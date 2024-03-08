CtrlScale
===========================

自动对窗口的子控件进行排序

****

## 用法

1.设置子控件的四边锚类型（可选）

```C++
//设置按钮相对于窗口的右下角位置不变，其它没有设置锚类型的子控件则按照比例缩放
m_scale.SetAnchor(IDOK,
  CCtrlScale::AnchorLeftToWinRight |
  CCtrlScale::AnchorRightToWinRight |
  CCtrlScale::AnchorTopToWinBottom |
  CCtrlScale::AnchorBottomToWinBottom);
```

2.设置忽略子控件（可选）

```C++
//设置忽略按钮
m_scale.AddExclude(IDCANCEL);
```

3.初始化

```C++
m_scale.Init(m_hWnd);
```
