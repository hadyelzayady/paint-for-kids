#include "ChangeWidth.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "WidthPallet.h"
ChangeWidth::ChangeWidth(ApplicationManager*pApp) :Action(pApp), widthsWin(pApp, ITM_CHANGEWIDTH*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ChangeWidth::ReadActionParameters()
{

}
void ChangeWidth::changeAllSelected() 
{
	for (int i = 0; i < ChangedList.size(); i++)
	{
		widths.push_back(ChangedList[i]->getGfxInfo().BorderWdth);
		ChangedList[i]->chngBorderWidth(newwidth);
	}
}
void ChangeWidth::Execute()
{
	widthsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing drawing Color");
	bool isselected = widthsWin.selectWidth();
	widthsWin.closeRect();
	if (!isselected)
	{
		return;
		pManager->destrList.push(pManager->popAction());
	}
	pManager->GetOutput()->PrintMessage("width changed");
	newwidth = widthsWin.getWidth();
	if (!pManager->getSelectedFigs(ChangedList))
	{
		UI.PenWidth = widthsWin.getWidth();
		pManager->popAction();// changing width only for no figures selected does not need undo and redo
	}
	else
		changeAllSelected();

}

void ChangeWidth::Undo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->chngBorderWidth(widths[i]);
	}
}

void ChangeWidth::Redo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->chngBorderWidth(newwidth);
	}
}
