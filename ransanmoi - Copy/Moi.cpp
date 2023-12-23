#include "pch.h"
#include "Moi.h"

void Moi::draw(CClientDC* pDC)
{
	CBrush* newb = new CBrush(RGB(0, 0, 250));
	CBrush* oldb;
	oldb = pDC->SelectObject(newb);
	Tron::draw(pDC);
	pDC->SelectObject(oldb);
}
