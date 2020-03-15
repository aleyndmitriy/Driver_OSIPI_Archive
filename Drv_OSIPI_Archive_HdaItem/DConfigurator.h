#pragma once
#include <IDsConfigurator.h>
#include <Interface\IAbstractUIFacrory.h>
#include <functional>
#include"ISettingsDataSource.h"
#include"IServerInteractor.h"

namespace DrvOSIPIArchValues
{
	class CDsConfigurator : public ODS::IDsConfigurator
	{
	private:
		std::function<ODS::UI::IAbstractUIFacrory * (void)>  m_uiFactoryGetter;
		std::shared_ptr<ISettingsDataSource> m_settingsDataStore;
		std::shared_ptr<IServerInteractor> m_pInteractor;
		HWND m_hParentWindow;
	public:

		CDsConfigurator(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter, std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<IServerInteractor> interactor);
		~CDsConfigurator() = default;

		void* GetInterface(int nIfcId) override;

		int Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString) override;

		int DestroyString(TCHAR* szCfgString) override;

		void SetOwnerWnd(void* pOwnerWnd) override;
	};
}