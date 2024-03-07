#pragma once
#include <vector>
#include <map>

typedef struct TAG_CTRLRECT
{
public:
    int nId;//�ؼ�ID
    double dScale[4];//����ֵ

    std::map<DWORD/*RectType*/, LONG> offsetAnchor;

    TAG_CTRLRECT()
    {
        nId = 0;//δ����
        dScale[0] = 0;
        dScale[1] = 0;
        dScale[2] = 0;
        dScale[3] = 0;
    }
    TAG_CTRLRECT(const TAG_CTRLRECT& cr)
    {
        *this = cr;
    }
    bool operator () (const TAG_CTRLRECT& cr)
    {
        return (cr.nId == nId);
    }
} CTRLRECT;

class CCtrlScale
{
public:
    typedef enum RectType
    {
		ProportionalScale = 0b0,    //����������(Ĭ��)

        AnchorLeftToWinLeft     = 0b1,       //�ؼ�������ڴ�����ľ��벻��
        AnchorLeftToWinRight    = 0b10,      //�ؼ�������ڴ����ҵľ��벻��
        AnchorRightToWinLeft    = 0b100,     //�ؼ�������ڴ�����ľ��벻��
        AnchorRightToWinRight   = 0b1000,    //�ؼ�������ڴ����ҵľ��벻��
        AnchorTopToWinTop       = 0b10000,   //�ؼ�������ڴ��ڶ��ľ��벻��
        AnchorTopToWinBottom    = 0b100000,  //�ؼ�������ڴ��ڵ׵ľ��벻��
        AnchorBottomToWinTop    = 0b1000000, //�ؼ�������ڴ��ڶ��ľ��벻��
        AnchorBottomToWinBottom = 0b10000000,//�ؼ�������ڴ��ڵ׵ľ��벻��
    } RectType;

    bool HasRectType(DWORD/*CCtrlScale::RectType*/ flags, CCtrlScale::RectType rectType);

public:
    CCtrlScale(void);
    CCtrlScale(HWND pParentWnd);
    virtual ~CCtrlScale(void);

    void SetAnchor(int ctrlId, DWORD/*CCtrlScale::RectType*/ rectType);
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

    std::vector<CTRLRECT> m_vecCtrl;//����ؼ�������Ϣ
    std::map<int, DWORD> m_ctrlRectType;
};