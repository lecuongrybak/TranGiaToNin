#include "pch.h"
#include "Ran.h"

Ran::Ran()
{
	sethem = 0;
	int mx = 0;
	int my = 0;
	n = 1;
	dau = Hcn(mx, my, mx + D, my + D);
	duoi[0] = Tron(dau.x1, dau.y2, dau.x1 + D, dau.y2 + D);
}

Ran::Ran(int mx, int my)
{
	sethem = 0;
	n = 1;
	dau = Hcn(mx, my, mx + D, my + D);
	duoi[0] = Tron(dau.x1, dau.y2, dau.x1 + D, dau.y2 + D);
}

void Ran::draw(CClientDC* pDC)
{
	dau.draw(pDC);
	for (int i = 0; i < n; i++)
	{
		duoi[i].draw(pDC);
	}
}

void Ran::goleft()
{
	doicho();
	dau.goLeft(D);
}

void Ran::goright()
{
	doicho();
	dau.goRight(D);
}

void Ran::goup()
{
	doicho();
	dau.goUp(D);
}

void Ran::godown()
{
	doicho();
	dau.goDown(D);
}

void Ran::doicho()
{
	if (sethem == 1)
	{
		n++;
		sethem = 0;
	}
	for (int i = n - 1; i > 0 ; i--)
	{
		duoi[i].x1 = duoi[i - 1].x1;
		duoi[i].y1 = duoi[i - 1].y1;
		duoi[i].x2 = duoi[i - 1].x2;
		duoi[i].y2 = duoi[i - 1].y2;
		duoi[i].thietlaptam();
	}
	duoi[0].x1 = dau.x1;
	duoi[0].y1 = dau.y1;
	duoi[0].x2 = dau.x2;
	duoi[0].y2 = dau.y2;
	duoi[0].thietlaptam();
}

void Ran::tangduoi()
{
	sethem = 1;
}

int Ran::ktdaudungduoi()
{
	int mx = (dau.x1 + dau.x2)/2;
	int my = (dau.y1 + dau.y2) / 2;
	CPoint p = CPoint(mx, my);
	for (int i = 0; i < n; i++)
	{
		if (duoi[i].kttronghinh(p) == 1)
		{
			return 1;
		}
	}
	return 0;
}



