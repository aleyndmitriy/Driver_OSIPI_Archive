#include"pch.h"
#include"HdaCommandHandler.h"
#include <HdaFunctionParam.h>
#include <HdaCommandParam.h>
#include<HdaFunction.h>
#include <HdaFunctionResult.h>
#include<HdaFunctionTypes.h>
#include"Constants.h"
#include"Log.h"
#include"ParamUtils.h"
#include<OdsCoreLib/TimeUtils.h>
#include <OdsErr.h>
#include"Utils.h"
#include<numeric>
#include<functional>
#include<chrono>
#include<algorithm>
#include<piapix.h>

DrvOSIPIArchValues::HdaCommandHandler::HdaCommandHandler(std::shared_ptr<IServerInteractor> interactor) : m_pAttributes(nullptr), m_pDataAttributes(nullptr), m_pInteractor(interactor)
{

}

DrvOSIPIArchValues::HdaCommandHandler::~HdaCommandHandler()
{

}

int DrvOSIPIArchValues::HdaCommandHandler::Init(std::shared_ptr<ConnectionAttributes> attributes, std::shared_ptr<DataTypeAttributes> dataAttributes)
{
	m_pAttributes = attributes;
	m_pDataAttributes = dataAttributes;
	m_pInteractor->SetAttributes(attributes);
	m_pInteractor->SetDataAttributes(dataAttributes);
	return ODS::ERR::OK;
}

int DrvOSIPIArchValues::HdaCommandHandler::Shut()
{
	m_pInteractor.reset();
	return ODS::ERR::OK;
}

int DrvOSIPIArchValues::HdaCommandHandler::HandleCommand(ODS::HdaCommand* pCommand, ODS::HdaCommandResult* pResult)
{
	m_pInteractor->SetOutput(shared_from_this());
	std::vector<ODS::HdaFunctionResult*> resultList;
	ODS::HdaFunction** pList = nullptr;
	int nCount = 0;
	int iRes = pCommand->GetFunctionList(&pList, &nCount);
	iRes = ExecuteCommand(pCommand, *pList, nCount, &resultList);
	if (iRes == ODS::ERR::OK) {
		for (std::vector<ODS::HdaFunctionResult*>::const_iterator iterRes = resultList.cbegin(); iterRes != resultList.cend(); iterRes++)
		{
			pResult->AddFunctionResult(*iterRes);
		}
	}
	pCommand->DestroyFunctionList(pList, nCount);
	return iRes;
}


int DrvOSIPIArchValues::HdaCommandHandler::AnalyzeCommand(ODS::HdaCommand* pCommand, ODS::HdaFunction* list, int listSize, std::map<int, std::vector<ODS::HdaFunction*> >& requestMap)
{
	requestMap.clear();
	std::vector<ODS::HdaFunction*> funcList;
	for (int i = 0; i < listSize; i++) {
		funcList.push_back(list + i);
	}
	if (funcList.size() <= 0) {
		return ODS::ERR::NOT_SUPPORTED;
	}
	if (ODS::HdaFunctionType::OPEN_SESSION == funcList[0]->GetType() || ODS::HdaFunctionType::CLOSE_SESSION == funcList[0]->GetType()) {
		int nFuncType = funcList[0]->GetType();
		std::pair<int, std::vector<ODS::HdaFunction*> > pair = std::make_pair<int, std::vector<ODS::HdaFunction*> >(std::move(nFuncType), std::vector<ODS::HdaFunction*>());
		std::pair<std::map<int, std::vector<ODS::HdaFunction*> >::iterator, bool > insertedPair = requestMap.insert(pair);
		insertedPair.first->second.push_back(funcList[0]);
		return ODS::ERR::OK;
	}

	for (std::vector<ODS::HdaFunction*>::const_iterator itr = funcList.cbegin(); itr != funcList.cend(); ++itr) {
		int nFuncType = (*itr)->GetType();
		std::pair<int, std::vector<ODS::HdaFunction*> > pair = std::make_pair<int, std::vector<ODS::HdaFunction*> >(std::move(nFuncType), std::vector<ODS::HdaFunction*>());
		std::pair<std::map<int, std::vector<ODS::HdaFunction*> >::iterator, bool > insertedPair = requestMap.insert(pair);
		insertedPair.first->second.push_back(*itr);
	}
	return ODS::ERR::OK;
}

int DrvOSIPIArchValues::HdaCommandHandler::HandleOpenSession(ODS::HdaFunction* pFunc, std::vector<ODS::HdaFunctionResult*>* pResultList)
{
	ODS::HdaFunctionResultSession* pSession = new ODS::HdaFunctionResultSession;
	pSession->SetContext(pFunc->GetContext());
	ODS::Core::Uuid sessionId;
	std::string uuid = std::string(sessionId.ToString().GetString());
	m_pInteractor->OpenConnection();
	pSession->SetSessionId(sessionId);
	pSession->SetRc(ODS::ERR::OK);
	Log::GetInstance()->WriteInfo(_T("OpenSession ok,  session id %s"), (LPCTSTR)sessionId.ToString());
	pResultList->push_back(pSession);
	Log::GetInstance()->WriteInfo(_T("Finish server executing commands."));
	return ODS::ERR::OK;
}

int DrvOSIPIArchValues::HdaCommandHandler::HandleCloseSession(ODS::HdaFunction* pFunc, std::vector<ODS::HdaFunctionResult*>* pResultList)
{
	ODS::HdaFunctionParam** pParam = nullptr;
	int nCount = 0;
	int res = pFunc->GetParameterList(&pParam, &nCount);
	ODS::Core::Uuid sessionId;
	if (pParam != nullptr && nCount > 0) {
		for (int ind = 0; ind < nCount; ind++) {
			if ((*pParam + ind)->GetType() == ODS::HdaFunctionParam::TYPE_SESSION) {
				ODS::HdaFunctionParamSession* ptrParamSession = dynamic_cast<ODS::HdaFunctionParamSession*>(*pParam + ind);
				if (ptrParamSession != nullptr) {
					sessionId = ptrParamSession->GetSessionId();
				}
				break;
			}
		}
	}
	else {
		Log::GetInstance()->WriteInfo(_T("Finish server executing commands."));
		return ODS::ERR::BAD_PARAM;
	}
	pFunc->DestroyParameterList(pParam, nCount);
	if (sessionId.IsEmpty()) {
		Log::GetInstance()->WriteInfo(_T("Empty session id %s has been received!"), (LPCTSTR)sessionId.ToString());
		Log::GetInstance()->WriteInfo(_T("Finish server executing commands."));
		return ODS::ERR::BAD_PARAM;
	}
	Log::GetInstance()->WriteInfo(_T("Close session ok,  session id %s"), (LPCTSTR)sessionId.ToString());
	ODS::HdaFunctionResultSession* pSession = new ODS::HdaFunctionResultSession;
	pSession->SetContext(pFunc->GetContext());
	pSession->SetRc(ODS::ERR::OK);
	pResultList->push_back(pSession);
	Log::GetInstance()->WriteInfo(_T("Finish server executing commands."));
	return ODS::ERR::OK;
}

int DrvOSIPIArchValues::HdaCommandHandler::ExecuteCommand(ODS::HdaCommand* pCommand, ODS::HdaFunction* funcList, int listSize, std::vector<ODS::HdaFunctionResult*>* pResultList)
{
	std::map<int, std::vector<ODS::HdaFunction*> > requestMap;
	Log::GetInstance()->WriteInfo(_T("Start server executing commands..."));
	int res = AnalyzeCommand(pCommand, funcList, listSize, requestMap);
	if (res == ODS::ERR::OK) {
		std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator itr = requestMap.find(ODS::HdaFunctionType::OPEN_SESSION);
		if (itr != requestMap.cend() && itr->second.size() == 1) {
			return HandleOpenSession(itr->second[0], pResultList);
		}
		itr = requestMap.find(ODS::HdaFunctionType::CLOSE_SESSION);
		if (itr != requestMap.cend() && itr->second.size() == 1) {
			return HandleCloseSession(itr->second[0], pResultList);
		}


		ODS::HdaCommandParam** ppCmdParamList = NULL;
		int nCount = 0;
		Log::GetInstance()->WriteInfo(_T("Start reading parameters list..."));
		std::chrono::time_point<std::chrono::steady_clock> startReceivingTagInfo = std::chrono::high_resolution_clock::now();
		int iRes = pCommand->GetParamList(&ppCmdParamList, &nCount);
		ODS::Core::Uuid sessionId = ODS::Core::Uuid::EmptyUuid();
		SYSTEMTIME currTime;
		SYSTEMTIME start;
		SYSTEMTIME end;
		if (iRes == ODS::ERR::OK)
		{
			for (int i = 0; i < nCount; i++)
			{
				if (ppCmdParamList[i]->GetType() == ODS::HdaCommandParam::TYPE_TIME_PERIOD)
				{
					ODS::HdaCommandParamTimePeriod* pTimePeriod = (ODS::HdaCommandParamTimePeriod*)ppCmdParamList[i];

					if (ODS::ERR::OK != pTimePeriod->GetTimePeriod(&start, &end, &currTime))
					{
						pCommand->DestroyParamList(ppCmdParamList, nCount);
						return ODS::ERR::BAD_PARAM;
					}
				}
				if (ppCmdParamList[i]->GetType() == ODS::HdaCommandParam::TYPE_SESSION)
				{
					ODS::HdaCommandParamSession* pSession = (ODS::HdaCommandParamSession*)ppCmdParamList[i];
					sessionId = pSession->GetSessionId();
				}
			}
			pCommand->DestroyParamList(ppCmdParamList, nCount);
		}
		SYSTEMTIME startUtc, endUtc;
		ODS::TimeUtils::SysTimeLocalToUtc(start, &startUtc);
		ODS::TimeUtils::SysTimeLocalToUtc(end, &endUtc);
		std::map<int, std::vector<ParamValueList> > paramList;
		std::string sessionID;
		if (sessionId.IsEmpty()) {
			Log::GetInstance()->WriteInfo(_T("Empty session id %s has been received!"), (LPCTSTR)sessionId.ToString());
			Log::GetInstance()->WriteInfo(_T("Finish server executing commands."));
			return ODS::ERR::DB_CONNECTION_FAILED;
		}
		else {
			sessionID = std::string(sessionId.ToString().GetString());
		}
		std::set<std::string> tags;
		CreateQueriesList(requestMap, paramList, tags);
		std::string tagNames;
		for (std::set<std::string>::const_iterator tagsNameItr = tags.cbegin(); tagsNameItr != tags.cend(); tagsNameItr++) {
			tagNames = tagNames + *tagsNameItr + std::string(", ");
		}
		ODS::OdsString strStartTime = ODS::TimeUtils::CreateIsoTimeStringFromSysTime(start, true);
		ODS::OdsString strStartTimeUts = ODS::TimeUtils::CreateIsoTimeStringFromSysTime(startUtc, true);
		ODS::OdsString strEndTime = ODS::TimeUtils::CreateIsoTimeStringFromSysTime(end, true);
		ODS::OdsString strEndTimeUts = ODS::TimeUtils::CreateIsoTimeStringFromSysTime(endUtc, true);
		Log::GetInstance()->WriteInfo(_T("Query: sessionId %s;  startTime %s; startTimeUts %s; endTime %s; endTimeUts %s; tags: %s"),
			(LPCTSTR)sessionID.c_str(), strStartTime.GetString(), strStartTimeUts.GetString(), strEndTime.GetString(), strEndTimeUts.GetString(),
			(LPCTSTR)tagNames.c_str());
		std::chrono::time_point<std::chrono::steady_clock> endReceivingTagInfo = std::chrono::high_resolution_clock::now();
		std::chrono::microseconds durationLoadingTagsParam = std::chrono::duration_cast<std::chrono::microseconds>(endReceivingTagInfo - startReceivingTagInfo);
		Log::GetInstance()->WriteInfo(_T("Finish reading parameters list in %d mcsec"), durationLoadingTagsParam.count());
		if (paramList.empty()) {
			Log::GetInstance()->WriteInfo(_T("Finish server executing commands. Empty parameters list."));
			return ODS::ERR::DB_NO_DATA;
		}
		startReceivingTagInfo = std::chrono::high_resolution_clock::now();
		Log::GetInstance()->WriteInfo(_T("Execute query..."));
		ExecuteQueriesList(requestMap, paramList, tags, pResultList, startUtc, endUtc, sessionID);
		endReceivingTagInfo = std::chrono::high_resolution_clock::now();
		durationLoadingTagsParam = std::chrono::duration_cast<std::chrono::microseconds>(endReceivingTagInfo - startReceivingTagInfo);
		Log::GetInstance()->WriteInfo(_T("Query has been executed in %d mcsec"), durationLoadingTagsParam.count());
		Log::GetInstance()->WriteInfo(_T("Finish server executing commands."));
		return ODS::ERR::OK;
	}
	else {
		return res;
	}
}

void DrvOSIPIArchValues::HdaCommandHandler::CreateQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions,
	std::map<int, std::vector<ParamValueList> >& paramList, std::set<std::string>& tagsForQuery)
{
	paramList.clear();
	tagsForQuery.clear();
	std::pair<int, std::vector<ParamValueList> > pair;
	std::pair<std::map<int, std::vector<ParamValueList> >::iterator, bool > insertedPair;
	for (std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator itr = requestFunctions.cbegin(); itr != requestFunctions.cend(); ++itr) {
		int type = itr->first;
		pair = std::make_pair<int, std::vector<ParamValueList> >(std::move(type), BuildCmdValueList(itr->second));
		for (std::vector<ParamValueList>::const_iterator paramItr = pair.second.cbegin(); paramItr != pair.second.cend(); ++paramItr) {
			tagsForQuery.merge(paramItr->GetTagsNames());
		}
		insertedPair = paramList.insert(pair);
	}
}

void DrvOSIPIArchValues::HdaCommandHandler::ExecuteQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, const std::map<int, std::vector<ParamValueList> >& queriesList,
	const std::set<std::string>& tagsForQuery, std::vector<ODS::HdaFunctionResult*>* pResultList, const SYSTEMTIME& startTime,
	const SYSTEMTIME& endTime, const std::string& sessionId)
{
	std::map<std::string, std::vector<Record> > tagsData;
	std::chrono::time_point<std::chrono::steady_clock> startReceivingRecords = std::chrono::high_resolution_clock::now();
	Log::GetInstance()->WriteInfo(_T("Start receiving records..."));
	m_pInteractor->GetRecords(tagsData, startTime, endTime, tagsForQuery, sessionId);
	for (std::map<std::string, std::vector<Record> >::const_iterator itrInfo = tagsData.cbegin(); itrInfo != tagsData.cend(); itrInfo++) {
		Log::GetInstance()->WriteInfo(_T("Tag %s has %d values"), (LPCTSTR)(itrInfo->first.c_str()), itrInfo->second.size());
	}
	std::chrono::time_point<std::chrono::steady_clock> endReceivingRecords = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds durationLoadingRecords = std::chrono::duration_cast<std::chrono::microseconds>(endReceivingRecords - startReceivingRecords);
	Log::GetInstance()->WriteInfo(_T("Records have been received in %d mcsec"), durationLoadingRecords.count());
	if (tagsData.empty()) {
		return;
	}
	startReceivingRecords = std::chrono::high_resolution_clock::now();
	Log::GetInstance()->WriteInfo(_T("Start processing records..."));
	for (std::map<int, std::vector<ParamValueList> >::const_iterator queriesIterator = queriesList.cbegin(); queriesIterator != queriesList.cend(); ++queriesIterator) {
		size_t length = queriesIterator->second.size();
		std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator funcIterator = requestFunctions.find(queriesIterator->first);
		if (funcIterator != requestFunctions.cend()) {
			for (size_t index = 0; index < length; ++index) {
				std::map<std::string, std::vector<Record> >::const_iterator tagsIterator = tagsData.find(queriesIterator->second.at(index).GetFullAddress());
				if (tagsIterator != tagsData.cend()) {
					if (tagsIterator->second.empty()) {
						return;
					}
					switch (queriesIterator->first) {
					case ODS::HdaFunctionType::VALUE_LIST_CONDITION:
					{
						ODS::HdaFunctionResultVLC* pFuncResult = new ODS::HdaFunctionResultVLC;
						std::vector<bool> conditions;
						std::vector<ODS::TvqListElementDescription> listDesc;
						for (std::vector<Record>::const_iterator itr = tagsIterator->second.cbegin(); itr != tagsIterator->second.cend(); ++itr) {
							bool condition = false;
							if (AdjustConditions(queriesIterator->second.at(index).GetConditions(), tagsData, *itr)) {
								condition = true;
							}
							ODS::Tvq* tvq = CreateTvqFromRecord(*itr);
							SYSTEMTIME tm = tvq->GetTimestampLoc();
							if (tm.wYear != 0) {
								if (itr == tagsIterator->second.cbegin()) {

									if (ODS::TimeUtils::SysTimeCompare(tvq->GetTimestampLoc(), startTime) <= 0) {
										ODS::TvqListElementDescription desc;
										desc.m_nIndex = 0;
										desc.m_ulFlags = ODS::TvqListElementDescription::PREV_POINT;
										listDesc.push_back(desc);
									}
								}
								if (itr == tagsIterator->second.cend() - 1) {
									if (ODS::TimeUtils::SysTimeCompare(tvq->GetTimestampLoc(), startTime) >= 0) {
										ODS::TvqListElementDescription desc;
										desc.m_nIndex = tagsIterator->second.size() - 1;
										desc.m_ulFlags = ODS::TvqListElementDescription::POST_POINT;
										listDesc.push_back(desc);
									}
								}
							}
							pFuncResult->AddTvq(tvq);
							conditions.push_back(condition);
						}
						bool* conditionsList = new bool[conditions.size()];
						for (size_t conditionItr = 0; conditionItr < conditions.size(); ++conditionItr) {
							*(conditionsList + conditionItr) = conditions.at(conditionItr);
						}
						pFuncResult->SetConditionValueList(conditionsList, conditions.size());

						if (!listDesc.empty()) {
							ODS::TvqListElementDescription* desc = new ODS::TvqListElementDescription[listDesc.size()];
							for (size_t descItr = 0; descItr < listDesc.size(); descItr++) {
								(desc + descItr)->m_nIndex = listDesc.at(descItr).m_nIndex;
								(desc + descItr)->m_ulFlags = listDesc.at(descItr).m_ulFlags;
							}
							pFuncResult->SetTvqDescList(desc, listDesc.size());
						}
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::LAST_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_LAST_VALUE:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						std::vector<Record>::const_iterator maxItr =
							std::max_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsDataTimeLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*maxItr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::FIRST_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_FIRST_VALUE:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						std::vector<Record>::const_iterator minItr =
							std::min_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsDataTimeLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*minItr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::AVG_VALUE:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						Record record = std::accumulate(tagsIterator->second.cbegin(), tagsIterator->second.cend(), Record(), RecordsSum);
						Record avgRecord = RecordAvg(record, tagsIterator->second.size());
						ODS::Tvq* tvq = CreateTvqFromRecord(avgRecord);
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::SUM_VALUE:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						Record record = std::accumulate(tagsIterator->second.cbegin(), tagsIterator->second.cend(), Record(), RecordsSum);
						ODS::Tvq* tvq = CreateTvqFromRecord(record);
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::MIN_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_MINIMUM_VALUE:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						std::vector<Record>::const_iterator minItr =
							std::min_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsValueLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*minItr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::MAX_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_MAXIMUM_VALUE:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						std::vector<Record>::const_iterator maxItr =
							std::max_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsValueLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*maxItr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
					break;
					case ODS::HdaFunctionType::VALUE_LIST:
					{
						ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
						pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
						std::vector<ODS::TvqListElementDescription> listDesc;
						for (std::vector<Record>::const_iterator itr = tagsIterator->second.cbegin(); itr != tagsIterator->second.cend(); ++itr) {
							if (!AdjustConditions(queriesIterator->second.at(index).GetConditions(), tagsData, *itr)) {
								continue;
							}
							ODS::Tvq* tvq = CreateTvqFromRecord(*itr);
							SYSTEMTIME tm = tvq->GetTimestampLoc();
							if (tm.wYear != 0) {
								if (itr == tagsIterator->second.cbegin()) {

									if (ODS::TimeUtils::SysTimeCompare(tvq->GetTimestampLoc(), startTime) < 0) {
										ODS::TvqListElementDescription desc;
										desc.m_nIndex = 0;
										desc.m_ulFlags = ODS::TvqListElementDescription::PREV_POINT;
										listDesc.push_back(desc);
									}
								}
								if (itr == tagsIterator->second.cend() - 1) {
									if (ODS::TimeUtils::SysTimeCompare(tvq->GetTimestampLoc(), startTime) > 0) {
										ODS::TvqListElementDescription desc;
										desc.m_nIndex = tagsIterator->second.size() - 1;
										desc.m_ulFlags = ODS::TvqListElementDescription::POST_POINT;
										listDesc.push_back(desc);
									}
								}
							}
							pFuncResult->AddTvq(tvq);
						}
						if (!listDesc.empty()) {
							ODS::TvqListElementDescription* desc = new ODS::TvqListElementDescription[listDesc.size()];
							for (size_t descItr = 0; descItr < listDesc.size(); descItr++) {
								(desc + descItr)->m_nIndex = listDesc.at(descItr).m_nIndex;
								(desc + descItr)->m_ulFlags = listDesc.at(descItr).m_ulFlags;
							}
							pFuncResult->SetTvqDescList(desc, listDesc.size());
						}
						pResultList->push_back(pFuncResult);
					}
					break;
					default:
						break;
					}
				}
			}
		}
	}
	endReceivingRecords = std::chrono::high_resolution_clock::now();
	durationLoadingRecords = std::chrono::duration_cast<std::chrono::microseconds>(endReceivingRecords - startReceivingRecords);
	Log::GetInstance()->WriteInfo(_T("Records have been processed in %d mcsec"), durationLoadingRecords.count());
}

std::vector<DrvOSIPIArchValues::ParamValueList> DrvOSIPIArchValues::HdaCommandHandler::BuildCmdValueList(const std::vector<ODS::HdaFunction*>& rFuncList)
{
	std::vector<ParamValueList> vec;
	for (std::vector<ODS::HdaFunction*>::const_iterator itr = rFuncList.cbegin(); itr != rFuncList.cend(); ++itr) {
		vec.push_back(GetParameterValueList(*itr));
	}
	return vec;
}

bool DrvOSIPIArchValues::HdaCommandHandler::AdjustConditions(const std::vector<TagCondition>& conditions,
	const std::map<std::string, std::vector<Record> >& tagsData, const Record& record)
{
	if (conditions.empty()) {
		return true;
	}
	//bool isConditions = false;
	for (std::vector<TagCondition>::const_iterator conditionsIter = conditions.cbegin(); conditionsIter != conditions.cend(); ++conditionsIter) {
		std::map<std::string, std::vector<Record> >::const_iterator findConditionRecord = tagsData.find(conditionsIter->tagName);
		if (findConditionRecord != tagsData.cend()) {
			std::vector<Record>::const_iterator findEqualTime = std::find_if(findConditionRecord->second.cbegin(),
				findConditionRecord->second.cend(), std::bind(CompareRecordsDataTime, std::placeholders::_1, record));
			if (findEqualTime != findConditionRecord->second.cend()) {
				return true;
			}

		}
	}
	return false;
}

DrvOSIPIArchValues::ParamValueList DrvOSIPIArchValues::HdaCommandHandler::GetParameterValueList(const ODS::HdaFunction* pHdaFunc)
{
	std::vector<ODS::HdaFunctionParam*> paramList;
	ODS::HdaFunctionParam** pParam = nullptr;
	int nCount = 0;
	int res = pHdaFunc->GetParameterList(&pParam, &nCount);
	for (int i = 0; i < nCount; i++) {
		paramList.push_back(pParam[i]);
	}
	ODS::OdsString address;
	ODS::OdsString fullAddress;
	ODS::OdsString sql;
	bool prevPoint = false;
	bool postPoint = false;
	ODS::HdaFunctionParamLimit::LimitParam limit;
	limit.m_nLimitCount = 0;
	limit.m_nLimitOffset = 0;
	limit.m_nLimitSide = 0;
	int nSpecPoint = 0;
	int valueType = 0;
	for (std::vector<ODS::HdaFunctionParam*>::const_iterator itr = paramList.cbegin(); itr != paramList.cend(); ++itr) {
		int nParamType = (*itr)->GetType();

		switch (nParamType)
		{
		case ODS::HdaFunctionParam::TYPE_ITEM_ADDRESS:
			ParamUtils::GetAddress(address, fullAddress, *itr);
			break;
		case ODS::HdaFunctionParam::TYPE_SQL:
			sql = ParamUtils::GetSql(*itr);
			break;
		case ODS::HdaFunctionParam::TYPE_LIMIT:
			((ODS::HdaFunctionParamLimit*) * itr)->GetLimit(&limit);
			break;
		case ODS::HdaFunctionParam::TYPE_OBJECT:
			valueType = ((ODS::HdaFunctionParamObject*) * itr)->GetType();
			break;
		case ODS::HdaFunctionParam::TYPE_SPEC_POINT:
			nSpecPoint = ((ODS::HdaFunctionParamSpecPoint*) * itr)->GetSpecPointFlag();
			if (ODS::HdaFunctionParamSpecPoint::POINT_TYPE_PREV == nSpecPoint)
				prevPoint = true;
			else if (ODS::HdaFunctionParamSpecPoint::POINT_TYPE_POST == nSpecPoint)
				postPoint = true;
			else if (ODS::HdaFunctionParamSpecPoint::POINT_TYPE_BOTH == nSpecPoint)
			{
				prevPoint = true;
				postPoint = true;
			}
			break;
		default:
			break;
		}
	}
	pHdaFunc->DestroyParameterList(pParam, nCount);
	ParamValueList valList(std::string(address.GetString()), std::string(fullAddress.GetString()), std::string(sql.GetString()), prevPoint, postPoint, valueType, Limit(limit.m_nLimitSide, limit.m_nLimitOffset, limit.m_nLimitCount));
	return valList;
}

ODS::Tvq* DrvOSIPIArchValues::HdaCommandHandler::CreateTvqFromRecord(const Record& record) const
{
	VARIANT vValue;
	std::string str;
	const SYSTEMTIME* timeStampStruct = nullptr;
	SYSTEMTIME dataTime = { 0 };
	SYSTEMTIME localDataTime = { 0 };
	SYSTEMTIME valDataTime = { 0 };
	SYSTEMTIME localValDataTime = { 0 };
	float val = 0.0;
	bool bitVal = false;
	ODS::Tvq* tvq = new ODS::Tvq();
	for (Record::const_iterator itr = record.cbegin(); itr != record.cend(); ++itr) {
		switch (itr->second.first)
		{
		case PI_Type_null:
			break;
		case PI_Type_bool:
			::VariantInit(&vValue);
			vValue.vt = VT_BOOL;
			if (std::stoi(itr->second.second) > 0) {
				bitVal = true;
			}
			else {
				bitVal = false;
			}
			vValue.boolVal = bitVal;
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case PI_Type_int8:
		case PI_Type_int16:
		case PI_Type_int32:
			::VariantInit(&vValue);
			vValue.vt = VT_INT;
			vValue.intVal = std::stoi(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			Log::GetInstance()->WriteInfoDebug(_T("Int32 result  %d !"), vValue.intVal);
			break;
		case PI_Type_int64:
		case PI_Type_digital:
			::VariantInit(&vValue);
			vValue.vt = VT_I8;
			vValue.llVal = std::stoll(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case PI_Type_uint8:
		case PI_Type_uint16:
		case PI_Type_uint32:
			::VariantInit(&vValue);
			vValue.vt = VT_UINT;
			vValue.ulVal = std::stoul(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case PI_Type_uint64:
			::VariantInit(&vValue);
			vValue.vt = VT_UI8;
			vValue.ullVal = std::stoull(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case PI_Type_float64:
			::VariantInit(&vValue);
			vValue.vt = VT_R8;
			vValue.dblVal = std::stod(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case PI_Type_float32:
		case PI_Type_float16:
			::VariantInit(&vValue);
			vValue.vt = VT_R8;
			val = std::stof(itr->second.second);
			vValue.dblVal = val;
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case PI_Type_PItimestamp:
			if (itr->first == std::string(OSI_PI_SERVER_TIMESTAMP)) {
				timeStampStruct = reinterpret_cast<const SYSTEMTIME*>(itr->second.second.c_str());
				dataTime.wYear = timeStampStruct->wYear;
				dataTime.wMonth = timeStampStruct->wMonth;
				dataTime.wDay = timeStampStruct->wDay;
				dataTime.wHour = timeStampStruct->wHour;
				dataTime.wMinute = timeStampStruct->wMinute;
				dataTime.wSecond = timeStampStruct->wSecond;
				dataTime.wMilliseconds = timeStampStruct->wMilliseconds;
			}
			else {
				timeStampStruct = reinterpret_cast<const SYSTEMTIME*>(itr->second.second.c_str());
				valDataTime.wYear = timeStampStruct->wYear;
				valDataTime.wMonth = timeStampStruct->wMonth;
				valDataTime.wDay = timeStampStruct->wDay;
				valDataTime.wHour = timeStampStruct->wHour;
				valDataTime.wMinute = timeStampStruct->wMinute;
				valDataTime.wSecond = timeStampStruct->wSecond;
				valDataTime.wMilliseconds = timeStampStruct->wMilliseconds;
				ODS::TimeUtils::SysTimeUtcToLocal(valDataTime, &localValDataTime);
				if (localValDataTime.wYear != 0) {
					tvq->SetValue(ODS::Data::Value(localValDataTime));
				}
			}
			break;
		default:
			tvq->SetValue(ODS::Data::Value(itr->second.second.c_str()));
			break;
		}
	}
	ODS::TimeUtils::SysTimeUtcToLocal(dataTime, &localDataTime);
	if (localDataTime.wYear != 0) {
		tvq->SetTimestamp(&localDataTime);
	}
	if (record.GetStatus() == PI_M_QFLAG) {
		tvq->SetQuality(ODS::Tvq::QUALITY_UNCERTAIN);
	}
	else if (record.GetStatus() == PI_M_SFLAG) {
		tvq->SetQuality(ODS::Tvq::QUALITY_BAD);
	}
	return tvq;
}

void DrvOSIPIArchValues::HdaCommandHandler::SendMessageError(std::string&& message)
{
	Log::GetInstance()->WriteError(_T(message.c_str()));
}

void DrvOSIPIArchValues::HdaCommandHandler::SendWarning(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOSIPIArchValues::HdaCommandHandler::SendMessageInfo(std::string&& message)
{

}

void DrvOSIPIArchValues::HdaCommandHandler::GetServers(std::vector<std::pair<std::string, long> >&& servers)
{

}


void DrvOSIPIArchValues::HdaCommandHandler::SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName)
{

}

void DrvOSIPIArchValues::HdaCommandHandler::ConnectionOpened(bool isOpened)
{
	
}

void DrvOSIPIArchValues::HdaCommandHandler::ConnectionClosed(bool isClosed)
{
	
}