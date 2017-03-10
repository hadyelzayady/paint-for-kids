#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp){}

void ChangeFillColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	pIn->GetPointClicked(x, y);// get choosed color or delete selection rect
	if (x < P2.x && x > P1.x && y > UI.ToolBarHeight && y < P2.y) //if clicked outside option rect ,then remove this rect
	{
		int indexI = (x - P1.x)/(width+1);// git distance from corner1 then divide it by width of colorRec+1 ; 1 because-> margin; -1 ->arr indexed from 0
		int indexJ = (y - P1.y) / (height + 1);
		int index = indexI + 8*indexJ;// 8 color per row
		UI.FillColor = colors[index];
	}
	// delete colors rectangle
	P1.y = UI.ToolBarHeight + 4;// 
	RectGfxInfo.BorderWdth = 0;
	RectGfxInfo.DrawClr = UI.BkGrndColor;
	RectGfxInfo.isFilled = true;
	RectGfxInfo.FillClr = UI.BkGrndColor;
	pOut->DrawRect(P2, P1, RectGfxInfo);
	return;


	pOut->ClearStatusBar();
}

void ChangeFillColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	P1.x = 319;
	P1.y= UI.ToolBarHeight+4;// 3-> width of toolbar border 54
	RectGfxInfo.BorderWdth = 0;
	RectGfxInfo.DrawClr = NONE;
	RectGfxInfo.isFilled = true;
	int k = 0;//index of color in the array
	for (size_t i = 0; i < 18; i++)//draw rectangles with colors 8 colors per row ,18 row
	{
		P2.y = P1.y + height;
		for (size_t j = 0; j < 8; j++)
		{
			P2.x = P1.x + width; // corner2 of color rect
			RectGfxInfo.FillClr = colors[k];
			k++;
			pOut->DrawRect(P1, P2, RectGfxInfo);
			P1.x = P2.x + 1;// x of next color rect make margin of 1 px
		}
		P1.y = P2.y + 1;//y1 of next rect ,margin=1px
		P1.x = 319;
	}
	//set the borders of the overall rectangle of all colors
	P1.y = UI.ToolBarHeight + 4;// other coord is adjusted
	//This action needs to choose color
	ReadActionParameters();

}