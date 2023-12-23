#pragma once
class Hinh
{
public:
	int x1, y1, x2, y2;
	Hinh() 
	{
		x1 = 0;
		x2 = 0;
		y1 = 0;
		y2 = 0;
	}
	Hinh(int mx1, int my1, int mx2, int my2) {
		x1 = mx1;
		y1 = my1;
		x2 = mx2;
		y2 = my2;
	}
	void virtual draw(CClientDC* pDC)
	{
		return;
	}
	void virtual goRight(int md) {
		x1 = x1 + md;
		x2 = x2 + md;
	}
	void virtual goLeft(int md) {
		x1 = x1 - md;
		x2 = x2 - md;
	}
	void virtual goUp(int md) {
		y1 = y1 - md;
		y2 = y2 - md;
	}
	void virtual goDown(int md) {
		y1 = y1 + md;
		y2 = y1 + md;
	};
	int  virtual kttronghinh(CPoint p)
	{
		if (p.x > x1 && p.x < x2 && p.y > y1 && p.y < y2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

