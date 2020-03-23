#pragma once
#include"IServerInteractorOutput.h"
#include"ConnectionAttributes.h"
#include"TagInfo.h"
#include<memory>
#include<set>
#include<map>
#include<Windows.h>
#include"Record.h"

namespace DrvOSIPIArchValues
{
	class IServerInteractor
	{
	public:
		virtual void SetAttributes(std::shared_ptr<ConnectionAttributes> attributes) = 0;
		virtual void SetDataAttributes(std::shared_ptr<DataTypeAttributes> attributes) = 0;
		virtual void SetOutput(std::shared_ptr<IServerInteractorOutput> output) = 0;
		virtual void GetConnectedServers(void* output) = 0;
		virtual void GetAllServers() = 0;
		virtual void GetAggregates() = 0 ;
		virtual void ChooseCurrentServer() = 0;
		virtual void OpenConnectionWithUUID(const std::string& connectionID) = 0;
		virtual void CloseConnectionWithUUID(const std::string& connectionID) = 0;
		virtual void OpenConnection() = 0;
		virtual void TestConnection() = 0;
		virtual void GetTags(std::set<TagInfo>& tags, std::vector<std::string>& tagsPath, const std::string& connectionID) = 0;
		virtual void GetRecords(std::map<std::string, std::vector<Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
			const std::map<std::string, std::vector<std::string> >& fullPaths, const std::string& connectionID) = 0;
	};
}