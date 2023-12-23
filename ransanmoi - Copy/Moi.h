#pragma once
#include "Tron.h"
class Moi :
    public Tron
{
public:
   Moi() :Tron(){}
   Moi(int mx1, int my1, int mx2, int my2) :Tron(mx1, my1, mx2, my2){}
   void draw(CClientDC* pDC);
};

