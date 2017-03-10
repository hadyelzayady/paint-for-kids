#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "ColorRectangle.h"
ColorRectangle::ColorRectangle(ApplicationManager*pApp,Point P1) :Action(pApp)
{
	this->P1 = P1;
	this->P2.x = P1.x+8*(width+1)-1;// 8 squares in row ,each square with width+margin 1 except last square
	this->P2.y = P1.y + 18 * (height + 1) - 1;
}
void ColorRectangle::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(x, y);
	selectColor();
	return;
}
color ColorRectangle::getcolor()const {
	return chosenColor;
}
void  ColorRectangle::selectColor()
{

	if (x < P2.x && x > P1.x && y > UI.ToolBarHeight && y < P2.y) //if clicked outside option rect ,then remove this rect
	{
		int indexI = (x - P1.x) / (width + 1);// git distance from corner1 then divide it by width of colorRec+1 ; 1 because-> margin; -1 ->arr indexed from 0
		int indexJ = (y - P1.y) / (height + 1);
		int index = indexI + 8 * indexJ;// 8 color per row
		chosenColor= colors[index];
		return;
	}
	chosenColor = UI.FillColor;
	return;
}
void ColorRectangle::DrawRect() const
{
	Output* pOut = pManager->GetOutput();
	GfxInfo RectGfxInfo;
	RectGfxInfo.BorderWdth = 0;
	RectGfxInfo.DrawClr = NONE;
	RectGfxInfo.isFilled = true;
	Point tempP1 = P1;// to keep the values of p1,p1
	Point tempP2 = P2;
	int k = 0;//index of color in the array
	for (size_t i = 0; i < 18; i++)//draw rectangles with colors 8 colors per row ,18 row
	{
		tempP2.y = tempP1.y + height;
		for (size_t j = 0; j < 8; j++)
		{
			tempP2.x = tempP1.x + width; // corner2 of color rect
			RectGfxInfo.FillClr = colors[k];
			k++;
			pOut->DrawRect(tempP1, tempP2, RectGfxInfo);
			tempP1.x = tempP2.x + 1;// x of next color rect make margin of 1 px
		}
		tempP1.y = tempP2.y + 1;//y1 of next rect ,margin=1px
		tempP1.x = P1.x; // start the next row from original x
	}
}
void ColorRectangle::closeRect() const
{ 
	GfxInfo RectGfxInfo;
	RectGfxInfo.BorderWdth = 0;
	RectGfxInfo.DrawClr = UI.BkGrndColor;
	RectGfxInfo.isFilled = true;
	RectGfxInfo.FillClr = UI.BkGrndColor;
	pManager->GetOutput()->DrawRect(P2, P1, RectGfxInfo);
}
void ColorRectangle::Execute()
{
	DrawRect();
	ReadActionParameters();
	closeRect();
}