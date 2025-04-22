#pragma once
#include <Windows.h>
#include <vector>
#include <map>
#include <set>

typedef struct TAG_CTRLRECT
{
public:
    double dScale[4];//����ֵ

    std::map<DWORD/*AnchorType*/, LONG> offsetAnchor;

    TAG_CTRLRECT()
    {
        dScale[0] = 0;
        dScale[1] = 0;
        dScale[2] = 0;
        dScale[3] = 0;
    }
    TAG_CTRLRECT(const TAG_CTRLRECT& cr)
    {
        *this = cr;
    }
} CTRLRECT;

class CCtrlScale
{
public:
    typedef enum AnchorType
    {
		ProportionalScale       = 0x0,  //����������(Ĭ��)

        AnchorLeftToWinLeft     = 0x1,  //�ؼ�������ڴ�����ľ��벻��
        AnchorLeftToWinRight    = 0x2,  //�ؼ�������ڴ����ҵľ��벻��
        AnchorRightToWinLeft    = 0x4,  //�ؼ�������ڴ�����ľ��벻��
        AnchorRightToWinRight   = 0x8,  //�ؼ�������ڴ����ҵľ��벻��
        AnchorTopToWinTop       = 0x10, //�ؼ�������ڴ��ڶ��ľ��벻��
        AnchorTopToWinBottom    = 0x20, //�ؼ�������ڴ��ڵ׵ľ��벻��
        AnchorBottomToWinTop    = 0x40, //�ؼ�������ڴ��ڶ��ľ��벻��
        AnchorBottomToWinBottom = 0x80, //�ؼ�������ڴ��ڵ׵ľ��벻��
    } AnchorType;

    bool HasAnchorType(DWORD/*CCtrlScale::AnchorType*/ flags, CCtrlScale::AnchorType rectType);

public:
    CCtrlScale(void);
    CCtrlScale(HWND pParentWnd);
    virtual ~CCtrlScale(void);

    void SetAnchor(HWND ctrl, DWORD/*CCtrlScale::AnchorType*/ rectType);
    void AddExclude(HWND ctrl);
    void RemoveExclude(HWND ctrl);

    BOOL Init(HWND pParentWnd);
    
    void Reset();

protected:
    static std::map<HWND, CCtrlScale*> ms_scaleManagers;
    void removeScaleManager();

    WNDPROC m_originalWinProc;
    static LRESULT CALLBACK ParentWinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    void Scale(int cx, int cy);

private:
    HWND m_pParentWnd;
    RECT m_rectWin;

    std::map<HWND, CTRLRECT> m_ctrlRect;//����ؼ�������Ϣ
    std::map<HWND, DWORD> m_ctrlAnchorType;
    std::set<HWND> m_ctrlExclude;
};