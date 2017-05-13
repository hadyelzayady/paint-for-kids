#include "CCircle.h"
#include <cmath>
#include <fstream>
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

void CCircle::Move(int newx, int newy)
{
	Center.x += newx - Center.x;
	Center.y += newy - Center.y;
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
	return pi*pow(Rad, 2);
}

void CCircle::Save(ofstream & OutFile)
{
	//int index	=;
	//int fillColorID = FigGfxInfo.isFilled ? FigGfxInfo.FillClr : -1;
	//OutFile << circ << setw(4) << ID << setw(8) << Center.x << setw(8) << Center.y << setw(8) << Rad
	//	<< setw(8) << pManager->getColorIndex(FigGfxInfo.DrawClr) << setw(8) << pManager->getColorIndex(fillColorID) << endl;
}

void CCircle::Load(ifstream & Infile)
{
	int Drawindex, Fillindex;
	Infile >> ID >> Center.x >> Center.y >> Rad >> Drawindex >> Fillindex;
	FigGfxInfo.DrawClr = colors[Drawindex];
	FigGfxInfo.FillClr = Fillindex != -1 ? colors[Fillindex] : GREEN;
	FigGfxInfo.isFilled = Fillindex == -1 ? false : true;

}
