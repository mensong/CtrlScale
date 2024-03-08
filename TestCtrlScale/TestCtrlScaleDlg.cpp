
// TestCtrlScaleDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "TestCtrlScale.h"
#include "TestCtrlScaleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestCtrlScaleDlg 对话框



CTestCtrlScaleDlg::CTestCtrlScaleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTCTRLSCALE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestCtrlScaleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_demoCtrl);
}

void CTestCtrlScaleDlg::ResetScale()
{
	m_scale.Reset();
	ResetControl();

	CButton* pbtn = (CButton*)GetDlgItem(IDC_CHECK1);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorLeftToWinLeft);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK2);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorLeftToWinRight);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK3);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorRightToWinLeft);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK4);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorRightToWinRight);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK5);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorTopToWinTop);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK6);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorTopToWinBottom);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK7);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorBottomToWinTop);
	pbtn = (CButton*)GetDlgItem(IDC_CHECK8);
	if (pbtn->GetCheck())
		m_scale.SetAnchor(m_demoCtrl.GetDlgCtrlID(), CCtrlScale::AnchorBottomToWinBottom);
}

void CTestCtrlScaleDlg::ResetControl()
{
	CRect rectWin;
	this->GetClientRect(&rectWin);
	
	CRect rectDemo;
	rectDemo.left = (rectWin.Width() - m_demoCtrlWidth) / 2;
	rectDemo.right = rectDemo.left + m_demoCtrlWidth;
	rectDemo.top = (rectWin.Height() - m_demoCtrlHeight) / 2;
	rectDemo.bottom = rectDemo.top + m_demoCtrlHeight;

	m_demoCtrl.MoveWindow(rectDemo);

	m_scale.AddExclude(IDC_CHECK1);
	m_scale.AddExclude(IDC_CHECK2);
	m_scale.AddExclude(IDC_CHECK3);
	m_scale.AddExclude(IDC_CHECK4);
	m_scale.AddExclude(IDC_CHECK5);
	m_scale.AddExclude(IDC_CHECK6);
	m_scale.AddExclude(IDC_CHECK7);
	m_scale.AddExclude(IDC_CHECK8);
}

BEGIN_MESSAGE_MAP(CTestCtrlScaleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestCtrlScaleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CTestCtrlScaleDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTestCtrlScaleDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CTestCtrlScaleDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CTestCtrlScaleDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CTestCtrlScaleDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CTestCtrlScaleDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CTestCtrlScaleDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CTestCtrlScaleDlg::OnBnClickedCheck8)
END_MESSAGE_MAP()


// CTestCtrlScaleDlg 消息处理程序

BOOL CTestCtrlScaleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_scale.Init(m_hWnd);

	CRect rectDemo;
	m_demoCtrl.GetWindowRect(&rectDemo);
	m_demoCtrlWidth = rectDemo.Width();
	m_demoCtrlHeight = rectDemo.Height();

	ResetControl();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestCtrlScaleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestCtrlScaleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestCtrlScaleDlg::OnBnClickedButton1()
{
	
}


void CTestCtrlScaleDlg::OnBnClickedCheck1()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck2()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck3()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck4()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck5()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck6()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck7()
{
	ResetScale();
}


void CTestCtrlScaleDlg::OnBnClickedCheck8()
{
	ResetScale();
}
