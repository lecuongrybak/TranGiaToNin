
// ransanmoiView.cpp : implementation of the CransanmoiView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ransanmoi.h"
#endif

#include "ransanmoiDoc.h"
#include "ransanmoiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CransanmoiView

IMPLEMENT_DYNCREATE(CransanmoiView, CView)

BEGIN_MESSAGE_MAP(CransanmoiView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CransanmoiView construction/destruction

CransanmoiView::CransanmoiView() noexcept
{ 
	banco = Banco();
	// TODO: add construction code here

}

CransanmoiView::~CransanmoiView()
{
}

BOOL CransanmoiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CransanmoiView drawing

void CransanmoiView::OnDraw(CDC* /*pDC*/)
{
	CransanmoiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	banco.draw(&pDC);
	// TODO: add draw code for native data here
}

void CransanmoiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CransanmoiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CransanmoiView diagnostics

#ifdef _DEBUG
void CransanmoiView::AssertValid() const
{
	CView::AssertValid();
}

void CransanmoiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CransanmoiDoc* CransanmoiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CransanmoiDoc)));
	return (CransanmoiDoc*)m_pDocument;
}
#endif //_DEBUG


// CransanmoiView message handlers


void CransanmoiView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (banco.dk == 0 && nChar == 32)
	{
		batdaugame();
	}
	if (banco.dk == 1 && nChar >= 37 && nChar <= 40)
	{
		banco.huong = nChar;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

UINT randichuyen(LPVOID nparam)
{
	CransanmoiView* cview = (CransanmoiView*)nparam;
	cview->banco.randichuyen();
	return 0;
}

UINT capnhathinh(LPVOID nparam)
{
	CransanmoiView* cview = (CransanmoiView*)nparam;
	CClientDC pDC(cview);
	cview->banco.capnhathinh(&pDC);
	return 0;
}

int CransanmoiView::batdaugame()
{
	banco.batdau();
	AfxBeginThread(randichuyen, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(capnhathinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return 0;
	// TODO: Add your implementation code here.
}
