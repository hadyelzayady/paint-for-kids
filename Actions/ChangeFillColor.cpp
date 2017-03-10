#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp) ,colorsWin(pApp,ITM_FILLCOLOR*UI.MenuItemWidth){}// 319 is the most left xpos of changedill icon

void ChangeFillColor::ReadActionParameters()
{

}

void ChangeFillColor::Execute()
{
	colorsWin.DrawRect();
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	UI.FillColor =colorsWin.getcolor() ;
	colorsWin.closeRect();
}