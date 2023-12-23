#pragma once
#include "Hinh.h"
class Hcn :
    public Hinh
{
public:
    Hcn() :Hinh(){}
    Hcn(int mx1, int my1, int mx2, int my2): Hinh(mx1, my1, mx2, my2){}
    void draw(CClientDC* pDC);
};

