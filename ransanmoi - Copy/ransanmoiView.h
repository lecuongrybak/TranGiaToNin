
// ransanmoiView.h : interface of the CransanmoiView class
//

#pragma once
#include "Banco.h"

class CransanmoiView : public CView
{
protected: // create from serialization only
	CransanmoiView() noexcept;
	DECLARE_DYNCREATE(CransanmoiView)

// Attributes
public:
	CransanmoiDoc* GetDocument() const;

// Operations
public:
	Banco banco;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CransanmoiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int batdaugame();
};

#ifndef _DEBUG  // debug version in ransanmoiView.cpp
inline CransanmoiDoc* CransanmoiView::GetDocument() const
   { return reinterpret_cast<CransanmoiDoc*>(m_pDocument); }
#endif

