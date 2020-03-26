#pragma once
#include"PIApplication.h"
#include<map>
#include<set>
#include"IServerInteractor.h"
#include "Record.h"
#include"TagInfo.h"
#include<piapi.h>
#include<piapix.h>

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
		void OpenConnection() override;
		void TestConnection() override;
		void GetTags(std::set<TagInfo>& tags, std::vector<std::string>& tagsPath) override;
		void GetRecords(std::map<std::string, std::vector<Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
			const std::set<std::string>& tagNames, const std::string& connectionID) override;
	private:
		std::shared_ptr<ConnectionAttributes> m_pServerAttributes;
		std::shared_ptr<DataTypeAttributes> m_pDataAttributes;
		std::weak_ptr<IServerInteractorOutput> m_pOutput;
		bool m_isGoodInclude;
		bool m_isAnnotatedInclude;
		bool m_isQuestionableInclude;
		bool m_isSubstitutedInclude;
		bool startApplication();
		void openConnection(const std::string& message);
		void getRawData(int32 pt, PIvaluetype type, PITIMESTAMP* startTime, PITIMESTAMP* endTime, std::vector<Record>& vecRecords);
		void getProcessedData(int32 pt, int32 code, int32 startTime, int32 endTime, double processedInterval, std::vector<Record>& vecRecords);
	};

	int32 PiTimeFromSysTime(const SYSTEMTIME& sysTime);
	int32 PiTimeFromPiTimeStamp(const PITIMESTAMP& sysTime);
	Record mapRecordFromDataValue(PIvaluetype type, double dValue, int32 iVal, char* strVal, uint32 strSize, const PITIMESTAMP& piTime,
		int32 iStat, int16 iFlag);
}

