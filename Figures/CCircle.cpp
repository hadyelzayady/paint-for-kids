#include "CCircle.h"
#include <cmath>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	CircCent = P1;
	Center = CircCent;// remember to determine whicj one to use ,if I will use center in all figures replace CircCent with Center
	Rad = (int)sqrt(pow(P1.x - P2.x, 2)+pow(P1.y-P2.y,2));
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCirc(CircCent, Rad, FigGfxInfo,Selected);
}

bool CCircle::isPointInFigure(int x, int y)const
{
	return pow(x - CircCent.x, 2) + pow(y - CircCent.y, 2) <= pow(Rad, 2);
}

void CCircle::Move(int newx, int newy)
{
	CircCent.x += newx - CircCent.x;
	CircCent.y += newy - CircCent.y;
}

void CCircle::Resize(float resize)
{
	Rad *= resize;
}

CFigure * CCircle::copy()
{
	return new CCircle(*this);
}
