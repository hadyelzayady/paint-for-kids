#include "CLine.h"
#include <iomanip>
#include <fstream>
#include <sstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Start = P1.x <P2.x ? P1:P2;
	End = P1.x < P2.x ? P2 : P1;
	Center.x = (Start.x + End.x) / 2;
	Center.y = (Start.y + End.y) / 2;
}

CLine::CLine()
{
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}
bool CLine::Move(int newx, int newy)
{
	int deltax = newx - Center.x;
	int deltay = newy - Center.y;
	Point SStart = Start;
	SStart.x += deltax;
	SStart.y += deltay;
	Point EEnd = End;
	EEnd.x += deltax;
	EEnd.y += deltay;

	if (EEnd.x> UI.width || EEnd.y <UI.ToolBarHeight || EEnd.y > UI.height - UI.StatusBarHeight || SStart.x<0 || SStart.y <UI.ToolBarHeight || SStart.y > UI.height - UI.StatusBarHeight)
		return false;
	End = EEnd;
	Start = SStart;
	Center.x = newx;
	Center.y = newy;
	return true;
}
bool CLine::Resize(float resize)
{
	int tempx, tempy;
	End.x=Start.x + (End.x-Start.x ) * resize;
	End.y =Start.y+ (End.y - Start.y)*resize;
	if (End.x> UI.width || End.y <UI.ToolBarHeight || End.y > UI.height - UI.StatusBarHeight)
		return false;
	return true;
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
	OutFile << lin << setw(4) << ID << setw(8) << Start.x << setw(8) << Start.y << setw(8) << End.x << setw(8) << End.y <<setw(8)<<getcolorIndex(FigGfxInfo.DrawClr)<<setw(8)<<FigGfxInfo.BorderWdth <<endl;
}
void CLine::Load(ifstream & Infile)
{
	int colorindex;
	Infile >> ID >> Start.x >> Start.y >> End.x >> End.y >> colorindex;
	FigGfxInfo.DrawClr = colors[colorindex];
	Infile >> FigGfxInfo.BorderWdth;
	FigGfxInfo.isFilled = false;
	Center.x = (Start.x + End.x) / 2;
	Center.y = (Start.y + End.y) / 2;
}
void CLine::PrintInfo(Output * pOut)
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Start:(" << Start.x << "," << Start.y << ")  End:(" <<End.x <<","<<End.y<< ")  Area:" << getArea();
	pOut->PrintMessage(oss.str());
}
bool CLine::isPointInFigure(int x, int y)const
{
	if (x >= Start.x && x <= End.x && y > min(End.y, Start.y) && y < max(End.y, Start.y))
	{
		float slope = (float)(Start.y - End.y) / (float)(Start.x - End.x);// line eq y=ax+b ;a->slope, b


		float b = Start.y - slope*Start.x;// substitute by point on line to get b
		//get perp line equ
		int x_inter =(x+slope*(y-b))/(pow(slope,2)+1); // inersection point of perp line on my line
		int y_inter = slope*x_inter + b;
		//
		int perpen_distance = sqrt(pow(x - x_inter, 2) + pow(y - y_inter, 2));
		//return y==(int)(slope*x+b);
		return perpen_distance <= UI.PenWidth / 2;
	}
	return false;

}