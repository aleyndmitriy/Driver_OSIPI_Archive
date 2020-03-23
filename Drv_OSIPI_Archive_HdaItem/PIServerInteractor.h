#pragma once
#include"PIApplication.h"
#include<map>
#include<set>
#include"IServerInteractor.h"
#include "Record.h"
#include"TagInfo.h"

namespace DrvOSIPIArchValues
{
	class PIServerInteractor : public IServerInteractor, public std::enable_shared_from_this<PIServerInteractor>
	{
	public:
		PIServerInteractor();
		PIServerInteractor(const PIServerInteractor& src) = delete;
		PIServerInteractor& operator=(const PIServerInteractor& src) = delete;
		PIServerInteractor(PIServerInteractor&& src) = delete;
		PIServerInteractor& operator=(PIServerInteractor&& src) = delete;
		~PIServerInteractor();
		void SetAttributes(std::shared_ptr<ConnectionAttributes> attributes) override;
		void SetDataAttributes(std::shared_ptr<DataTypeAttributes> attributes) override;
		void SetOutput(std::shared_ptr<IServerInteractorOutput> output) override;
		void GetConnectedServers(void* output) override;
		void GetAllServers() override;
		void GetAggregates() override;
		void ChooseCurrentServer() override;
		void OpenConnectionWithUUID(const std::string& connectionID) override;
		void CloseConnectionWithUUID(const std::string& connectionID) override;
		void OpenConnection() override;
		void TestConnection() override;
		void GetTags(std::set<TagInfo>& tags, std::vector<std::string>& tagsPath, const std::string& connectionID) override;
		void GetRecords(std::map<std::string, std::vector<Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
			const std::map<std::string, std::vector<std::string> >& fullPaths, const std::string& connectionID) override;
	private:
		std::shared_ptr<ConnectionAttributes> m_pServerAttributes;
		std::shared_ptr<DataTypeAttributes> m_pDataAttributes;
		std::weak_ptr<IServerInteractorOutput> m_pOutput;
		bool startApplication();
	};
}
