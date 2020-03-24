#include"pch.h"
#include"PIServerInteractor.h"
#include "Utils.h"
#include"Constants.h"
#include<piapi.h>
#include<piapix.h>

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


void DrvOSIPIArchValues::PIServerInteractor::OpenConnection()
{
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	if (startApplication()) {
		char* serverName = new char[MAX_NODENAME_LEN];
		int32 len = MAX_NODENAME_LEN;
		int32 nodeId = 0;
		int32 port = 0;
		int32 res = pilg_getconnectedserver(serverName, &len, &nodeId, &port, GETFIRST);
		if (res < -1 || res > 1) {
			if (output) {
				std::string message("System error!");
				output->SendMessageError(std::move(message));
				return;
			}
		}
		if (res == SUCCESS) {
			if (std::string(serverName) == m_pServerAttributes->configuration.serverName) {
				if (output) {
					output->ConnectionOpened(true);
				}
				return;
			}
			while (res == SUCCESS) {
				res = pilg_getconnectedserver(serverName, &len, &nodeId, &port, GETNEXT);
				if (res == SUCCESS) {
					if (std::string(serverName) == m_pServerAttributes->configuration.serverName) {
						if (output) {
							output->ConnectionOpened(true);
						}
						return;
					}
				}
			}
		}
		else {
			std::string message = std::string("Login Succeed!");
			openConnection(message);
		}
	}
	else {
		if (output) {
			std::string message("Application is not registered!");
			output->SendMessageInfo(std::move(message));
		}
	}
}

void DrvOSIPIArchValues::PIServerInteractor::TestConnection()
{
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	if (startApplication()) {
		std::string message = std::string("Connection Test Succeed!");
		openConnection(message);
	}
	else {
		if (output) {
			std::string message("Application is not registered!");
			output->SendMessageInfo(std::move(message));
		}
	}
}

void DrvOSIPIArchValues::PIServerInteractor::openConnection(const std::string& message)
{
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	if (m_pServerAttributes->configuration.serverName.empty()) {
		if (output) {
			std::string message("Select server name!");
			output->SendMessageInfo(std::move(message));
			output->ConnectionOpened(false);
		}
		return;
	}
	LPCSTR userName = NULL;
	LPCSTR password = NULL;
	if (!m_pServerAttributes->userAccess.m_login.empty()) {
		userName = m_pServerAttributes->userAccess.m_login.c_str();
	}
	if (!m_pServerAttributes->userAccess.m_password.empty()) {
		password = m_pServerAttributes->userAccess.m_password.c_str();
	}
	int32 isValid = 0;
	int32 res = pilg_login(NULL, userName, m_pServerAttributes->configuration.serverName.c_str(), password, &isValid);
	if (res == SUCCESS) {
		if (output) {
			std::string messages = message;
			output->SendWarning(std::move(messages));
			output->ConnectionOpened(true);
		}
		return;
	}
	else {
		if (output) {
			output->SendMessageInfo(std::string("Login failed!"));
			output->ConnectionOpened(false);
		}
	}
}

void DrvOSIPIArchValues::PIServerInteractor::GetTags(std::set<TagInfo>& tags, std::vector<std::string>& tagsPath)
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
		}
	}
	
}

void DrvOSIPIArchValues::PIServerInteractor::GetRecords(std::map<std::string, std::vector<Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
	const std::set<std::string>& tagNames, const std::string& connectionID)
{
	int32 startPiTime = PiTimeFromSysTime(startTime);
	int32 endPiTime = PiTimeFromSysTime(endTime);
	tagsData.clear();
	int32 pt = 0;
	int32 res;
	int32 valCount = 0;
	PIvaluetype type;
	char tagName[MAX_TAGNAME_LEN];
	std::vector<std::pair<int32, short> > vec;
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	for (std::set<std::string>::const_iterator itr = tagNames.cbegin(); itr != tagNames.cend(); ++itr) {
		res = pipt_findpoint(const_cast<char*>(itr->c_str()), &pt);
		if (res == SUCCESS) {
			res = pipt_pointtypex(pt, &type);
			if (res == SUCCESS) {
				/*valCount = 8000;
				int32 times[8000];
				times[0] = startPiTime;
				times[7999] = endPiTime;
				float rvals[8000];
				int32 istats[8000];
				res = piar_interpvalues(pt, &valCount, times, rvals, istats);
				if (res == SUCCESS) {
					for (int index = 0; index < 4000; ++index) {
						res = istats[index];
					}
				}
				res = piar_compvalues(pt, &valCount, times, rvals, istats,0);
				if (res == SUCCESS) {
					for (int index = 0; index < 4000; ++index) {
						res = istats[index];
					}
				}*/
			}
		}
	}
}

bool DrvOSIPIArchValues::PIServerInteractor::startApplication()
{
	return PIApplication::Instance().StartApplication();
}

int32 DrvOSIPIArchValues::PiTimeFromSysTime(const SYSTEMTIME& sysTime)
{
	int32 piTime;
	int32 arrayTime[6];
	arrayTime[0] = sysTime.wMonth;
	arrayTime[1] = sysTime.wDay;
	arrayTime[2] = sysTime.wYear;
	arrayTime[3] = sysTime.wHour;
	arrayTime[4] = sysTime.wMinute;
	arrayTime[5] = sysTime.wSecond;
	pitm_intsec(&piTime, arrayTime);
	return piTime;
}