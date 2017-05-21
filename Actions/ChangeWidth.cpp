#include "ChangeWidth.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "WidthPallet.h"
ChangeWidth::ChangeWidth(ApplicationManager*pApp) :Action(pApp), widthsWin(pApp, ITM_CHANGEWIDTH*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ChangeWidth::ReadActionParameters()
{

}
void ChangeWidth::changeAllSelected() const
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	for (size_t i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->chngBorderWidth(UI.PenWidth);
	}
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
	UI.PenWidth = widthsWin.getWidth();
	changeAllSelected();
	widthsWin.closeRect();
}