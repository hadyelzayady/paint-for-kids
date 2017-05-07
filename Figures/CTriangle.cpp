#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Center.x = (P1.x + P2.x + P3.x) / 3;
	Center.y = (P1.y + P2.y + P3.y) / 3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3 ,FigGfxInfo, Selected);
}
double calcArea(Point p1, Point p2, Point p3)
{
	return abs((p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2.0);
}
bool CTriangle::isPointInFigure(int x, int y)const
{
	double Area1 = calcArea(Point{ x, y }, Corner1, Corner2);
	double Area2 = calcArea(Point{ x, y }, Corner1, Corner3);
	double Area3 = calcArea(Point{ x, y }, Corner3, Corner2);
	double TotalArea = calcArea(Corner1, Corner2, Corner3);
	return  TotalArea == Area1 + Area2 + Area3;
}

CFigure * CTriangle::copy()
{
	return new CTriangle(*this);
}

void CTriangle::Move(int x, int y)
{
	int deltaX = x - Center.x;
	int deltaY = y - Center.y;
	Corner1.x += deltaX;
	Corner1.y += deltaY;
	Corner2.x += deltaX;
	Corner2.y += deltaY;
	Corner3.x += deltaX;
	Corner3.y += deltaY;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
}

void CTriangle::Resize(float)
{
}

Point CTriangle::getCenter() const
{
	return Center;
}

double CTriangle::getArea() const
{
	return abs((Corner1.x*(Corner2.y - Corner3.y) + Corner2.x*(Corner3.y - Corner1.y) + Corner3.x*(Corner1.y - Corner2.y)) / 2.0);
}
