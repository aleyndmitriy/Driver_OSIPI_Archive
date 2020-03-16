#include "pch.h"
#include "DSource.h"
#include "PluginObjectFactory.h"
#include"Log.h"

DrvOSIPIArchValues::CDSource::CDSource(std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<IServerInteractor> interactor) : m_Configurator([this]()->ODS::UI::IAbstractUIFacrory* {
	if (m_pHost)
		return (ODS::UI::IAbstractUIFacrory*) (m_pHost->GetInterface(ODS::IPluginHost::IID_UI_FACTORY));
	return 	nullptr;
	}, settingsDataStore, interactor), m_Browser(settingsDataStore, interactor), m_Server(settingsDataStore, interactor), m_pHost(nullptr)
{

}

	DrvOSIPIArchValues::CDSource::~CDSource()
	{
		m_pHost = nullptr;
	}

	void* DrvOSIPIArchValues::CDSource::GetInterface(int nIfcID)
	{
		return this;
	}

	ODS::IDsConfigurator* DrvOSIPIArchValues::CDSource::GetConfigurator()
	{
		return &m_Configurator;
	}

	ODS::IServerHda* DrvOSIPIArchValues::CDSource::GetServer()
	{
		return &m_Server;
	}

	ODS::IBrowserItem* DrvOSIPIArchValues::CDSource::GetBrowser()
	{
		return &m_Browser;
	}

	int DrvOSIPIArchValues::CDSource::Attach(const ODS::IPluginHost* pHost)
	{
		if (!pHost)
			return ODS::ERR::BAD_PARAM;

		m_pHost = const_cast<ODS::IPluginHost*>(pHost);
		ODS::System::ILog* pILog =
			static_cast<ODS::System::ILog*>(m_pHost->GetInterface(ODS::IPluginHost::IID_LOG));
		Log::GetInstance()->Init(pILog);
		return ODS::ERR::OK;
	}

	int DrvOSIPIArchValues::CDSource::Detach()
	{
		m_pHost = 0;
		return ODS::ERR::OK;
	}

	ODS::IPropertySet* DrvOSIPIArchValues::CDSource::GetPropertySet()
	{
		ODS::RegisterInfo* pInfo = PluginObjectFactory::GetInstance().GetRegisterInfo();
		return pInfo->m_pPropertySet;
	}