#include"pch.h"
#include"PIApplication.h"
#include"Constants.h"

DrvOSIPIArchValues::PIApplication::PIApplication() :m_hAppInstance()
{
	m_hAppInstance = pilg_registerapp(PI_API_DLL_NAME);
	if (m_hAppInstance == NULL) {

	}

}

DrvOSIPIArchValues::PIApplication::~PIApplication()
{
	pilg_unregisterapp();
	if (m_hAppInstance) {
		int32 res = pilg_disconnect();
	}
	
}

DrvOSIPIArchValues::PIApplication& DrvOSIPIArchValues::PIApplication::Instance()
{
	static PIApplication shared;
	return shared;
}

bool DrvOSIPIArchValues::PIApplication::StartApplication()
{
	return m_hAppInstance != NULL;
}