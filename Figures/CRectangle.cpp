#include "CRectangle.h"
#include <cmath>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isPointInFigure(int x, int y)const
{
	return !((Corner1.x - x)*(x - Corner2.x) < 0 || (Corner1.y - y)*(y - Corner2.y) < 0); // eqation of rectangle= sqrt( (a-x)*(x-c) ) * sqrt( (b-y)*(y-d) ) ; where corners are (a,b) (c,d)
}