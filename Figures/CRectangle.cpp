#include "CRectangle.h"
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
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

CRectangle::CRectangle()
{
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

bool CRectangle::Move(int newx, int newy)
{
	int deltaX = newx - Center.x;
	int deltaY = newy - Center.y;

	Point CCorner1 = Corner1;
	CCorner1.x += deltaX;
	CCorner1.y += deltaY;
	Point CCorner2 = Corner2;
	CCorner2.x += deltaX;
	CCorner2.y += deltaY;
	if (CCorner2.x > UI.width-15 || CCorner1.x < 0 || CCorner1.y <UI.ToolBarHeight || CCorner2.y >UI.height - UI.ToolBarHeight)
		return false;
	Center = { newx,newy };
	Corner1 = CCorner1;
	Corner2 = CCorner2;
	return true;
}
bool CRectangle::Resize(float resize)
{
	int width = Corner2.x - Corner1.x;
	int height = Corner2.y - Corner1.y;
	Corner2.x = Corner1.x + width*resize;
	Corner2.y = Corner1.y + height*resize;
	if (Corner2.x > UI.width-15 || Corner1.x < 0 || Corner1.y <UI.ToolBarHeight || Corner2.y >UI.height - UI.ToolBarHeight)
		return false;
	return true;

}
CFigure * CRectangle::copy()	
{
	return new CRectangle(*this);
}

void CRectangle::Save(ofstream & OutFile)
{
	int fillColorindex = FigGfxInfo.isFilled ? getcolorIndex(FigGfxInfo.FillClr) : -1;
	OutFile << rect << setw(4) << ID << setw(8) << Corner1.x << setw(8) << Corner1.y << setw(8) << Corner2.x << setw(8) << Corner2.y <<setw(8)<<getcolorIndex(FigGfxInfo.DrawClr)<<setw(8)<<fillColorindex<<setw(8)<<FigGfxInfo.BorderWdth<< endl;
}

void CRectangle::Load(ifstream & Infile)
{
	int colorindex;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> colorindex;
	FigGfxInfo.DrawClr = colors[colorindex];
	Infile >> colorindex;//fill
	FigGfxInfo.FillClr = colorindex != -1 ? colors[colorindex] : UI.FillColor;
	FigGfxInfo.isFilled = colorindex != -1 ? true : false;
	Infile >> FigGfxInfo.BorderWdth;
	//get the center
	int width = abs(Corner1.x - Corner2.x);
	int height = abs(Corner1.y - Corner2.y);
	Center.x = min(Corner1.x, Corner2.x) + width / 2;
	Center.y = min(Corner1.y, Corner2.y) + height / 2;
}

void CRectangle::PrintInfo(Output * pOut)
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x <<","<<Corner2.y <<")  Area:" << getArea()<<" Height: "
		<<abs(Corner1.y-Corner2.y)<<" Width:"<<abs(Corner1.x-Corner2.x);
	pOut->PrintMessage(oss.str());
}

double CRectangle::getArea() const
{
	return abs((Corner2.x-Corner1.x)*(Corner2.y-Corner1.y));
}
