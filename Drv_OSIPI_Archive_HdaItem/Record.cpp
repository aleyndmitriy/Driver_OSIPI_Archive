#include"pch.h"
#include"Record.h"
#include"Constants.h"
#include<piapix.h>

#include<OdsCoreLib/TimeUtils.h>

DrvOSIPIArchValues::Record::Record() :recordData(), status(0)
{

}


std::pair<typename DrvOSIPIArchValues::Record::const_iterator, bool> DrvOSIPIArchValues::Record::insert(std::string colName, short dataType, std::string value)
{
	typename DrvOSIPIArchValues::Record::FieldData val = std::make_pair(dataType, value);
	std::pair<std::string, typename DrvOSIPIArchValues::Record::FieldData> rec = std::make_pair(colName, val);
	return recordData.insert(rec);
}

int DrvOSIPIArchValues::Record::GetStatus() const
{
	return status;
}

void DrvOSIPIArchValues::Record::SetStatus(int iStatus)
{
	status = iStatus;
}

const typename DrvOSIPIArchValues::Record::FieldData& DrvOSIPIArchValues::Record::at(const std::string& key) const
{
	return recordData.at(key);
}

typename DrvOSIPIArchValues::Record::const_iterator DrvOSIPIArchValues::Record::cbegin() const
{
	return recordData.cbegin();
}

typename DrvOSIPIArchValues::Record::const_iterator DrvOSIPIArchValues::Record::cend() const
{
	return recordData.cend();
}

typename DrvOSIPIArchValues::Record::const_iterator DrvOSIPIArchValues::Record::findColumnValue(const std::string& key) const
{
	return recordData.find(key);
}

size_t DrvOSIPIArchValues::Record::GetColumnNumber() const
{
	return recordData.size();
}

DrvOSIPIArchValues::Record::~Record()
{
	recordData.clear();
}

bool DrvOSIPIArchValues::operator==(const DrvOSIPIArchValues::Record& lhs, const DrvOSIPIArchValues::Record& rhs)
{
	return lhs.recordData == rhs.recordData;
}

bool DrvOSIPIArchValues::operator!=(const DrvOSIPIArchValues::Record& lhs, const DrvOSIPIArchValues::Record& rhs)
{
	return lhs.recordData != rhs.recordData;
}

bool DrvOSIPIArchValues::operator<(const DrvOSIPIArchValues::Record& lhs, const DrvOSIPIArchValues::Record& rhs)
{
	return lhs.recordData < rhs.recordData;
}

bool DrvOSIPIArchValues::operator<=(const DrvOSIPIArchValues::Record& lhs, const DrvOSIPIArchValues::Record& rhs)
{
	return lhs.recordData <= rhs.recordData;
}

bool DrvOSIPIArchValues::operator>(const DrvOSIPIArchValues::Record& lhs, const DrvOSIPIArchValues::Record& rhs)
{
	return lhs.recordData > rhs.recordData;
}

bool DrvOSIPIArchValues::operator>=(const DrvOSIPIArchValues::Record& lhs, const DrvOSIPIArchValues::Record& rhs)
{
	return lhs.recordData >= rhs.recordData;
}

bool DrvOSIPIArchValues::CompareRecordsValueLess(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = nullptr;
	const SYSTEMTIME* timeStampStructRight = nullptr;
	Record::const_iterator itrLhs = lhs.findColumnValue(OSI_PI_VALUE);
	Record::const_iterator itrRhs = rhs.findColumnValue(OSI_PI_VALUE);
	if (itrLhs == lhs.cend() || itrRhs == rhs.cend()) {
		return false;
	}
	if (itrLhs->second.first != itrRhs->second.first) {
		return false;
	}
	switch (itrLhs->second.first)
	{
	case PI_Type_null:
		return false;
		break;
	case PI_Type_bool:
	case PI_Type_int8:
	case PI_Type_int16:
	case PI_Type_int32:
		return std::stoi(itrLhs->second.second) < std::stoi(itrRhs->second.second);
		break;
	case PI_Type_int64:
		return std::stoll(itrLhs->second.second) < std::stoll(itrRhs->second.second);
		break;
	case PI_Type_uint8:
	case PI_Type_uint16:
	case PI_Type_uint32:
		return std::stoul(itrLhs->second.second) < std::stoul(itrRhs->second.second);
		break;
	case PI_Type_uint64:
		return std::stoull(itrLhs->second.second) < std::stoull(itrRhs->second.second);
		break;
	case PI_Type_float64:
		return std::stod(itrLhs->second.second) < std::stod(itrRhs->second.second);
		break;
	case PI_Type_float32:
	case PI_Type_float16:
		return std::stof(itrLhs->second.second) < std::stof(itrRhs->second.second);
		break;
	case PI_Type_PItimestamp:
		timeStampStructLeft = reinterpret_cast<const SYSTEMTIME*>(itrLhs->second.second.c_str());
		timeStampStructRight = reinterpret_cast<const SYSTEMTIME*>(itrRhs->second.second.c_str());
		return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) < 0;
		break;
	default:
		return itrLhs->second.second < itrRhs->second.second;
		break;
	}
}

bool DrvOSIPIArchValues::CompareRecordsValue(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = nullptr;
	const SYSTEMTIME* timeStampStructRight = nullptr;
	Record::const_iterator itrLhs = lhs.findColumnValue(OSI_PI_VALUE);
	Record::const_iterator itrRhs = rhs.findColumnValue(OSI_PI_VALUE);
	if (itrLhs == lhs.cend() || itrRhs == rhs.cend()) {
		return false;
	}
	if (itrLhs->second.first != itrRhs->second.first) {
		return false;
	}
	switch (itrLhs->second.first)
	{
	case PI_Type_null:
		return true;
		break;
	case PI_Type_bool:
	case PI_Type_int8:
	case PI_Type_int16:
	case PI_Type_int32:
		return std::stoi(itrLhs->second.second) == std::stoi(itrRhs->second.second);
		break;
	case PI_Type_int64:
		return std::stoll(itrLhs->second.second) == std::stoll(itrRhs->second.second);
		break;
	case PI_Type_uint8:
	case PI_Type_uint16:
	case PI_Type_uint32:
		return std::stoul(itrLhs->second.second) == std::stoul(itrRhs->second.second);
		break;
	case PI_Type_uint64:
		return std::stoull(itrLhs->second.second) == std::stoull(itrRhs->second.second);
		break;
	case PI_Type_float64:
		return std::stod(itrLhs->second.second) == std::stod(itrRhs->second.second);
		break;
	case PI_Type_float32:
	case PI_Type_float16:
		return std::stof(itrLhs->second.second) == std::stof(itrRhs->second.second);
		break;
	case PI_Type_PItimestamp:
		timeStampStructLeft = reinterpret_cast<const SYSTEMTIME*>(itrLhs->second.second.c_str());
		timeStampStructRight = reinterpret_cast<const SYSTEMTIME*>(itrRhs->second.second.c_str());
		return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) < 0;
		break;
	default:
		return itrLhs->second.second == itrRhs->second.second;
		break;
	}
}

const SYSTEMTIME* DrvOSIPIArchValues::GetTimeStampFromRecord(const Record& rec)
{
	Record::const_iterator itr = rec.findColumnValue(OSI_PI_SERVER_TIMESTAMP);
	if (itr == rec.cend()) {
		return nullptr;
	}
	if (itr->second.first != PI_Type_PItimestamp) {
		return nullptr;
	}
	return reinterpret_cast<const SYSTEMTIME*>(itr->second.second.c_str());
}

bool DrvOSIPIArchValues::CompareRecordsDataTimeLess(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = GetTimeStampFromRecord(lhs);
	const SYSTEMTIME* timeStampStructRight = GetTimeStampFromRecord(rhs);
	if (timeStampStructLeft == nullptr || timeStampStructRight == nullptr) {
		return false;
	}
	return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) < 0;
}

bool DrvOSIPIArchValues::CompareRecordsDataTime(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = GetTimeStampFromRecord(lhs);
	const SYSTEMTIME* timeStampStructRight = GetTimeStampFromRecord(rhs);
	if (timeStampStructLeft == nullptr || timeStampStructRight == nullptr) {
		return false;
	}
	return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) == 0;
}

bool DrvOSIPIArchValues::CompareRecord(const Record& lhs, const std::string& val, ConditionType type)
{
	const SYSTEMTIME* timeStampStructLeft = nullptr;
	const SYSTEMTIME* timeStampStructRight = nullptr;
	Record::const_iterator itrLhs = lhs.findColumnValue(OSI_PI_VALUE);
	if (itrLhs == lhs.cend()) {
		return false;
	}
	if (val.empty()) {
		if (itrLhs->second.first == PI_Type_null) {
			return true;
		}
		return false;
	}
	switch (itrLhs->second.first)
	{
	case PI_Type_bool:
	case PI_Type_int8:
	case PI_Type_int16:
	case PI_Type_int32:
		switch (type) {
		case ConditionType::CONDTYPE_LESS:
			return std::stoi(itrLhs->second.second) < std::stoi(val);
			break;
		case ConditionType::CONDTYPE_GREATER:
			return std::stoi(itrLhs->second.second) > std::stoi(val);
			break;
		case ConditionType::CONDTYPE_LESSEQUAL:
			return std::stoi(itrLhs->second.second) <= std::stoi(val);
			break;
		case ConditionType::CONDTYPE_GREATEREQUAL:
			return std::stoi(itrLhs->second.second) >= std::stoi(val);
			break;
		case ConditionType::CONDTYPE_NOTEQUAL:
			return std::stoi(itrLhs->second.second) != std::stoi(val);
			break;
		default:
			return std::stoi(itrLhs->second.second) == std::stoi(val);
			break;
		}
	case PI_Type_int64:
		switch (type) {
		case ConditionType::CONDTYPE_LESS:
			return std::stoll(itrLhs->second.second) < std::stoll(val);
			break;
		case ConditionType::CONDTYPE_GREATER:
			return std::stoll(itrLhs->second.second) > std::stoll(val);
			break;
		case ConditionType::CONDTYPE_LESSEQUAL:
			return std::stoll(itrLhs->second.second) <= std::stoll(val);
			break;
		case ConditionType::CONDTYPE_GREATEREQUAL:
			return std::stoll(itrLhs->second.second) >= std::stoll(val);
			break;
		case ConditionType::CONDTYPE_NOTEQUAL:
			return std::stoll(itrLhs->second.second) != std::stoll(val);
			break;
		default:
			return std::stoll(itrLhs->second.second) == std::stoll(val);
			break;
		}
	case PI_Type_uint8:
	case PI_Type_uint16:
	case PI_Type_uint32:
		switch (type) {
		case ConditionType::CONDTYPE_LESS:
			return std::stoul(itrLhs->second.second) < std::stoul(val);
			break;
		case ConditionType::CONDTYPE_GREATER:
			return std::stoul(itrLhs->second.second) > std::stoul(val);
			break;
		case ConditionType::CONDTYPE_LESSEQUAL:
			return std::stoul(itrLhs->second.second) <= std::stoul(val);
			break;
		case ConditionType::CONDTYPE_GREATEREQUAL:
			return std::stoul(itrLhs->second.second) >= std::stoul(val);
			break;
		case ConditionType::CONDTYPE_NOTEQUAL:
			return std::stoul(itrLhs->second.second) != std::stoul(val);
			break;
		default:
			return std::stoul(itrLhs->second.second) == std::stoul(val);
			break;
		}
	case PI_Type_uint64:
		switch (type) {
		case ConditionType::CONDTYPE_LESS:
			return std::stoull(itrLhs->second.second) < std::stoull(val);
			break;
		case ConditionType::CONDTYPE_GREATER:
			return std::stoull(itrLhs->second.second) > std::stoull(val);
			break;
		case ConditionType::CONDTYPE_LESSEQUAL:
			return std::stoull(itrLhs->second.second) <= std::stoull(val);
			break;
		case ConditionType::CONDTYPE_GREATEREQUAL:
			return std::stoull(itrLhs->second.second) >= std::stoull(val);
			break;
		case ConditionType::CONDTYPE_NOTEQUAL:
			return std::stoull(itrLhs->second.second) != std::stoull(val);
			break;
		default:
			return std::stoull(itrLhs->second.second) == std::stoull(val);
			break;
		}
	case PI_Type_float64:
		switch (type) {
		case ConditionType::CONDTYPE_LESS:
			return std::stod(itrLhs->second.second) < std::stod(val);
			break;
		case ConditionType::CONDTYPE_GREATER:
			return std::stod(itrLhs->second.second) > std::stod(val);
			break;
		case ConditionType::CONDTYPE_LESSEQUAL:
			return std::stod(itrLhs->second.second) <= std::stod(val);
			break;
		case ConditionType::CONDTYPE_GREATEREQUAL:
			return std::stod(itrLhs->second.second) >= std::stod(val);
			break;
		case ConditionType::CONDTYPE_NOTEQUAL:
			return std::stod(itrLhs->second.second) != std::stod(val);
			break;
		default:
			return std::stod(itrLhs->second.second) == std::stod(val);
			break;
		}
	case PI_Type_float32:
	case PI_Type_float16:
		switch (type) {
		case ConditionType::CONDTYPE_LESS:
			return std::stof(itrLhs->second.second) < std::stof(val);
			break;
		case ConditionType::CONDTYPE_GREATER:
			return std::stof(itrLhs->second.second) > std::stof(val);
			break;
		case ConditionType::CONDTYPE_LESSEQUAL:
			return std::stof(itrLhs->second.second) <= std::stof(val);
			break;
		case ConditionType::CONDTYPE_GREATEREQUAL:
			return std::stof(itrLhs->second.second) >= std::stof(val);
			break;
		case ConditionType::CONDTYPE_NOTEQUAL:
			return std::stof(itrLhs->second.second) != std::stof(val);
			break;
		default:
			return std::stof(itrLhs->second.second) == std::stof(val);
			break;
		}
	case PI_Type_PItimestamp:
		timeStampStructLeft = reinterpret_cast<const SYSTEMTIME*>(itrLhs->second.second.c_str());
		timeStampStructRight = reinterpret_cast<const SYSTEMTIME*>(val.c_str());
		return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) == 0;
		break;
	default:
		return itrLhs->second.second == val;
		break;
	}
}

DrvOSIPIArchValues::Record DrvOSIPIArchValues::RecordsSum(const Record& lhs, const Record& rhs)
{
	DrvOSIPIArchValues::Record record;
	Record::const_iterator itrLhs = lhs.findColumnValue(OSI_PI_VALUE);
	Record::const_iterator itrRhs = rhs.findColumnValue(OSI_PI_VALUE);
	if (itrLhs == lhs.cend() || itrLhs->second.first < PI_Type_uint8 || itrLhs->second.first > PI_Type_float64) {
		if (itrRhs != rhs.cend() && itrRhs->second.first > PI_Type_bool && itrRhs->second.first < PI_Type_PI2) {
			record.insert(OSI_PI_VALUE, itrRhs->second.first, itrRhs->second.second);
			return record;
		}
		else {
			record.insert(OSI_PI_VALUE, PI_Type_null, std::string());
			return record;
		}
	}
	if (itrRhs == rhs.cend() || itrRhs->second.first < PI_Type_uint8 || itrRhs->second.first > PI_Type_float64) {
		record.insert(OSI_PI_VALUE, itrLhs->second.first, itrLhs->second.second);
		return record;
	}
	switch (itrLhs->second.first)
	{
	case PI_Type_int8:
	case PI_Type_int16:
	case PI_Type_int32:
	{
		int res = std::stoi(itrLhs->second.second) + std::stoi(itrRhs->second.second);
		record.insert(OSI_PI_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case PI_Type_int64:
	{
		long long res = std::stoll(itrLhs->second.second) + std::stoll(itrRhs->second.second);
		record.insert(OSI_PI_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case PI_Type_uint8:
	case PI_Type_uint16:
	case PI_Type_uint32:
	{
		unsigned long res = std::stoul(itrLhs->second.second) + std::stoul(itrRhs->second.second);
		record.insert(OSI_PI_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case PI_Type_uint64:
	{
		unsigned long long res = std::stoull(itrLhs->second.second) + std::stoull(itrRhs->second.second);
		record.insert(OSI_PI_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case PI_Type_float64:
	{
		double res = std::stod(itrLhs->second.second) + std::stod(itrRhs->second.second);
		record.insert(OSI_PI_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case PI_Type_float16:
	case PI_Type_float32:
	{
		float res = std::stof(itrLhs->second.second) + std::stof(itrRhs->second.second);
		record.insert(OSI_PI_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	default:
		record.insert(OSI_PI_VALUE, PI_Type_null, std::string());
		return record;
		break;
	}
}

DrvOSIPIArchValues::Record DrvOSIPIArchValues::RecordAvg(const Record& record, unsigned int quantity)
{
	DrvOSIPIArchValues::Record avgRecord;
	Record::const_iterator itr = record.findColumnValue(OSI_PI_VALUE);
	if (itr == record.cend()) {
		avgRecord.insert(OSI_PI_VALUE, PI_Type_null, std::string());
		return avgRecord;
	}
	double res = 0.0;
	switch (itr->second.first)
	{
	case PI_Type_int8:
	case PI_Type_int16:
	case PI_Type_int32:
	{
		int val = std::stoi(itr->second.second);
		res = (double)val / (double)quantity;

	}
	break;
	case PI_Type_int64:
	{
		long long val = std::stoll(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	case PI_Type_uint8:
	case PI_Type_uint16:
	case PI_Type_uint32:
	{
		unsigned long val = std::stoul(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	case PI_Type_uint64:
	{
		unsigned long long val = std::stoull(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	case PI_Type_float64:
	{
		double val = std::stod(itr->second.second);
		res = val / (double)quantity;
	}
	break;
	case PI_Type_float16:
	case PI_Type_float32:
	{
		float val = std::stof(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	default:
		avgRecord.insert(OSI_PI_VALUE, PI_Type_null, std::string());
		return avgRecord;
		break;
	}
	avgRecord.insert(OSI_PI_VALUE, PI_Type_float64, std::to_string(res));
	return avgRecord;
}
