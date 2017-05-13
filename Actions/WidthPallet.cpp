#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "WidthPallet.h"
WidthPallet::WidthPallet(ApplicationManager*pApp, int x) :Action(pApp)
{
	this->P1.x = x;
	this->P1.y = 52;
	this->P2.x =P1.x+width;// 8 squares in row ,each square with width+margin 1 except last square
	this->P2.y = P1.y;
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
	int yup=0, ydown=2;
	int widthessum=2;// sum of prev widthes
	int currentwidth = 2;
	y -= 50;
	for (size_t i = 0; i < 15; i++)
	{
		if (y >= yup && y <= ydown)
		{
			chosenwidth = currentwidth;
			return true;
		}
		//next line parameters;
		yup = pow(2, i+1) + widthessum;
		currentwidth/*of next line*/ = 2 * (i + 2);
		ydown = pow(2, i + 1) +widthessum+ currentwidth;
		widthessum += currentwidth;
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
	int k = 0;//index of color in the array
	int space = 5;
	int nextWidth,currentWidth;
	for (size_t i = 0; i < 15; i++)//as line is drawn from center the half width up and down we can deduce this equ
	{
		pOut->DrawLine(tempP1, tempP2, LineGfxInfo);
		currentWidth = LineGfxInfo.BorderWdth;
		LineGfxInfo.BorderWdth += 2;
		nextWidth = LineGfxInfo.BorderWdth;
		tempP1.y += space + .5*nextWidth + .5*currentWidth;
		tempP2.y = tempP1.y;
	}
}
void WidthPallet::closeRect() const
{
	pManager->GetOutput()->ClearDrawArea();
}
void WidthPallet::Execute()
{
}