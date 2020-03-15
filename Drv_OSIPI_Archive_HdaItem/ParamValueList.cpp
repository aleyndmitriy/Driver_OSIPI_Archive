#include"pch.h"
#include"ParamValueList.h"

DrvOSIPIArchValues::Limit::Limit(int limitSide, int limitOffset, int limitCount) :m_nLimitSide(limitSide), m_nLimitOffset(limitOffset), m_nLimitCount(limitCount)
{

}

DrvOSIPIArchValues::Limit::Limit() : Limit(0, 0, 0)
{

}

DrvOSIPIArchValues::Limit::~Limit()
{

}

bool DrvOSIPIArchValues::Limit::IsLimit() const
{
	return (m_nLimitOffset != 0 && m_nLimitCount != 0);
}

DrvOSIPIArchValues::ParamValueList::ParamValueList(std::string&& address, std::string&& fullAddress, std::string&& sql, bool prevPoint, bool postPoint, int valueType, Limit&& limit) :
	ParamValue(std::move(address), std::move(fullAddress), std::move(sql), prevPoint, postPoint), m_ValueType(valueType), m_Limit(std::move(limit))
{

}

DrvOSIPIArchValues::ParamValueList::ParamValueList() :ParamValueList(std::string(), std::string(), std::string(), false, false, 0, Limit())
{

}

DrvOSIPIArchValues::ParamValueList::~ParamValueList() {

}

DrvOSIPIArchValues::Limit DrvOSIPIArchValues::ParamValueList::GetLimit() const
{
	return m_Limit;
}

int DrvOSIPIArchValues::ParamValueList::GetValueType() const
{
	return m_ValueType;
}