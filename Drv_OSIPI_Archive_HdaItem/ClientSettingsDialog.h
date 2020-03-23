#pragma once
#include<functional>
#include <Interface\IAbstractUIFacrory.h>
#include"ConnectionAttributes.h"
#include"IServerInteractor.h"
#include "afxdialogex.h"

class CClientSettingsDialog : public CDialogEx, public DrvOSIPIArchValues::IServerInteractorOutput, public std::enable_shared_from_this<CClientSettingsDialog>
{
	DECLARE_DYNAMIC(CClientSettingsDialog)

public:
	CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOSIPIArchValues::IServerInteractor> interactor, std::shared_ptr<DrvOSIPIArchValues::ConnectionAttributes> attributes, std::shared_ptr<DrvOSIPIArchValues::DataTypeAttributes> dataAttributes, CWnd* pParent);
	virtual ~CClientSettingsDialog();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_SETTINGS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	std::function<ODS::UI::IAbstractUIFacrory * (void)> m_uiFactoryGetter;
	std::shared_ptr<DrvOSIPIArchValues::ConnectionAttributes> m_connectAttributes;
	std::shared_ptr<DrvOSIPIArchValues::DataTypeAttributes> m_dataAttributes;
	std::shared_ptr<DrvOSIPIArchValues::IServerInteractor> m_pInteractor;
	CComboBox m_cmbServerName;
	CEdit m_editPort;
	CEdit m_editLogin;
	CEdit m_editUserPassword;
	CComboBox m_cmbAggregateType;
	CEdit m_editProcessingInterval;
	CSpinButtonCtrl m_spinTimeInterval;
	CComboBox m_cmbReadType;
	CEdit m_editDataQuality;

	BOOL OnInitDialog() override;
	void SetUpInitialState();
	void StartLoading();
	void StopLoading();
	void ReadAttributes();
	void WarningMessage(std::string message);
	void ErrorMessage(std::string message);
	void ShowDataReadTypeView(BOOL bShow);
	void fillAggregateList();
public:
	afx_msg void OnCbnSelchangeComboSelectServer();
	afx_msg void OnCbnEditChangeComboSelectServer();
	afx_msg void OnEnChangeEditPort();
	afx_msg void OnBtnClickedButtonBrowseNetwork();
	afx_msg void OnBtnClickedButtonDiscoverServers();
	afx_msg void OnBtnClickedButtonTestConnection();
	afx_msg void OnBtnClickedCancel();
	afx_msg void OnBtnClickedOk();
	afx_msg void OnDeltaPosSpinInterval(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCbnSelChangeComboReadType();
	afx_msg void OnEnUpdateEditDataQuality();
	void SendMessageError(std::string&& message) override;
	void SendWarning(std::string&& message) override;
	void SendMessageInfo(std::string&& message) override;
	void GetServers(std::vector<std::pair<std::string, long>>&& servers) override;
	void SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName) override;
	void GetNewConnectionGuide(std::string&& uuid) override;
	void CloseConnectionWithGuide(std::string&& uuid) override;
};