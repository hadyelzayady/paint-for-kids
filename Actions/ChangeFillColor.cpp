#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp) ,colorsWin(pApp,ITM_FILLCOLOR*UI.MenuItemWidth),newcolor(WHITE){}// 319 is the most left xpos of changedill icon

void ChangeFillColor::ReadActionParameters()
{

}
bool ChangeFillColor::changeAllSelected(color c) 
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	size_t i;
	for (i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			if (FigList[i]->getGfxInfo().isFilled == true)
			{
				ChangedList.push_back(FigList[i]);
				Fillcolors.push_back(FigList[i]->getGfxInfo().FillClr);
				FigList[i]->ChngFillClr(c);
			}
		}

	}
	return i == 0 ? false : true;
}

void ChangeFillColor::Execute()
{
	colorsWin.DrawRect();
	pManager->GetOutput()->PrintMessage("Changeing Fill Color");
	bool isselected = colorsWin.selectColor();
	colorsWin.closeRect();
	if (!isselected)
		return;
	if (!changeAllSelected(colorsWin.getcolor()))
	{
		UI.FillColor = colorsWin.getcolor();
		pManager->popAction();// changing width only for no figures selected does not need undo and redo
	}
	newcolor = colorsWin.getcolor();
}

void ChangeFillColor::Undo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->ChngFillClr(Fillcolors[i]);
	}
}
void ChangeFillColor::Redo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->ChngFillClr(newcolor);
	}
}