#include "pch.h"
#include "Banco.h"
#include <iostream>
Banco::Banco()
{
	dk = 0;
	diem = 0;
	thang = 0;
	huong = 38;
	dv = Hcn(XDAU, YDAU, XDAU + RONG, YDAU + RONG);
	ran = Ran(XDAU + 10 * D, YDAU + 10 * D);
	moi = Moi(XDAU + 5 * D, YDAU + 10 * D, XDAU + 6 * D, YDAU + 11 * D);

}

void Banco::draw(CClientDC* pDC)
{
	CString strdiem;
	strdiem.Format(_T("Diem: %d   "), diem);
	pDC->TextOutW(XDAU, YDAU / 2, strdiem);
	dv.draw(pDC);
	ran.draw(pDC);
	moi.draw(pDC);
	if (thang == -1)
	{
		CString strkt;
		strkt.Format(_T("GAME OVER!"));
		pDC->TextOutW(XDAU + 10 * D, YDAU + 10 * D, strkt);
	}
}

void Banco::capnhathinh(CClientDC* pDC)
{
	while (dk == 1)
	{
		draw(pDC);
		Sleep(30);
	}
}

void Banco::randichuyen()
{
	while (dk == 1)
	{
		if (huong == 38) 
		{
			ran.goup();
		}
		if (huong == 37) //sang trai
		{
			ran.goleft();
		}
		if (huong == 39) // sang phai
		{
			ran.goright();
		}
		if (huong == 40) // di xuong
		{
			ran.godown();
		}
		rananmoi();
		kiemtrabien();
		ktdungduoi();

		Sleep(200);
	}
}

void Banco::kiemtrabien()
{
	if (ran.dau.y2 <= dv.y1)
	{
		ran.dau.y2 = dv.y2;
		ran.dau.y1 = dv.y2 - D;
	}
	if (ran.dau.x2 <= dv.x1)
	{
		ran.dau.x2 = dv.x2;
		ran.dau.x1 = dv.x2 - D;
	}
	if (ran.dau.x1 >= dv.x2)
	{
		ran.dau.x1 = dv.x1;
		ran.dau.x2 = dv.x1 + D;
	}
	if (ran.dau.y1 >= dv.y2)
	{
		ran.dau.y1 = dv.y1;
		ran.dau.y2 = dv.y1 + D;
	}
}

void Banco::batdau()
{
	dk = 1;
	diem = 0;
}

int Banco::rananmoi()
{
	int mx = (ran.dau.x1 + ran.dau.x2) / 2;
	int my = (ran.dau.y1 + ran.dau.y2) / 2;
	if (moi.kttronghinh(CPoint(mx, my)) == 1)
	{
		diem++;
		ran.tangduoi();//tang 1 pt o duoi
		Sleep(30);
		taomoi();
		return 1;
	}
	else
		return 0;
}

void Banco::taomoi()
{
	int g = RONG / D;
	int r = rand() % g;
	int mx = XDAU + r * D;
	r = rand() % g;
	int my = YDAU + r * D;
	while (mx == moi.x1 && my == moi.x2)
	{
		 r = rand() % g;
		 mx = XDAU + r * D;
		 r = rand() % g;
		 my = YDAU + r * D;
	}
	moi = Moi(mx, my, mx + D, my + D);
}

void Banco::ktdungduoi()
{
	if (ran.ktdaudungduoi() == 1)
	{
		dk = 0;
		thang = -1;
	}
}


