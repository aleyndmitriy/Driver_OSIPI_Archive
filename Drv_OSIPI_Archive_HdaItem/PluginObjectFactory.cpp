#include "pch.h"
#include "PluginObjectFactory.h"
#include <OdsErr.h>
//#include "DSource.h"
#include"Constants.h"

DrvOSIPIArchValues::PluginObjectFactory& DrvOSIPIArchValues::PluginObjectFactory::GetInstance()
{
	static PluginObjectFactory f;
	return f;
}

void* DrvOSIPIArchValues::PluginObjectFactory::GetInterface(int nIfcId)
{
	return this;
}

int DrvOSIPIArchValues::PluginObjectFactory::CreateObject(const TCHAR* szObjKey, void* pObjCreationParam, ODS::IPluginObj** ppPluginObj)
{
	*ppPluginObj = 0;
	if (_tcscmp(szObjKey, OSI_PI_HIST_VALUES)) {
		return ODS::ERR::BAD_PARAM;
	}
	//*ppPluginObj = new CDSource(DataAccessAssembly::Instance().GetSettingDataSource(), DataAccessAssembly::Instance().GetSoftingDataSource());
	if (*ppPluginObj)
		return ODS::ERR::OK;
	else
		return ODS::ERR::MEMORY_ALLOCATION_ERR;
}

int DrvOSIPIArchValues::PluginObjectFactory::DestroyObject(ODS::IPluginObj* pPluginObj)
{
	delete pPluginObj;

	return ODS::ERR::OK;
}

void DrvOSIPIArchValues::PluginObjectFactory::CreateRegisterInfo()
{
	regInfoDSList = std::make_unique<CRegisterInfo>(VERSION_MINOR, VERSION_MAJOR, OSI_PI_HIST_VALUES, nullptr, this);
}

ODS::RegisterInfo* DrvOSIPIArchValues::PluginObjectFactory::GetRegisterInfo()
{
	if (regInfoDSList) {
		return &(regInfoDSList->m_RegInfo);
	}
	else {
		return nullptr;
	}

}