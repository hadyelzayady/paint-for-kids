#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp) ,colorsWin(pApp,ITM_FILLCOLOR*UI.MenuItemWidth){}// 319 is the most left xpos of changedill icon

void ChangeFillColor::ReadActionParameters()
{

}
void ChangeFillColor::changeAllSelected() const
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	for (size_t i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			if(!filled)
				FigList[i]->chngIsFilled(filled);
			else
				FigList[i]->ChngFillClr(UI.FillColor);
		}

	}
}
void ChangeFillColor::Execute()
{
	colorsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing Fill Color");
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	filled = colorsWin.isfilled();
	UI.FillColor = colorsWin.getcolor();
	changeAllSelected();
	colorsWin.closeRect();
}