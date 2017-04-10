#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
	//Center=
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}
void CLine::Move(int newx, int newy)
{
}
CFigure * CLine::copy()
{
	return nullptr;
}
bool CLine::isPointInFigure(int x, int y)const
{
	float slope = (float)(Start.y - End.y) / (float)(Start.x - End.x);// line eq y=ax+b ;a->slope, b
	float b =Start.y - slope*Start.x;// substitute by point on line to get b
	return y==(int)(slope*x+b);
}