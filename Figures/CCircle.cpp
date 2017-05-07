#include "CCircle.h"
#include <cmath>
const double  pi = 3.141592653589793238463;
CCircle::CCircle(Point Center, int Rad, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	CircCent = Center;
	Center = CircCent;// remember to determine whicj one to use ,if I will use center in all figures replace CircCent with Center
	this->Rad = Rad;
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

double CCircle::getArea() const
{
	return pi*pow(Rad,2);
}
