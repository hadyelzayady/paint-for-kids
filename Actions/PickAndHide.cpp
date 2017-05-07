#include "PickAndHide.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <typeinfo>
PickAndHide::PickAndHide(ApplicationManager * pApp) :Action(pApp)
{
}
void PickAndHide::ReadActionParameters()
{
	// save the original Figlist and figcount 
	int FigCount = pManager->getFigCount();
	vector<CFigure*>FigList(pManager->getFigList(), pManager->getFigList() + FigCount);

	//
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	//////////////////////choose host figure
	CFigure*hostFig;
	do {
		pOut->PrintMessage("Play Pick and Hide,select the host figure");
		pIn->GetPointClicked(x, y);
		if (y < UI.ToolBarHeight)// click on toolbar
			return;
		hostFig = pManager->GetFigure(x, y);
	} while (hostFig == NULL);
	hideFig(x, y);
	//now I have the host fig
	///////////////////
	CFigure*Fig;
	switch (PropType)
	{
	case 0://figure type
		while (true)
		{
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight)// click on toolbar
				break;
			Fig = pManager->GetFigure(x, y);
			if (typeid(*Fig) == typeid(*hostFig))
				hideFig(x, y);
		}
		break;
	case 1://FILL color
		while (true)
		{
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight)// click on toolbar
				break;
			Fig = pManager->GetFigure(x, y);
			if (Fig->getGfxInfo().FillClr == hostFig->getGfxInfo().FillClr)
				hideFig(x, y);
		}
		break;
	}
	//case 2://type and fill color
	//	while (true)
	//	{
	//		pIn->GetPointClicked(x, y);
	//		if (y < UI.ToolBarHeight)// click on toolbar
	//			break;
	//		Fig = pManager->GetFigure(x, y);
	//		if (typeid(*Fig) == typeid(*hostFig) && Fig->getGfxInfo().FillClr == hostFig->getGfxInfo().FillClr)
	//			hideFig(x, y);
	//	}
	//	break;
	//case 3://Area
	//	while (true)
	//	{
	//		pIn->GetPointClicked(x, y);
	//		if (y < UI.ToolBarHeight)// click on toolbar
	//			break;
	//		Fig = pManager->GetFigure(x, y);
	//		if (Fig->getArea()==hostFig->getArea())
	//			hideFig(x, y);
	//	}
	//	break;
	//}
	while (true)
	{
		pIn->GetPointClicked(x, y);
		if (y < UI.ToolBarHeight)// click on toolbar
			break;
		Fig = pManager->GetFigure(x, y);
		if (typeid(*Fig)==typeid(*hostFig))
			hideFig(x, y); 
	}
	//reset to prev values
	copy(FigList.begin(), FigList.end(), pManager->getFigList());
	pManager->setFigCount(FigCount);
}

void PickAndHide::createPropPallet()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x = UI.MenuItemWidth*PICKHIDE;
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
		index = relativeDistance / 50;//50 is the width of resize option ; .25->50 px ...
	}
	//close pallete
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	if (index >= 4 || index == -1)
		return;
	PropType = options[index];
	ReadActionParameters();
}



void PickAndHide::hideFig(int x,int y)
{
	size_t FigCount = pManager->getFigCount();
	CFigure**FigList = pManager->getFigList();
	for (size_t i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isPointInFigure(x, y))
		{
			FigList[i] = FigList[--FigCount];
			FigList[FigCount] = NULL;
			pManager->GetOutput()->ClearDrawArea();
			pManager->setFigCount(FigCount);
			pManager->UpdateInterface();
			return;
		}
	}

}

//Execute the action
void PickAndHide::Execute()
{
	createPropPallet();
	//This action needs to read some parameters first
//	ReadActionParameters();
}
