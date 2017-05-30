#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager*pApp) :Action(pApp), colorsWin(pApp, ITM_DRAWCOLOR*UI.MenuItemWidth),newColor(UI.BkGrndColor) {}// 319 is the most left xpos of changedill icon

void ChangeDrawColor::ReadActionParameters()
{

}
void ChangeDrawColor::changeAllSelected() 
{
	for (int i = 0; i < ChangedList.size(); i++)
	{
		colorsList.push_back(ChangedList[i]->getGfxInfo().DrawClr);
		ChangedList[i]->ChngDrawClr(newColor);
	}
}
void ChangeDrawColor::Execute()
{
	colorsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing drawing Color");
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	newColor = colorsWin.getcolor();
	if(!pManager->getSelectedFigs(ChangedList))
	{	
		UI.DrawColor = newColor;
		pManager->popAction();// changing width only for no figures selected does not need undo and redo
	}
	else 		
		changeAllSelected();

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
