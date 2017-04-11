#include "ChangeBKColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeBKColor::ChangeBKColor(ApplicationManager*pApp) :Action(pApp), colorsWin(pApp, ITM_BGRCOLOR*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ChangeBKColor::ReadActionParameters()
{

}

void ChangeBKColor::Execute()
{
	pManager->GetOutput()->PrintMessage("Change BackGround Color");
	colorsWin.DrawRect();
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	UI.BkGrndColor = colorsWin.getcolor();
	pManager->GetOutput()->ClearDrawArea();
}