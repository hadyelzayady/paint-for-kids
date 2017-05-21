#include "CTriangle.h"
#include <iomanip>
#include <fstream>
#include <sstream>
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Center.x = (P1.x + P2.x + P3.x) / 3;
	Center.y = (P1.y + P2.y + P3.y) / 3;
}

CTriangle::CTriangle()
{
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

bool CTriangle::Move(int x, int y)
{
	int deltaX = x - Center.x;
	int deltaY = y - Center.y;
	Point CCorner1 = Corner1;
	CCorner1.x += deltaX;
	CCorner1.y += deltaY;
	Point CCorner2 = Corner2;
	CCorner2.x += deltaX;
	CCorner2.y += deltaY;
	Point CCorner3 = Corner3;
	CCorner3.x += deltaX;
	CCorner3.y += deltaY;
	if (CCorner1.x > UI.width || CCorner2.x > UI.width || CCorner3.x > UI.width || CCorner1.x < 0 || CCorner2.x < 0 || CCorner3.x < 0 || CCorner1.y <UI.ToolBarHeight || CCorner2.y <UI.ToolBarHeight|| CCorner3.y <UI.ToolBarHeight || CCorner1.y >UI.height - UI.ToolBarHeight || CCorner2.y >UI.height - UI.ToolBarHeight || CCorner3.y >UI.height - UI.ToolBarHeight)
		return false;
	Corner1 = CCorner1;
	Corner2 = CCorner2;
	Corner3 = CCorner3;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return true;
}
bool operator==(Point const& lhs, Point const& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool CTriangle::Resize(float rs)
{
	//get minx point
	Point* central = Corner1.x < Corner2.x ? &Corner1 : &Corner2;
	Point* P1 = *central == Corner1 ? &Corner2 : &Corner1;
	Point* P2 = Corner3.x > central->x ? &Corner3 : central;
	central = Corner3.x < central->x ? &Corner3 : central;
	Point P1new,P2new;
	//
	//get next P1;
	double vx = P1->x - central->x;
	double vy = P1->y - central->y;
	double length = sqrt(vx*vx + vy*vy);
	double addedDist = length*rs - length;
	//get unit vector vx,vy
	vx /= length;
	vy /= length;
	//addedDist = rs < 1 ? -1 * addedDist : addedDist;
	P1new.x = P1->x + vx*addedDist;
	P1new.y = P1->y+vy*addedDist;
	//get next P2;
	vx = P2->x - central->x;
	vy = P2->y - central->y;
	length = sqrt(vx*vx+vy*vy);
	addedDist = length*rs - length;
	//get unit vector 
	vx /= length;
	vy /= length;
	//addedDist = rs < 1 ? -1 * addedDist : addedDist;
	P2new.x = P2->x + vx*addedDist;
	P2new.y = P2->y + vy*addedDist;
	//
	*P2 = P2new;
	*P1 = P1new;
	if (P1new.x > UI.width || P2new.x > UI.width || P1new.x < 0 || P2new.x < 0 || P1new.y <UI.ToolBarHeight || P2new.y <UI.ToolBarHeight || P1new.y >UI.height - UI.ToolBarHeight || P2new.y >UI.height - UI.ToolBarHeight)
		return false;
	return true;
}

Point CTriangle::getCenter() const
{
	return Center;
}

void CTriangle::Save(ofstream & OutFile)
{
	int fillColorindex = FigGfxInfo.isFilled ? getcolorIndex(FigGfxInfo.FillClr) : -1;
	OutFile << tri << setw(4) << ID << setw(8) << Corner1.x << setw(8) << Corner1.y << setw(8) << Corner2.x << setw(8) << Corner2.y
		<< setw(8) << Corner3.x << setw(8) << Corner3.y <<setw(8)<<getcolorIndex(FigGfxInfo.DrawClr)<<setw(8)<<fillColorindex<<setw(8)<<FigGfxInfo.BorderWdth <<endl;
}

void CTriangle::Load(ifstream & Infile)
{
	int colorindex;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> colorindex;
	FigGfxInfo.DrawClr = colors[colorindex];
	Infile>>colorindex;
	FigGfxInfo.FillClr = colorindex != -1 ? colors[colorindex] : UI.FillColor;
	FigGfxInfo.isFilled = colorindex != -1 ? true : false;
	Infile >> FigGfxInfo.BorderWdth;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
}

double CTriangle::getArea() const
{
	return abs((Corner1.x*(Corner2.y - Corner3.y) + Corner2.x*(Corner3.y - Corner1.y) + Corner3.x*(Corner1.y - Corner2.y)) / 2.0);
}

void CTriangle::PrintInfo(Output * pOut)
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Corner3:(" << Corner3.x << "," << Corner3.y << ")  Area:" << getArea();
	pOut->PrintMessage(oss.str());
}
