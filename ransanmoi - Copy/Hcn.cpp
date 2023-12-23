#include "pch.h"
#include "Hcn.h"

void Hcn::draw(CClientDC* pDC)
{
    CPen pen(PS_SOLID, 5 , RGB(250, 0, 0));

    CPen* pOldPen = pDC->SelectObject(&pen);
    pDC->Rectangle(x1, y1, x2, y2);
    pDC->SelectObject(pOldPen);
	
}
