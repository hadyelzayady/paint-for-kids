#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "ColorRectangle.h"
ColorRectangle::ColorRectangle(ApplicationManager*pApp,int x) :Action(pApp)
{
	this->P1.x = x;
	this->P1.y = 54;
	this->P2.x = P1.x+8*(width+1)-1+10;// 8 squares in row ,each square with width+margin 1 except last square
	this->P2.y = P1.y + 18 * (height + 1) - 1;
}
void ColorRectangle::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(x, y);
	return;
}
color ColorRectangle::getcolor() const
{
	return chosencolor;
}
bool  ColorRectangle::selectColor()
{
	ReadActionParameters();
	if (x < P2.x && x > P1.x && y > UI.ToolBarHeight && y < P2.y) //if clicked outside option rect ,then remove this rect
	{
		int indexI = (x - P1.x) / (width + 1);// git distance from corner1 then divide it by width of colorRec+1 ; 1 because-> margin; -1 ->arr indexed from 0
		int indexJ = (y - P1.y) / (height + 1);
		int index = indexI + 8 * indexJ;// 8 color per row
		chosencolor = index < 144 ? colors[index] : 0;//not working well ,index is less than the correct index
		isFilled = index > 143 ? false : true;
		return true;
	}
	
	return false;
}
bool ColorRectangle::isfilled()
{
	return isFilled;
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
	int w, h;
	w = P2.x - P1.x;
	h = P2.y - P1.y;
	pOut->drawImg(P1.x, P1.y,w,h);
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
}