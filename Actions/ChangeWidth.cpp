#include "ChangeWidth.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "WidthPallet.h"
ChangeWidth::ChangeWidth(ApplicationManager*pApp) :Action(pApp), widthsWin(pApp, ITM_CHANGEWIDTH*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ChangeWidth::ReadActionParameters()
{

}
bool ChangeWidth::changeAllSelected(int width) 
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	size_t i;
	for (i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			ChangedList.push_back(FigList[i]);
			widths.push_back(FigList[i]->getGfxInfo().BorderWdth);
			FigList[i]->chngBorderWidth(width);
		}
	}
	return i == 0 ? false : true;
}
void ChangeWidth::Execute()
{
	widthsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing drawing Color");
	bool isselected = widthsWin.selectWidth();
	widthsWin.closeRect();
	if (!isselected)
		return;
	pManager->GetOutput()->PrintMessage("width changed");
	if (!changeAllSelected(widthsWin.getWidth()))
	{
		UI.PenWidth = widthsWin.getWidth();
		pManager->popAction();// changing width only for no figures selected does not need undo and redo
	}
	newwidth = widthsWin.getWidth();
	widthsWin.closeRect();
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
