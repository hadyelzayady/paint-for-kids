#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager*pApp) :Action(pApp), colorsWin(pApp, ITM_DRAWCOLOR*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ChangeDrawColor::ReadActionParameters()
{

}

void ChangeDrawColor::Execute()
{
	colorsWin.DrawRect();
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	UI.DrawColor = colorsWin.getcolor() ;
}