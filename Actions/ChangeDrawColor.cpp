#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager*pApp) :Action(pApp), colorsWin(pApp, ITM_DRAWCOLOR*UI.MenuItemWidth),oldColor(UI.BkGrndColor),ActColor(UI.BkGrndColor) {}// 319 is the most left xpos of changedill icon

void ChangeDrawColor::ReadActionParameters()
{

}
int ChangeDrawColor::changeAllSelected(color c) const
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	int numOfSelec = 0;
	for (size_t i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngDrawClr(c);
			numOfSelec++;
		}
	}
	return numOfSelec;
}
void ChangeDrawColor::Execute()
{
	colorsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing drawing Color");
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	color c = colorsWin.getcolor();
	if(changeAllSelected(c)==0)
		UI.DrawColor = c;
	colorsWin.closeRect();
}

void ChangeDrawColor::Undo()
{

}

void ChangeDrawColor::Redo()
{
}
