#include "CLine.h"
#include <iomanip>
#include <fstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
	//Center=
}

CLine::CLine()
{
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}
void CLine::Move(int newx, int newy)
{
}
void CLine::Resize(float resize)
{
	End.x = (Start.x + End.x) * resize;
	End.y = (Start.y + End.y) * resize;
}
CFigure * CLine::copy()
{
	return new CLine(*this);
}
double CLine::getArea() const
{
	return sqrt( pow(End.x-Start.x,2) +pow(End.y-Start.y,2));
}
void CLine::Save(ofstream & OutFile)
{
	OutFile << lin << setw(4) << ID << setw(8) << Start.x << setw(8) << Start.y << setw(8) << End.x << setw(8) << End.y <<setw(8)<<FigGfxInfo.DrawClr.getID()<< endl;
}
void CLine::Load(ifstream & Infile)
{
}
bool CLine::isPointInFigure(int x, int y)const
{
	float slope = (float)(Start.y - End.y) / (float)(Start.x - End.x);// line eq y=ax+b ;a->slope, b
	float b =Start.y - slope*Start.x;// substitute by point on line to get b
	return y==(int)(slope*x+b);
}