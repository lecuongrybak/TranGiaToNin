#pragma once
#include "Hinh.h"

class Tron: public Hinh
{
public:
	int r;
	CPoint o;
	Tron() :Hinh() {
		r = 0;
		o.x = 0;
		o.y = 0;
	}
	Tron(int mx1, int my1, int mx2, int my2) :Hinh(mx1, my1, mx2, my2)
	{
		thietlaptam();
	}
	void thietlaptam();
	void draw(CClientDC* pDC);
};

