#include "CFigure.h"
unsigned int CFigure::IDcounter = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = ++IDcounter;
}

CFigure::CFigure()
{
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
int CFigure::getcolorIndex(color cl)
{
	for (size_t i = 0; i < 144; i++)
	{
		if (cl == colors[i])
			return i;
	}
	return 0;
}
void CFigure::setCenter(int x,int y)
{
	Center.x = x;
	Center.y = y;
}

Point CFigure::getCenter() const
{
	return Center;
}



void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::chngIsFilled(bool isfilled)
{
	FigGfxInfo.isFilled = isfilled;
}

void CFigure::chngBorderWidth(int wid)
{
	FigGfxInfo.BorderWdth = wid;
}

GfxInfo CFigure::getGfxInfo() const
{
	return FigGfxInfo;
}

