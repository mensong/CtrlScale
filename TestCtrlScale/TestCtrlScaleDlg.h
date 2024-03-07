
// TestCtrlScaleDlg.h: 头文件
//

#pragma once
#include "../CtrlScale.h"

// CTestCtrlScaleDlg 对话框
class CTestCtrlScaleDlg : public CDialogEx
{
// 构造
public:
	CTestCtrlScaleDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCTRLSCALE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	CCtrlScale m_scale;
	void ResetScale();

	void ResetControl();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	CButton m_demoCtrl;
	LONG m_demoCtrlWidth;
	LONG m_demoCtrlHeight;
};
