#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager*pApp) :Action(pApp), colorsWin(pApp, ITM_DRAWCOLOR*UI.MenuItemWidth),newColor(UI.BkGrndColor) {}// 319 is the most left xpos of changedill icon

void ChangeDrawColor::ReadActionParameters()
{

}
bool ChangeDrawColor::changeAllSelected(color c) 
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	int numOfSelec = 0;
	int i;
	for (i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			ChangedList.push_back(FigList[i]);
			colorsList.push_back(FigList[i]->getGfxInfo().DrawClr);
			FigList[i]->ChngDrawClr(c);
		}
	}
	return i == 0 ? false : true;
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
	{	
		UI.DrawColor = c;
		pManager->popAction();// changing width only for no figures selected does not need undo and redo
	}
	newColor = colorsWin.getcolor();

}

void ChangeDrawColor::Undo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->ChngDrawClr(colorsList[i]);
	}
}

void ChangeDrawColor::Redo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->ChngDrawClr(newColor);
	}
}
