#include "FillingAct.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillingAct::FillingAct(ApplicationManager * pApp) :Action(pApp)
{}

void FillingAct::ReadActionParameters()
{


}
void FillingAct::changeAllSelected() 
{
	CFigure** FigList = pManager->getFigList();
	size_t count = pManager->getFigCount();
	for (size_t i = 0; i < count; i++)
	{
		if (FigList[i]->IsSelected())
		{
			ChangedList.push_back(FigList[i]);
			isFilledList.push_back(FigList[i]->getGfxInfo().isFilled);
			FigList[i]->chngIsFilled(pManager->isFilled);
		}

	}
	pManager->GetOutput()->ClearDrawArea();
}
//Execute the action
void FillingAct::Execute()
{
	oldisFilled=pManager->isFilled = !(pManager->isFilled);
	//activate toolbar image
	if (pManager->isFilled)
		pManager->GetOutput()->drawImg(UI.MenuItemWidth*ITM_FILL, 0,UI.MenuItemWidth, UI.ToolBarHeight, "images\\MenuItems\\Fill.jpg");
	else
		pManager->GetOutput()->drawImg(UI.MenuItemWidth*ITM_FILL, 0, UI.MenuItemWidth, UI.ToolBarHeight, "images\\MenuItems\\UnFill.jpg");
	changeAllSelected();
}

void FillingAct::Undo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->chngIsFilled(isFilledList[i]);
	}
}

void FillingAct::Redo()
{
	for (size_t i = 0; i < ChangedList.size(); i++)
	{
		ChangedList[i]->chngIsFilled(oldisFilled);
	}
}
