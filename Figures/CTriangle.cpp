#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
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
	return nullptr;
}

void CTriangle::Move(int x, int y)
{
}

void CTriangle::Resize(float)
{
}
