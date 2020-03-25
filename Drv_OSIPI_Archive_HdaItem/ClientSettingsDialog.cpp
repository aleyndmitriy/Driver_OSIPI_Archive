#include"pch.h"
#include "resource.h"	
#include"ClientSettingsDialog.h"
//#include"Log.h"
#include "Utils.h"
#include"Constants.h"

IMPLEMENT_DYNAMIC(CClientSettingsDialog, CDialogEx)

CClientSettingsDialog::CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOSIPIArchValues::IServerInteractor> interactor, std::shared_ptr<DrvOSIPIArchValues::ConnectionAttributes> attributes, std::shared_ptr<DrvOSIPIArchValues::DataTypeAttributes> dataAttributes, CWnd* pParent)
	: CDialogEx(IDD_CLIENT_SETTINGS_DLG, pParent), m_uiFactoryGetter(uiFactiryGetter), m_connectAttributes(attributes), m_dataAttributes(dataAttributes), m_pInteractor(interactor)
{
	m_pInteractor->SetAttributes(m_connectAttributes);
	m_pInteractor->SetDataAttributes(m_dataAttributes);
}

CClientSettingsDialog::~CClientSettingsDialog()
{
	m_connectAttributes.reset();
	m_dataAttributes.reset();
	m_pInteractor.reset();
}

void CClientSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SELECT_SERVER, m_cmbServerName);
	DDX_Control(pDX, IDC_EDIT_PORT, m_editPort);
	DDX_Control(pDX, IDC_EDIT_LOGIN, m_editLogin);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editUserPassword);
	DDX_Control(pDX, IDC_COMBO_AGGREGATE, m_cmbAggregateType);
	DDX_Control(pDX, IDC_EDIT_PROCESSING_INTERVAL, m_editProcessingInterval);
	DDX_Control(pDX, IDC_SPIN_INTERVAL, m_spinTimeInterval);
	DDX_Control(pDX, IDC_COMBO_READ_TYPE, m_cmbReadType);
	DDX_Control(pDX, IDC_EDIT_DATA_QUALITY, m_editDataQuality);
}


BEGIN_MESSAGE_MAP(CClientSettingsDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_SERVER, &CClientSettingsDialog::OnCbnSelchangeComboSelectServer)
	ON_EN_CHANGE(IDC_EDIT_PORT, &CClientSettingsDialog::OnEnChangeEditPort)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_NETWORK, &CClientSettingsDialog::OnBtnClickedButtonBrowseNetwork)
	ON_BN_CLICKED(IDC_BUTTON_DISCOVER_SERVERS, &CClientSettingsDialog::OnBtnClickedButtonDiscoverServers)
	ON_BN_CLICKED(IDC_BUTTON_TEST_CONNECTION, &CClientSettingsDialog::OnBtnClickedButtonTestConnection)
	ON_BN_CLICKED(IDCANCEL, &CClientSettingsDialog::OnBtnClickedCancel)
	ON_BN_CLICKED(IDOK, &CClientSettingsDialog::OnBtnClickedOk)
	ON_CBN_EDITCHANGE(IDC_COMBO_SELECT_SERVER, &CClientSettingsDialog::OnCbnEditChangeComboSelectServer)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_INTERVAL, &CClientSettingsDialog::OnDeltaPosSpinInterval)
	ON_CBN_SELCHANGE(IDC_COMBO_READ_TYPE, &CClientSettingsDialog::OnCbnSelChangeComboReadType)
	ON_EN_UPDATE(IDC_EDIT_DATA_QUALITY, &CClientSettingsDialog::OnEnUpdateEditDataQuality)
END_MESSAGE_MAP()

BOOL CClientSettingsDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetUpInitialState();
	
	if (!m_connectAttributes->configuration.serverName.empty()) {
		int ind = m_cmbServerName.AddString(m_connectAttributes->configuration.serverName.c_str());
		m_cmbServerName.SetCurSel(ind);
	}
	if (m_connectAttributes->configuration.port > 0) {
		std::string port = std::to_string(m_connectAttributes->configuration.port);
		m_editPort.SetWindowTextA(port.c_str());
	}

	if (!m_connectAttributes->userAccess.m_login.empty() && m_connectAttributes->userAccess.m_login.size() > 0) {
		m_editLogin.SetWindowTextA(m_connectAttributes->userAccess.m_login.c_str());
	}
	if (!m_connectAttributes->userAccess.m_password.empty() && m_connectAttributes->userAccess.m_password.size() > 0) {
		m_editUserPassword.SetWindowTextA(m_connectAttributes->userAccess.m_password.c_str());
	}
	

	m_cmbReadType.SetCurSel(m_dataAttributes->m_iProcessed);
	if (m_dataAttributes->m_iProcessed) {
		ShowDataReadTypeView(TRUE);
		m_cmbAggregateType.SetCurSel(m_dataAttributes->m_pAggregateType.second);
		unsigned int interval = (unsigned int)m_dataAttributes->m_dProcessingInterval;
		SetDlgItemInt(IDC_EDIT_PROCESSING_INTERVAL, interval, FALSE);
	}

	if (!m_dataAttributes->m_vDataQuantities.empty()) {
		std::string quantities;
		for (std::vector<std::string>::const_iterator itr = m_dataAttributes->m_vDataQuantities.cbegin(); itr != m_dataAttributes->m_vDataQuantities.cend(); ++itr) {
			quantities = quantities + *itr + std::string(",");
		}
		quantities.pop_back();
		m_editDataQuality.SetWindowTextA(quantities.c_str());
	}
	return TRUE;
}


void CClientSettingsDialog::SetUpInitialState()
{
	m_pInteractor->SetOutput(shared_from_this());
	m_editPort.SetSel(0, -1);
	m_editPort.Clear();
	m_editLogin.SetSel(0, -1);
	m_editLogin.Clear();
	m_editUserPassword.SetSel(0, -1);
	m_editUserPassword.Clear();
	m_cmbReadType.SetCurSel(0);
	m_cmbAggregateType.ResetContent();
	fillAggregateList();
	m_editProcessingInterval.SetSel(0, -1);
	m_editProcessingInterval.Clear();
	m_editDataQuality.SetSel(0, -1);
	m_editDataQuality.Clear();
	m_spinTimeInterval.SetBuddy(&m_editProcessingInterval);
	ShowDataReadTypeView(FALSE);
}

void CClientSettingsDialog::ShowDataReadTypeView(BOOL bShow)
{
	GetDlgItem(IDC_AGGREGATE_BOX)->ShowWindow(bShow);
	GetDlgItem(IDC_STATIC_AGGREGATE)->ShowWindow(bShow);
	GetDlgItem(IDC_STATIC_INTERVAL)->ShowWindow(bShow);
	GetDlgItem(IDC_STATIC_MS)->ShowWindow(bShow);
	m_cmbAggregateType.ShowWindow(bShow);
	m_editProcessingInterval.ShowWindow(bShow);
	m_spinTimeInterval.ShowWindow(bShow);
}





void CClientSettingsDialog::OnCbnEditChangeComboSelectServer()
{
	if (m_cmbServerName.GetCount() > 0) {
		m_cmbServerName.ResetContent();
	}
	
}

void CClientSettingsDialog::OnCbnSelchangeComboSelectServer()
{
	int curSel = m_cmbServerName.GetCurSel();
	if (curSel > -1) {
		long port = m_cmbServerName.GetItemData(curSel);
		std::string strPort = std::to_string(port);
		m_editPort.SetWindowTextA(strPort.c_str());
	}
	ReadAttributes();
}


void CClientSettingsDialog::OnEnChangeEditPort()
{
	
}


void CClientSettingsDialog::OnBtnClickedButtonBrowseNetwork()
{
	StartLoading();
	m_cmbServerName.ResetContent();
	m_editPort.SetSel(0, -1);
	m_editPort.Clear();
	if (m_pInteractor) {
		m_pInteractor->GetConnectedServers(&(this->m_hWnd));
	}
}


void CClientSettingsDialog::OnBtnClickedButtonDiscoverServers()
{
	StartLoading();
	m_cmbServerName.ResetContent();
	m_editPort.SetSel(0, -1);
	m_editPort.Clear();
	if (m_pInteractor) {
		m_pInteractor->GetAllServers();
	}
}


void CClientSettingsDialog::OnBtnClickedButtonTestConnection()
{
	StartLoading();
	ReadAttributes();
	if (m_pInteractor) {
		m_pInteractor->TestConnection();
	}
}



void CClientSettingsDialog::OnDeltaPosSpinInterval(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	BOOL isGood = FALSE;
	unsigned int res = GetDlgItemInt(IDC_EDIT_PROCESSING_INTERVAL, &isGood, FALSE);
	if (isGood) {
		res -= pNMUpDown->iDelta;
		if (res > 0) {
			SetDlgItemInt(IDC_EDIT_PROCESSING_INTERVAL, res, FALSE);
		}
	}
	*pResult = 0;
}



void CClientSettingsDialog::OnCbnSelChangeComboReadType()
{
	BOOL isProcessed = m_cmbReadType.GetCurSel();
	if (!isProcessed) {
		m_editProcessingInterval.SetSel(0, -1);
		m_editProcessingInterval.Clear();
	}
	ShowDataReadTypeView(isProcessed);
}

void CClientSettingsDialog::OnEnUpdateEditDataQuality()
{
	int selStart = -1;
	int selEnd = -1;
	int res = ::SendMessage(m_editDataQuality.m_hWnd, EM_GETSEL, (WPARAM)(&selStart), (LPARAM)(&selEnd));
	if ((selStart == selEnd) && selStart != 0)
	{
		CString str;
		int len = m_editDataQuality.GetWindowTextLengthA();
		m_editDataQuality.GetWindowTextA(str);
		char currentSymbol = str[selStart - 1];
		bool isNoHex = !_istdigit(currentSymbol) && (currentSymbol != ',') && (currentSymbol != 'x') && (currentSymbol != 'a') && (currentSymbol != 'b') &&
			(currentSymbol != 'c') && (currentSymbol != 'd') && (currentSymbol != 'e') && (currentSymbol != 'f');
		if (isNoHex || ((selStart == 1) && (str[0] != '0')) || ((selStart == 2) && (str[1] != 'x')))
		{
			str.Delete(selStart - 1, 1);
			m_editDataQuality.SetWindowTextA(str);
			::SendMessage(m_editDataQuality.m_hWnd, EM_SETSEL, (WPARAM)(selStart - 1), (LPARAM)(selEnd - 1));
		}
		if (selStart >= 3) {
			if ((currentSymbol == 'x' && str[selStart - 2] != '0') || ((currentSymbol == 'x' && str[selStart - 3] != ',')) || (currentSymbol != '0' && str[selStart - 2] == ',') || (currentSymbol != 'x' && str[selStart - 2] == '0') && str[selStart - 3] == ',') {
				str.Delete(selStart - 1, 1);
				m_editDataQuality.SetWindowTextA(str);
				::SendMessage(m_editDataQuality.m_hWnd, EM_SETSEL, (WPARAM)(selStart - 1), (LPARAM)(selEnd - 1));
			}
		}
	}
}

void CClientSettingsDialog::OnBtnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CClientSettingsDialog::OnBtnClickedOk()
{
	ReadAttributes();
	CDialogEx::OnOK();
}

void CClientSettingsDialog::WarningMessage(std::string message)
{
	MessageBox(TEXT(message.c_str()), "Warning", MB_ICONWARNING);
}

void CClientSettingsDialog::ErrorMessage(std::string message)
{
	MessageBox(TEXT(message.c_str()), "Warning", MB_ICONSTOP);
}


void CClientSettingsDialog::StartLoading()
{
	HCURSOR hCurs = LoadCursor(NULL, IDC_WAIT);
	SetCursor(hCurs);
}

void CClientSettingsDialog::StopLoading()
{
	HCURSOR hCurs = LoadCursor(NULL, IDC_ARROW);
	SetCursor(hCurs);
}

void CClientSettingsDialog::ReadAttributes()
{
	CString str;
	int len = 0;
	int curSel = m_cmbServerName.GetCurSel();
	if (curSel > -1) {
		len = m_cmbServerName.GetLBTextLen(curSel);
		m_cmbServerName.GetLBText(curSel, str);
		m_connectAttributes->configuration.serverName = std::string(str.GetBuffer(len));
		str.ReleaseBuffer();
		str.Empty();
	}
	len = m_editPort.GetWindowTextLengthA();
	m_editPort.GetWindowTextA(str);
	std::string port = std::string(str.GetBuffer(len));
	if (!port.empty()) {
		m_connectAttributes->configuration.port = std::stoul(port);
	}
	str.ReleaseBuffer();
	str.Empty();
	
	len = m_editLogin.GetWindowTextLengthA();
	m_editLogin.GetWindowTextA(str);
	m_connectAttributes->userAccess.m_login = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editUserPassword.GetWindowTextLengthA();
	m_editUserPassword.GetWindowTextA(str);
	m_connectAttributes->userAccess.m_password = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	

	m_dataAttributes->m_iProcessed = m_cmbReadType.GetCurSel();

	if (m_dataAttributes->m_iProcessed) {
		int index = m_cmbAggregateType.GetCurSel();
		int identifier = (int)m_cmbAggregateType.GetItemData(index);
		len = m_cmbAggregateType.GetWindowTextLengthA();
		m_cmbAggregateType.GetWindowTextA(str);
		m_dataAttributes->m_pAggregateType = std::make_pair<std::string, int>(std::string(str.GetBuffer(len)), std::move(identifier));
		str.ReleaseBuffer();
		str.Empty();
		BOOL isGood = FALSE;
		unsigned int res = GetDlgItemInt(IDC_EDIT_PROCESSING_INTERVAL, &isGood, FALSE);
		if (isGood) {
			m_dataAttributes->m_dProcessingInterval = (double)res;
		}
	}
	else {
		m_dataAttributes->m_pAggregateType = std::make_pair<std::string, int>(std::string(), 0);
		m_dataAttributes->m_dProcessingInterval = 0;
	}
	len = m_editDataQuality.GetWindowTextLengthA();
	m_editDataQuality.GetWindowTextA(str);
	std::string quantities = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	m_dataAttributes->m_vDataQuantities.clear();
	std::vector<std::string> quantitiesVec = split(quantities, std::string(","));
	if (!quantitiesVec.empty()) {
		for (std::vector<std::string>::const_iterator itr = quantitiesVec.cbegin(); itr != quantitiesVec.cend(); ++itr) {
			if (itr->empty() == false && itr->size() > 0) {
				m_dataAttributes->m_vDataQuantities.push_back(*itr);
			}
		}
	}
}


void CClientSettingsDialog::fillAggregateList()
{
	int pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_TOTAL);
	m_cmbAggregateType.SetItemData(pos, 0);
	pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_MINIMUM);
	m_cmbAggregateType.SetItemData(pos, 1);
	pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_MAXIMUM);
	m_cmbAggregateType.SetItemData(pos, 2);
	pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_STDEV);
	m_cmbAggregateType.SetItemData(pos, 3);
	pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_RANGE);
	m_cmbAggregateType.SetItemData(pos, 4);
	pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_AVERAGE);
	m_cmbAggregateType.SetItemData(pos, 5);
	pos = m_cmbAggregateType.AddString(OSI_PI_AGGREGATE_MEAN);
	m_cmbAggregateType.SetItemData(pos, 6);
}

void CClientSettingsDialog::SendMessageError(std::string&& message)
{
	StopLoading();
	ErrorMessage(message);
}

void CClientSettingsDialog::SendWarning(std::string&& message)
{
	StopLoading();
	WarningMessage(message);
}

void CClientSettingsDialog::SendMessageInfo(std::string&& message)
{
	StopLoading();
}

void CClientSettingsDialog::GetServers(std::vector<std::pair<std::string, long> >&& servers)
{
	m_cmbServerName.ResetContent();
	m_editPort.SetSel(0, -1);
	m_editPort.Clear();
	for (std::vector<std::pair<std::string, long> >::const_iterator itr = servers.cbegin(); itr != servers.cend(); ++itr)
	{
		int pos = m_cmbServerName.AddString(itr->first.c_str());
		m_cmbServerName.SetItemData(pos, itr->second);
	}
	StopLoading();
}


void CClientSettingsDialog::SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName)
{

	std::string strPort = std::to_string(port);
	m_editPort.SetWindowTextA(strPort.c_str());
	if (m_cmbServerName.GetCount() > 0) {
		m_cmbServerName.SetCurSel(0);
	}
	ReadAttributes();
}

void CClientSettingsDialog::ConnectionOpened(bool isOpenned)
{

}

void CClientSettingsDialog::ConnectionClosed(bool isClosed)
{

}
