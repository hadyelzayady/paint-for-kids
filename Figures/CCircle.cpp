#include "CCircle.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
const double  pi = 3.141592653589793238463;
CCircle::CCircle(Point Centerpt, int Rad, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = Centerpt;// remember to determine whicj one to use ,if I will use center in all figures replaceCenter with Center
	this->Rad = Rad;
}

CCircle::CCircle()
{
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCirc(Center, Rad, FigGfxInfo, Selected);
}

bool CCircle::isPointInFigure(int x, int y)const
{
	return pow(x - Center.x, 2) + pow(y - Center.y, 2) <= pow(Rad, 2);
}

bool CCircle::Move(int newx, int newy)
{
	if (newx - Rad <0 || newy + Rad >UI.height - UI.StatusBarHeight || newx + Rad>UI.width || newy - Rad<UI.ToolBarHeight)
		return false;
	Center.x = newx;
	Center.y = newy;
	return true;
}

bool CCircle::Resize(float resize)
{
	Rad*= resize;
	if (Center.y - Rad <UI.ToolBarHeight || Center.y + Rad >UI.height - UI.StatusBarHeight || Center.x - Rad<0 || Center.x + Rad>UI.width)
		return false;
	return true;
}

CFigure * CCircle::copy()
{
	return new CCircle(*this);
}

double CCircle::getArea() const
{
	return pi*pow(Rad, 2);
}

void CCircle::Save(ofstream & OutFile)
{
	int fillColorindex = FigGfxInfo.isFilled ? getcolorIndex(FigGfxInfo.FillClr) : -1;
	OutFile << circ << setw(4) << ID << setw(8) << Center.x << setw(8) << Center.y << setw(8) << Rad
		<< setw(8) << getcolorIndex(FigGfxInfo.DrawClr) << setw(8) <<fillColorindex<<setw(8)<<FigGfxInfo.BorderWdth << endl;
}

void CCircle::Load(ifstream & Infile)
{
	int Drawindex, Fillindex;
	Infile >> ID >> Center.x >> Center.y >> Rad >> Drawindex >> Fillindex;
	FigGfxInfo.DrawClr = colors[Drawindex];
	FigGfxInfo.FillClr = Fillindex != -1 ? colors[Fillindex] : UI.FillColor;
	FigGfxInfo.isFilled = Fillindex == -1 ? false : true;
	Infile >> FigGfxInfo.BorderWdth;

}

void CCircle::PrintInfo(Output * pOut)
{
	ostringstream oss;
	oss<< "ID:" << ID << "\t Center:(" << Center.x << "," << Center.y << ")  Rad:" << Rad << "  Area:" << getArea();
	pOut->PrintMessage(oss.str());
}
