#include "ChangeWidth.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "WidthPallet.h"
ChangeWidth::ChangeWidth(ApplicationManager*pApp) :Action(pApp), widthsWin(pApp, ITM_CHANGEWIDTH*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ChangeWidth::ReadActionParameters()
{

}
bool ChangeWidth::changeAllSelected(int width) const
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	size_t i;
	for (i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->chngBorderWidth(width);
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
		UI.PenWidth = widthsWin.getWidth();
	widthsWin.closeRect();
}

void ChangeWidth::Undo()
{
}

void ChangeWidth::Redo()
{
}
