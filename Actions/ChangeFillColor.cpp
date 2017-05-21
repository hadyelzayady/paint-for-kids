#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp) ,colorsWin(pApp,ITM_FILLCOLOR*UI.MenuItemWidth){}// 319 is the most left xpos of changedill icon

void ChangeFillColor::ReadActionParameters()
{

}
int ChangeFillColor::changeAllSelected(color c) const
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	int numOfSelect=0;
	for (size_t i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			if (FigList[i]->getGfxInfo().isFilled==true)
				FigList[i]->ChngFillClr(c);
			numOfSelect++;
		}

	}
	return numOfSelect;
}
void ChangeFillColor::Execute()
{
	colorsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing Fill Color");
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	if (changeAllSelected(colorsWin.getcolor())==0)
		UI.FillColor = colorsWin.getcolor();
	colorsWin.closeRect();
}