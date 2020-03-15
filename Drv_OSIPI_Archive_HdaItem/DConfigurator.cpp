#include"pch.h"
#include <sstream>
#include "DConfigurator.h"
#include <OdsErr.h>
#include <OdsString.h>
#include"ConnectionAttributes.h"
#include"XMLSettingsDataSource.h"
#include "ClientSettingsDialog.h"
#include"Constants.h"

DrvOSIPIArchValues::CDsConfigurator::CDsConfigurator(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter, std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<IServerInteractor> interactor) :m_uiFactoryGetter(uiFactoryGetter), m_settingsDataStore(settingsDataStore), m_pInteractor(interactor), m_hParentWindow(nullptr)
{

}

void* DrvOSIPIArchValues::CDsConfigurator::GetInterface(int nIfcId)
{
	return NULL;
}

int DrvOSIPIArchValues::CDsConfigurator::DestroyString(TCHAR* szCfgString)
{
	delete[] szCfgString;

	return ODS::ERR::OK;
}

void DrvOSIPIArchValues::CDsConfigurator::SetOwnerWnd(void* pOwnerWnd)
{
	m_hParentWindow = reinterpret_cast<HWND>(pOwnerWnd);
}

int DrvOSIPIArchValues::CDsConfigurator::Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString)
{
	int iRes = ODS::ERR::FILE;
	std::shared_ptr<ConnectionAttributes> attributes = std::make_shared<ConnectionAttributes>();
	std::shared_ptr<DataTypeAttributes> dataAttributes = std::make_shared<DataTypeAttributes>();
	if (szCfgInString != NULL)
	{
		size_t len = _tcslen(szCfgInString);
		if (len > 0) {
			m_settingsDataStore->LoadAttributesString(szCfgInString, len, *attributes, *dataAttributes);
		}
	}
	HINSTANCE hOld = AfxGetResourceHandle();
	HMODULE hModule = GetModuleHandle(OSI_PI_LIBRARY_NAME);
	AfxSetResourceHandle(hModule);
	CWnd* parent = CWnd::FromHandle(m_hParentWindow);
	std::shared_ptr<CClientSettingsDialog> dlg = std::make_shared<CClientSettingsDialog>(m_uiFactoryGetter, m_pInteractor, attributes, dataAttributes, parent);
	int response = dlg->DoModal();
	if (response == IDOK) {
		std::ostringstream outStream;
		m_settingsDataStore->Save(*attributes, *dataAttributes, outStream);
		std::string outString = outStream.str();
		char* outStr = new char[outString.length() + 1];
		_tcscpy_s(outStr, outString.length() + 1, outString.c_str());
		*pszCfgOutString = outStr;
		iRes = ODS::ERR::OK;
	}
	else {
		if (szCfgInString != NULL)
		{
			size_t len = _tcslen(szCfgInString);
			char* outStr = new char[len + 1];
			_tcscpy_s(outStr, len + 1, szCfgInString);
			*pszCfgOutString = outStr;
			iRes = ODS::ERR::OK;
		}
	}
	return iRes;
}