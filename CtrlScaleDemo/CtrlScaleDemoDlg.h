
// CtrlScaleDemoDlg.h: 头文件
//

#pragma once
#include "../CtrlScale.h"

// CCtrlScaleDemoDlg 对话框
class CCtrlScaleDemoDlg : public CDialogEx
{
// 构造
public:
	CCtrlScaleDemoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTRLSCALEDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CCtrlScale m_scale;

};
