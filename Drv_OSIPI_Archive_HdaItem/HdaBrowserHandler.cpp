#include"pch.h"
#include"HdaBrowserHandler.h"
#include"Constants.h"
#include"Log.h"
#include<OdsCoreLib/TimeUtils.h>
#include <OdsErr.h>
#include<algorithm>
#include"Utils.h"

DrvOSIPIArchValues::BrowserHandler::BrowserHandler(std::shared_ptr<IServerInteractor> interactor) : m_pAttributes(nullptr), m_pInteractor(interactor), m_ConnectionId()
{

}

DrvOSIPIArchValues::BrowserHandler::~BrowserHandler()
{
	if (!m_ConnectionId.empty()) {
		std::string connectionId(m_ConnectionId);
		m_pInteractor->CloseConnectionWithUUID(connectionId);
		Log::GetInstance()->WriteInfo(_T("Close connection with session id %s !"), (LPCTSTR)connectionId.c_str());
	}
}

int DrvOSIPIArchValues::BrowserHandler::Init(std::shared_ptr<ConnectionAttributes> attributes, std::shared_ptr<DataTypeAttributes> dataAttributes)
{
	m_pAttributes = attributes;
	m_pDataAttributes = dataAttributes;
	m_pInteractor->SetAttributes(attributes);
	m_pInteractor->SetDataAttributes(dataAttributes);
	return ODS::ERR::OK;
}

int DrvOSIPIArchValues::BrowserHandler::GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList)
{
	m_pInteractor->SetOutput(shared_from_this());
	pTagList->clear();
	if (m_ConnectionId.empty()) {
		m_pInteractor->OpenConnection();
		if (m_ConnectionId.empty()) {
			Log::GetInstance()->WriteInfo(_T("Can't open connection!"));
			return ODS::ERR::DB_CONNECTION_FAILED;
		}
		Log::GetInstance()->WriteInfo(_T("Open connection with session id %s !"), (LPCTSTR)m_ConnectionId.c_str());
	}
	std::set<TagInfo> tagsName;
	std::vector<std::string> vec;
	std::vector<std::string> splitVec;
	if (rEntry.size() == 1) {
		std::string name(rEntry.at(0).GetString());
		splitVec = split(name, std::string("/"));
		std::transform(splitVec.cbegin(), splitVec.cend(), std::back_inserter(vec), [](const std::string& path) {
			return path;
			});
	}
	else {
		std::transform(rEntry.cbegin(), rEntry.cend(), std::back_inserter(vec), [](const ODS::OdsString& path) {
			std::string name(path.GetString());
			return name;
			});
	}

	m_pInteractor->GetTags(tagsName, vec, m_ConnectionId);
	for (std::set<TagInfo>::const_iterator itr = tagsName.cbegin(); itr != tagsName.cend(); ++itr) {
		ODS::OdsString szAddress(itr->m_strName.c_str());
		STagItem sItem;
		if (rEntry.size() == 1) {
			std::transform(splitVec.cbegin(), splitVec.cend(), std::back_inserter(sItem.m_vAddress), [](const std::string& path) {
				return ODS::OdsString(path.c_str()); });
		}
		else {
			sItem.m_vAddress.assign(rEntry.cbegin(), rEntry.cend());
		}

		sItem.m_vAddress.push_back(szAddress);
		sItem.m_szDescription = ODS::OdsString(itr->m_strDescription.c_str());
		sItem.m_nType = itr->m_iType;
		pTagList->push_back(sItem);
	}
	return ODS::ERR::OK;
}


void DrvOSIPIArchValues::BrowserHandler::SendMessageError(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOSIPIArchValues::BrowserHandler::SendWarning(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOSIPIArchValues::BrowserHandler::SendMessageInfo(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOSIPIArchValues::BrowserHandler::GetServers(std::vector<std::string>&& servers)
{

}


void DrvOSIPIArchValues::BrowserHandler::GetAggregates(std::vector<std::pair<std::string, int> >&& aggregates)
{

}


void DrvOSIPIArchValues::BrowserHandler::SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName)
{

}

void DrvOSIPIArchValues::BrowserHandler::GetNewConnectionGuide(std::string&& uuid)
{
	m_ConnectionId = uuid;
}

void DrvOSIPIArchValues::BrowserHandler::CloseConnectionWithGuide(std::string&& uuid)
{
	m_ConnectionId.clear();
}

DrvOSIPIArchValues::STagItem DrvOSIPIArchValues::mapFromHierarchicalTagInfo(const HierarchicalTagInfo& tag)
{
	STagItem item;
	item.m_szDescription = ODS::OdsString(tag.m_strDescription.c_str());
	item.m_nType = tag.m_iType;
	std::transform(tag.m_strAddress.cbegin(), tag.m_strAddress.cend(), std::back_inserter(item.m_vAddress), [](const std::string& addr) {
		ODS::OdsString odsAddr(addr.c_str());
		return odsAddr; });
	return item;
}
