#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "WidthPallet.h"
WidthPallet::WidthPallet(ApplicationManager*pApp, int x) :Action(pApp)
{
	this->P1.x = x;
	this->P1.y = 54;
	this->P2.x =P1.x+width;// 8 squares in row ,each square with width+margin 1 except last square
	this->P2.y = P1.y;
	this->P2.x = P1.x + 4 * (width + 1) - 1 ;// 8 squares in row ,each square with width+margin 1 except last square
	this->P2.y = P1.y + 4 * (height + 1) - 1;
}
void WidthPallet::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(x, y);
	return;
}
int WidthPallet::getWidth() const
{
	return chosenwidth;
}
bool  WidthPallet::selectWidth()
{
	ReadActionParameters();
	if (x < P2.x && x > P1.x && y > UI.ToolBarHeight && y < P2.y) //if clicked outside option rect ,then remove this rect
	{
		int indexI = (x - P1.x) / (width + 1);// git distance from corner1 then divide it by width of colorRec+1 ; 1 because-> margin; -1 ->arr indexed from 0
		int indexJ = (y - P1.y) / (height + 1);
		int index = indexI + 4 * indexJ;// 8 color per row
		chosenwidth = 3*(index+1);// increasing width by three
		return true;
	}

	return false;
}

void WidthPallet::DrawRect() 
{
	Point tempP1 = P1;
	Point tempP2 = P2;
	Output* pOut = pManager->GetOutput();
	GfxInfo LineGfxInfo;
	LineGfxInfo.BorderWdth = 3;
	LineGfxInfo.DrawClr = BLACK;
	LineGfxInfo.isFilled = false;
	GfxInfo RectGfxInfo;
	RectGfxInfo.BorderWdth = 3;
	RectGfxInfo.DrawClr = BLUE;
	RectGfxInfo.isFilled = false;
	int k = 0;//index of color in the array
	int space = 5;
	int nextWidth,currentWidth;
	int BW = 3;
	for (size_t i = 0; i < 4; i++)//draw rectangles with colors 8 colors per row ,18 row
	{
		tempP2.y = tempP1.y + height;
		for (size_t j = 0; j < 4; j++)
		{
			//draw rect
			tempP2.x = tempP1.x + width; // corner2 of color rect
			k++;
			pOut->DrawRect(tempP1, tempP2, RectGfxInfo);
			//draw line width
			Point Start = {tempP1.x+BW,(tempP1.y+tempP2.y)/2};
			Point End = {tempP2.x-BW,Start.y };
			pOut->DrawLine(Start, End,LineGfxInfo);
			//
			tempP1.x = tempP2.x + 1;// x of next  rect make margin of 1 px
			BW=LineGfxInfo.BorderWdth+=3;
		}
		tempP1.y = tempP2.y + 1;//y1 of next rect ,margin=1px
		tempP1.x = P1.x; // start the next row from original x
	}
}
void WidthPallet::closeRect() const
{
	pManager->GetOutput()->ClearDrawArea();
}
void WidthPallet::Execute()
{
}