#pragma once
#include "Hcn.h"
#include "Tron.h"
#define D 30

class Ran
{
public:
	int sethem;
	int n;
	Hcn dau;
	Tron duoi[100];
	Ran();
	Ran(int mx, int my);
	void draw(CClientDC* pDC);
	void goleft();
	void goright();
	void goup();
	void godown();
	void doicho();
	void tangduoi();
	int ktdaudungduoi();
	
};

