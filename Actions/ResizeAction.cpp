#include "ResizeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ResizeAction::ResizeAction(ApplicationManager*pApp) :Action(pApp){}

void ResizeAction::ReadActionParameters()
{

}
void ResizeAction::changeAllSelected()
{
	pManager->GetOutput()->PrintMessage("resize");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			ResizedList.push_back(FigList[i]);
			if (!FigList[i]->Resize(resize))
			{
				Undo();
				pManager->GetOutput()->PrintMessage("beyond boundries");
				//pManager->destruct(pManager->popAction());
				break;
			}
		}

	}
	pManager->GetOutput()->ClearDrawArea();
	
}
void ResizeAction::CreateResizePallete()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x = UI.MenuItemWidth*ITM_RESIZE-75;
	int y = UI.ToolBarHeight;
	int width = 200;
	int height = 50;
	pOut->drawImg(x, y, width, height, "images\\MenuItems\\ResizeOptions.jpg");
	int clickX, clickY;
	pIn->GetPointClicked(clickX, clickY);
	// getting option
	int index = -1;// if no size clicked then this default value ,-1 -> no choose
	if (clickY >UI.ToolBarHeight && clickY<y + height)
	{
		int relativeDistance = clickX - x;// distance from most left of the resize image
		index = relativeDistance /50;//50 is the width of resize option ; .25->50 px ...
	}
	//close pallete
	pOut->ClearDrawArea();

	if (index >= 4 || index == -1)
		return;
	resize = options[index];
	changeAllSelected();

}
void ResizeAction::Undo()
{
	for (size_t i = 0; i < ResizedList.size(); i++)
	{
			ResizedList[i]->Resize(1/resize);
	}
	pManager->GetOutput()->ClearDrawArea();

}
void ResizeAction::Redo()
{
	for (size_t i = 0; i < ResizedList.size(); i++)
	{
		ResizedList[i]->Resize(resize);
	}
	pManager->GetOutput()->ClearDrawArea();
}
void ResizeAction::Execute()
{
	CreateResizePallete();

}

void ResizeAction::recover(double resize,int lastelemindex)const
{
	pManager->GetOutput()->PrintMessage("beyond boundries");
	CFigure** FigList = pManager->getFigList();
	for (size_t i = 0; i <= lastelemindex; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->Resize(resize);
		}
	}
}
