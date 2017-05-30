#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp) ,colorsWin(pApp,ITM_FILLCOLOR*UI.MenuItemWidth),newcolor(WHITE){}// 319 is the most left xpos of changedill icon

void ChangeFillColor::ReadActionParameters()
{

}
void ChangeFillColor::changeAllSelected() 
{
	for (int i = 0; i < ChangedList.size(); i++)
	{
		if (ChangedList[i]->getGfxInfo().isFilled == true)
		{
			Fillcolors.push_back(ChangedList[i]->getGfxInfo().FillClr);
			ChangedList[i]->ChngFillClr(newcolor);
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
	newcolor = colorsWin.getcolor();;
	if (!pManager->getSelectedFigs(ChangedList))
	{
		UI.FillColor = newcolor;
		pManager->popAction();// changing width only for no figures selected does not need undo and redo
	}
	else
		changeAllSelected();
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