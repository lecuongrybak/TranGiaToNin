#pragma once
#include "Hcn.h"
#include "Ran.h"
#include "Moi.h"
#include <iostream>
#define XDAU 50
#define YDAU 50
#define RONG 600



class Banco
{
public:

	int dk, diem;
	int huong;
	int thang;
	Hcn dv;
	Ran ran;
	Moi moi;
	Banco();
	void draw(CClientDC* pDC);
	void capnhathinh(CClientDC* pDC);
	void randichuyen();
	void kiemtrabien();
	void batdau();
	int rananmoi();
	void taomoi();
	void ktdungduoi();
};

