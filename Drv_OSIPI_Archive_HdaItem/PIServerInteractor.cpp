#include"pch.h"
#include"PIServerInteractor.h"
#include "Utils.h"
#include"Constants.h"
#include<piapi.h>

DrvOSIPIArchValues::PIServerInteractor::PIServerInteractor(): m_pServerAttributes(), m_pDataAttributes(), m_pOutput()
{

}

DrvOSIPIArchValues::PIServerInteractor::~PIServerInteractor()
{
	m_pServerAttributes.reset();
	m_pDataAttributes.reset();
	m_pOutput.reset();
}

void DrvOSIPIArchValues::PIServerInteractor::SetAttributes(std::shared_ptr<ConnectionAttributes> attributes)
{
	m_pServerAttributes = attributes;
}

void DrvOSIPIArchValues::PIServerInteractor::SetDataAttributes(std::shared_ptr<DataTypeAttributes> attributes)
{
	m_pDataAttributes = attributes;
}

void DrvOSIPIArchValues::PIServerInteractor::SetOutput(std::shared_ptr<IServerInteractorOutput> output)
{
	m_pOutput.reset();
	m_pOutput = output;
}

void DrvOSIPIArchValues::PIServerInteractor::GetConnectedServers(void* output)
{
	if (startApplication()) {
		std::shared_ptr<IServerInteractorOutput> out = m_pOutput.lock();
		HWND* ptrHandle = reinterpret_cast<HWND*>(output);
		char* serverName = new char[MAX_NODENAME_LEN];
		int32 len = MAX_NODENAME_LEN;
		char* addressName = new char[MAX_NODENAME_LEN];
		len = MAX_NODENAME_LEN;
		int32 nodeId = 0;
		int32 port = 0;
		int32 res = pilg_connectdlg(*ptrHandle);
		if (res == SUCCESS) {
			std::vector<std::pair<std::string,long> > vec;
			res = pilg_getconnectedserver(serverName, &len, &nodeId, &port, GETFIRST);
			if (res == SUCCESS) {
				vec.push_back(std::make_pair<std::string, long>(std::string(serverName),std::move(port)));
				while (res == SUCCESS) {
					res = pilg_getconnectedserver(serverName, &len, &nodeId, &port, GETNEXT);
					if (res == SUCCESS) {
						vec.push_back(std::make_pair<std::string, long>(std::string(serverName), std::move(port)));
					}
				}
				if (out) {
					out->GetServers(std::move(vec));
				}
			}
			else {
				if (out) {
					std::string message("There are no any connected servers!");
					out->GetServers(std::move(vec));
					out->SendMessageInfo(std::move(message));
				}
			}
		}
		else {
			if (out) {
				std::string message("System error!");
				out->SendMessageError(std::move(message));
			}
		}
		piut_netserverinfo(serverName, len, addressName, len, &port);
		//res = pilg_getdefserverinfo(serverName, &len, &nodeId,&port);
		res = pilg_login(NULL, "admin", "WIN-CT79E7UNU02", "Shal1212", &nodeId);
	}
	
}

void DrvOSIPIArchValues::PIServerInteractor::GetAllServers()
{
	if (startApplication()) {
		std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
		char info[STR_LENGTH];
		int32 res = piut_getprofile("PINODEIDENTIFIERS", NULL, OSI_PI_NO_REGISTERED_SERVERS, info, STR_LENGTH, OSI_PI_SDK_DAT_FILE_PATH);
		std::vector<std::string> vec;
		std::string serverName;
		for(int ind = 0; ind < res; ind++) {
			if (info[ind] != '\0') {
				serverName.push_back(info[ind]);
			}
			else {
				vec.push_back(serverName);
				serverName.clear();
			}
		}
		if (vec.empty() && serverName == std::string(OSI_PI_NO_REGISTERED_SERVERS)) {
			if (output) {
				output->SendMessageInfo(std::string(OSI_PI_NO_REGISTERED_SERVERS));
			}
		}
		std::vector<std::pair<std::string, long> > vecServers;
		for (std::vector<std::string>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr) {
			res = piut_getprofile("PINODEIDENTIFIERS", itr->c_str(), OSI_PI_NO_REGISTERED_SERVERS, info, STR_LENGTH, OSI_PI_SDK_DAT_FILE_PATH);
			std::string server(info);
			std::vector<std::string> serverDesc = split(server, std::string(","));
			if (serverDesc.size() == 3) {
				if (!serverDesc.back().empty() && !serverDesc.front().empty()) {
					vecServers.push_back(std::make_pair<std::string, long>(std::string(serverDesc.front()),std::stol(serverDesc.back())));
				}
			}
		}
		if (output) {
			output->GetServers(std::move(vecServers));
		}
	}
}


void DrvOSIPIArchValues::PIServerInteractor::GetAggregates()
{
	
}

void DrvOSIPIArchValues::PIServerInteractor::ChooseCurrentServer()
{

}


void DrvOSIPIArchValues::PIServerInteractor::OpenConnectionWithUUID(const std::string& connectionID)
{
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	if (startApplication()) {
		
	}
	else {
		if (output) {
			std::string message("Application has not been started!");
			output->SendMessageError(std::move(message));
			output->GetNewConnectionGuide(std::string());
		}
	}
}

void DrvOSIPIArchValues::PIServerInteractor::CloseConnectionWithUUID(const std::string& connectionID)
{

}


void DrvOSIPIArchValues::PIServerInteractor::OpenConnection()
{
	GUID guid;
	if (CoCreateGuid(&guid) != S_OK) {
		std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message("Can not create Guide!");
			output->SendMessageError(std::move(message));
			output->GetNewConnectionGuide(std::string());
		}
		return;
	}
	WCHAR strGuide[MAX_UUID_LENGTH];
	int res = StringFromGUID2(guid, strGuide, MAX_UUID_LENGTH);
	std::string key = std::string(Wstr2Str(std::wstring(strGuide)));
}

void DrvOSIPIArchValues::PIServerInteractor::TestConnection()
{

}


void DrvOSIPIArchValues::PIServerInteractor::GetTags(std::set<TagInfo>& tags, std::vector<std::string>& tagsPath, const std::string& connectionID)
{
	int32 isFound;
	int32 pt;
	int32 numFound;
	int32 isDesc = 0;
	int32 descLength = MAX_TAG_DESCRIPTION_LENGTH;
	char tagName[MAX_TAGNAME_LEN];
	char tagDesc[MAX_TAG_DESCRIPTION_LENGTH];
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	int32 res = pipt_wildcardsearch("*", 0, &isFound, tagName, MAX_TAGNAME_LEN, &pt, &numFound);
	if ((res == SUCCESS || res == -411) && isFound) {
		isDesc = pipt_descriptorx(pt, tagDesc, &descLength);
		if (isDesc == SUCCESS || res == -411) {
			tags.insert(TagInfo(std::string(tagName), std::string(tagDesc), pt));
		}
		while ((res == SUCCESS || res == -411) && isFound) {
			res = pipt_wildcardsearch("*", 1, &isFound, tagName, MAX_TAGNAME_LEN, &pt, &numFound);
			descLength = MAX_TAG_DESCRIPTION_LENGTH;
			isDesc = pipt_descriptorx(pt, tagDesc, &descLength);
			if (isDesc == SUCCESS || res == -411) {
				tags.insert(TagInfo(std::string(tagName), std::string(tagDesc), pt));
			}
		}
	}
	if (res > 0) {
		if (output) {
			std::string message("SystemError!");
			output->SendMessageError(std::move(message));
			output->GetNewConnectionGuide(std::string());
		}
	}
	
}

void DrvOSIPIArchValues::PIServerInteractor::GetRecords(std::map<std::string, std::vector<Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
	const std::map<std::string, std::vector<std::string> >& fullPaths, const std::string& connectionID)
{

}

bool DrvOSIPIArchValues::PIServerInteractor::startApplication()
{
	return PIApplication::Instance().StartApplication();
}