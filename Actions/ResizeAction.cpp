#include "ResizeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ResizeAction::ResizeAction(ApplicationManager*pApp) :Action(pApp), colorsWin(pApp, ITM_DRAWCOLOR*UI.MenuItemWidth) {}// 319 is the most left xpos of changedill icon

void ResizeAction::ReadActionParameters()
{

}
void ResizeAction::changeAllSelected() const
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	for (size_t i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->ChngDrawClr(UI.DrawColor);
	}
}
void ResizeAction::Execute()
{
	colorsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing drawing Color");
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	UI.DrawColor = colorsWin.getcolor();
	changeAllSelected();
	colorsWin.closeRect();
}