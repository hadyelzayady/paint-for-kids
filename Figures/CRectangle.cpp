#include "CRectangle.h"
#include <cmath>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1.x < P2.x ? P1 : P2;
	Corner2 = P1.x > P2.x ? P1 : P2;
	//get the center
	int width = abs(P1.x - P2.x);
	int height = abs(P1.y - P2.y);
	Center.x = min(P1.x, P2.x)+width/2;
	Center.y = min(P1.y, P2.y) + height / 2;
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

void CRectangle::Move(int newx, int newy)
{
	int deltaX = newx - Center.x;
	int deltaY = newy - Center.y;
	Center = { newx,newy };
	Corner1.x += deltaX;
	Corner1.y += deltaY;
	Corner2.x += deltaX;
	Corner2.y += deltaY;
}
void CRectangle::Resize(float resize)
{
	int width = Corner1.x - Corner1.x;
	int height = Corner1.y - Corner1.y;
	Corner2.x = Corner1.x + width*resize;
	Corner2.y = (Corner1.y + Corner2.y)*resize;
}
CFigure * CRectangle::copy()
{
	return new CRectangle(*this);
}
