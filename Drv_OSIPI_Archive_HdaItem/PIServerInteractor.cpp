#include"pch.h"
#include"PIServerInteractor.h"
#include "Utils.h"
#include"Constants.h"


DrvOSIPIArchValues::PIServerInteractor::PIServerInteractor():
	m_pServerAttributes(), m_pDataAttributes(), m_pOutput(), m_isGoodInclude(false), m_isAnnotatedInclude(false), m_isQuestionableInclude(false), m_isSubstitutedInclude(false)
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
	if (m_pDataAttributes->m_vDataQuantities.empty()) {
		m_isGoodInclude = true;
	}
	else {
		for (std::vector<std::string>::const_iterator itr = m_pDataAttributes->m_vDataQuantities.cbegin(); itr != m_pDataAttributes->m_vDataQuantities.cend(); ++itr) {
			try {
				unsigned int mask = std::stoul(*itr);
				if (mask == PI_M_SFLAG) {
					m_isSubstitutedInclude = true;
				}
				else if (mask == PI_M_QFLAG) {
					m_isQuestionableInclude = true;
				}
				else if (mask == PI_M_AFLAG){
					m_isAnnotatedInclude = true;
				}
				else if (mask == 0) {
					m_isGoodInclude = true;
				}
			}
			catch (std::exception& e) {
				m_isGoodInclude = true;
			}
		}
	}
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
	int32 res = 0;
	int32 startPiTime = PiTimeFromSysTime(startTime);
	int32 endPiTime = PiTimeFromSysTime(endTime);
	PITIMESTAMP piStartTime;
	ZeroMemory(&piStartTime, sizeof(PITIMESTAMP));
	res = pitm_settime(&piStartTime, startTime.wYear, startTime.wMonth, startTime.wDay, startTime.wHour, startTime.wMinute, startTime.wSecond);
	PITIMESTAMP piEndTime;
	ZeroMemory(&piEndTime, sizeof(PITIMESTAMP));
	res = pitm_settime(&piEndTime, endTime.wYear, endTime.wMonth, endTime.wDay, endTime.wHour, endTime.wMinute, endTime.wSecond);
	
	tagsData.clear();
	int32 pt = 0;
	PIvaluetype type;
	std::vector<std::pair<int32, short> > vec;
	std::shared_ptr<IServerInteractorOutput> output = m_pOutput.lock();
	for (std::set<std::string>::const_iterator itr = tagNames.cbegin(); itr != tagNames.cend(); ++itr) {
		res = pipt_findpoint(const_cast<char*>(itr->c_str()), &pt);
		if (res == SUCCESS) {
			res = pipt_pointtypex(pt, &type);
			if (res == SUCCESS) {
				std::vector<Record> vecRecords;
				if (m_pDataAttributes->m_iProcessed) {
					getProcessedData(pt, m_pDataAttributes->m_pAggregateType.second, startPiTime, endPiTime, m_pDataAttributes->m_dProcessingInterval, vecRecords);
				}
				else {
					getRawData(pt, type, &piStartTime, &piEndTime, vecRecords);
				}
				if (!vecRecords.empty()) {
					tagsData.insert(std::make_pair<std::string, std::vector<Record> >(std::string(*itr),std::move(vecRecords)));
				}
				
			}
		}
	}
}

void DrvOSIPIArchValues::PIServerInteractor::getRawData(int32 pt, PIvaluetype type, PITIMESTAMP* startTime, PITIMESTAMP* endTime, std::vector<Record>& vecRecords)
{
	double dVal = 0.0;
	int32 iVal = 0;
	int32 iStat = 0;
	int16 iFlag = 0;
	uint32 uSize = MAX_TAGNAME_LEN;
	int32 valCount = LONG_MAX;
	PITIMESTAMP piPtTime;
	char stringData[MAX_TAGNAME_LEN];
	memcpy(&piPtTime, endTime, sizeof(PITIMESTAMP));
	int32 res = piar_getarcvaluesx(pt, ARCflag_comp, &valCount, &dVal, &iVal, stringData, &uSize, &iStat, &iFlag, startTime, &piPtTime, GETFIRST);
	if (res == SUCCESS || res == -15010) {
		if ((iFlag == 0 && m_isGoodInclude) || (iFlag == PI_M_AFLAG && m_isAnnotatedInclude) || (iFlag == PI_M_QFLAG && m_isQuestionableInclude) || (iFlag == PI_M_SFLAG && m_isSubstitutedInclude)) {
			vecRecords.push_back(mapRecordFromDataValue(type, dVal, iVal, stringData, uSize, piPtTime, iStat, iFlag));
		}
		while (res == SUCCESS || res == -15010) {
			memcpy(&piPtTime, endTime, sizeof(PITIMESTAMP));
			valCount = LONG_MAX;
			res = piar_getarcvaluesx(pt, ARCflag_even, &valCount, &dVal, &iVal, stringData, &uSize, &iStat, &iFlag, startTime, &piPtTime, GETNEXT);
			if (res == SUCCESS || res == -15010) {
				if ((iFlag == 0 && m_isGoodInclude) || (iFlag == PI_M_AFLAG && m_isAnnotatedInclude) || (iFlag == PI_M_QFLAG && m_isQuestionableInclude) || (iFlag == PI_M_SFLAG && m_isSubstitutedInclude)) {
					vecRecords.push_back(mapRecordFromDataValue(type, dVal, iVal, stringData, uSize, piPtTime, iStat, iFlag));
				}
			}
		}
	}
	/*valCount = 8000;
				int32 times[8000];
				times[0] = startPiTime;
				times[7999] = endPiTime;
				float rvals[8000];
				int32 istats[8000];
				res = piar_compvalues(pt, &valCount, times, rvals, istats,0);
				if (res == SUCCESS) {
					for (int index = 0; index < 8000; ++index) {
						res = istats[index];
					}
				}*/
}


void DrvOSIPIArchValues::PIServerInteractor::getProcessedData(int32 pt, int32 code, int32 startTime, int32 endTime, double processedInterval, std::vector<Record>& vecRecords)
{
	float rVal;
	float percent;
	int32 start = startTime;
	
	int32 interval = endTime - startTime;
	int procInterval = processedInterval / 1000;
	if (procInterval > 1 && procInterval < interval) {
		interval = procInterval;
	}
	int32 end = start + interval;
	int32 step = 0;
	while (start < endTime) {
		PITIMESTAMP piStartTime;
		ZeroMemory(&piStartTime, sizeof(PITIMESTAMP));
		int32 timeArray[6];
		pitm_secint(start, timeArray);
		int res = pitm_settime(&piStartTime, timeArray[2], timeArray[0], timeArray[1], timeArray[3], timeArray[4], timeArray[5]);
		res = piar_summary(pt, &start, &end, &rVal, &percent, code);
		if (res == SUCCESS) {
			vecRecords.push_back(mapRecordFromDataValue(PI_Type_float32, rVal, 0, NULL, 0, piStartTime, 0, 0));
		}
		step++;
		start = startTime + step * interval;
		end = start + interval;
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

int32 DrvOSIPIArchValues::PiTimeFromPiTimeStamp(const PITIMESTAMP& sysTime)
{
	int32 piTime;
	int32 arrayTime[6];
	arrayTime[0] = sysTime.month;
	arrayTime[1] = sysTime.day;
	arrayTime[2] = sysTime.year;
	arrayTime[3] = sysTime.hour;
	arrayTime[4] = sysTime.minute;
	arrayTime[5] = sysTime.second;
	pitm_intsec(&piTime, arrayTime);
	return piTime;
}


DrvOSIPIArchValues::Record DrvOSIPIArchValues::mapRecordFromDataValue(PIvaluetype type, double dValue, int32 iVal, char* strVal, uint32 strSize,
	const PITIMESTAMP& piTime, int32 iStat, int16 iFlag)
{
	Record record;
	record.SetStatus(iFlag);
	SYSTEMTIME serverDataTime = { 0 };
	uint32 uInt;
	serverDataTime.wYear = piTime.year;
	serverDataTime.wMonth = piTime.month;
	serverDataTime.wDay = piTime.day;
	serverDataTime.wHour = piTime.hour;
	serverDataTime.wMinute = piTime.minute;
	serverDataTime.wSecond = piTime.second;
	char* strPtr = reinterpret_cast<char*>(&serverDataTime);
	record.insert(OSI_PI_SERVER_TIMESTAMP, PI_Type_PItimestamp, std::string(strPtr, sizeof(SYSTEMTIME)));
	std::string valueStr;
	switch (type)
	{
	case PI_Type_null:
		valueStr.clear();
		break;
	case PI_Type_bool:
		if (iVal > 0) {
			valueStr = std::to_string(1);
		}
		else {
			valueStr = std::to_string(0);
		}
		break;
	case PI_Type_int8:
	case PI_Type_int16:
	case PI_Type_int32:
		valueStr = std::to_string(iVal);
		break;
	case PI_Type_int64:
		valueStr = std::to_string(iVal);
		break;
	case PI_Type_uint8:
	case PI_Type_uint16:
	case PI_Type_uint32:
		uInt = iVal;
		valueStr = std::to_string(uInt);
		break;
	case PI_Type_uint64:
		uInt = iVal;
		valueStr = std::to_string(uInt);
		break;
	case PI_Type_float64:
		valueStr = std::to_string(dValue);
		break;
	case PI_Type_float32:
	case PI_Type_float16:
		valueStr = std::to_string(dValue);
		break;
	case PI_Type_PItimestamp:
		
		break;
	case PI_Type_digital:
		valueStr = std::to_string(iStat);
		break;
	default:
		strVal[strSize - 1] = '\0';
		valueStr = std::string(strVal);
		break;
	}
	record.insert(OSI_PI_VALUE, (short)type, valueStr);
	return record;
}