
// CtrlScaleDemoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CtrlScaleDemo.h"
#include "CtrlScaleDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCtrlScaleDemoDlg 对话框



CCtrlScaleDemoDlg::CCtrlScaleDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CTRLSCALEDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCtrlScaleDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCtrlScaleDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCtrlScaleDemoDlg 消息处理程序

BOOL CCtrlScaleDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_scale.SetAnchor(GetDlgItem(IDC_CHECK1)->GetSafeHwnd(),
		CCtrlScale::AnchorLeftToWinLeft | 
		CCtrlScale::AnchorRightToWinLeft | 
		CCtrlScale::AnchorTopToWinTop);
	m_scale.SetAnchor(GetDlgItem(IDC_RADIO1)->GetSafeHwnd(),
		CCtrlScale::AnchorLeftToWinLeft | 
		CCtrlScale::AnchorRightToWinLeft);
	m_scale.SetAnchor(GetDlgItem(IDC_STATIC1)->GetSafeHwnd(),
		CCtrlScale::AnchorLeftToWinLeft | 
		CCtrlScale::AnchorRightToWinLeft);
	m_scale.SetAnchor(GetDlgItem(IDC_SYSLINK1)->GetSafeHwnd(),
		CCtrlScale::AnchorLeftToWinLeft | 
		CCtrlScale::AnchorRightToWinLeft);
	m_scale.SetAnchor(GetDlgItem(IDC_EDIT1)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinTop);
	m_scale.SetAnchor(GetDlgItem(IDC_COMBO1)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinTop);
	m_scale.SetAnchor(GetDlgItem(IDC_LIST1)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinTop);
	m_scale.SetAnchor(GetDlgItem(IDC_LIST2)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinTop);
	m_scale.SetAnchor(GetDlgItem(IDC_SCROLLBAR1)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinBottom | 
		CCtrlScale::AnchorBottomToWinBottom | 
		CCtrlScale::AnchorLeftToWinLeft | 
		CCtrlScale::AnchorRightToWinRight);
	m_scale.SetAnchor(GetDlgItem(IDC_SCROLLBAR2)->GetSafeHwnd(),
		CCtrlScale::AnchorLeftToWinRight | 
		CCtrlScale::AnchorRightToWinRight | 
		CCtrlScale::AnchorTopToWinTop | 
		CCtrlScale::AnchorBottomToWinBottom);
	m_scale.SetAnchor(GetDlgItem(IDCANCEL)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinBottom | 
		CCtrlScale::AnchorBottomToWinBottom);
	m_scale.SetAnchor(GetDlgItem(IDOK)->GetSafeHwnd(),
		CCtrlScale::AnchorTopToWinBottom | 
		CCtrlScale::AnchorBottomToWinBottom);
	m_scale.Init(m_hWnd);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCtrlScaleDemoDlg::OnPaint()
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
HCURSOR CCtrlScaleDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

