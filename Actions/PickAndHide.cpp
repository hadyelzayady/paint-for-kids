#include "PickAndHide.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <typeinfo>
#include <sstream>
PickAndHide::PickAndHide(ApplicationManager * pApp) :Action(pApp)
{
	TotalvalidCount = 0;// as the host figure is not counted from valid figures then we subtract it
}

void PickAndHide::setCountOfValid()
{
	int count = pManager->getFigCount();
	CFigure**FigList = pManager->getFigList();
	switch (PropType) {
	case 0:
		for (size_t i = 0; i < count; i++)
		{
			if (typeid(*FigList[i]) == typeid(*hostFig))
				TotalvalidCount++;
		}
		return;
	case 1:
		for (size_t i = 0; i < count; i++)
		{
			if (FigList[i]->getGfxInfo().FillClr == hostFig->getGfxInfo().FillClr && FigList[i]->getGfxInfo().isFilled == hostFig->getGfxInfo().isFilled )
				TotalvalidCount++;
		}
		return;
	case 2:
		for (size_t i = 0; i < count; i++)
		{
			if (typeid(*FigList[i]) == typeid(*hostFig) && FigList[i]->getGfxInfo().FillClr == hostFig->getGfxInfo().FillClr && FigList[i]->getGfxInfo().isFilled == hostFig->getGfxInfo().isFilled)
				TotalvalidCount++;
		}
		return;

	case 3:
		setnextarea();
		TotalvalidCount = pManager->getFigCount();
		return;

	}
}
void PickAndHide::setnextarea()
{
	int count = pManager->getFigCount();
	CFigure**FigList = pManager->getFigList();
	max_area = min_area = FigList[0]->getArea();
	for (size_t i = 1; i < count; i++)
	{
		if (FigList[i]->getArea() > max_area)
			max_area = FigList[i]->getArea();
		else if (FigList[i]->getArea() < min_area)
			min_area = FigList[i]->getArea();
	}
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
	do {
		pOut->PrintMessage("Play Pick and Hide,select the host figure");
		pIn->GetPointClicked(x, y);
		if (y < UI.ToolBarHeight)// click on toolbar
			return;
		hostFig = pManager->GetFigure(x, y);
	} while (hostFig == NULL);
	//// if area pro then check if host figure is the largest or the smallest
	if (PropType == 3)
	{
		setnextarea();// set max and min area
		if (hostFig->getArea() == min_area)
			desc = false;
		else if (hostFig->getArea() == max_area)
			desc = true;
		else
			return;
	}
	/////
	//now I have the host fig
	///////////////////
	CFigure*Fig;
	int validCount = 0;
	int invalidCount = 0;
	setCountOfValid();
	if (TotalvalidCount == 1) {//host figure counted
		pOut->PrintMessage("No Similar Figures exist !");
		return;
	}
	hideFig(x, y);
	TotalvalidCount--;;
	switch (PropType)
	{
	case 0://figure type
		while (validCount < TotalvalidCount)
		{
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight)// click on toolbar
				break;
			Fig = pManager->GetFigure(x, y);
			if (Fig == NULL)
				continue;
			if (typeid(*Fig) == typeid(*hostFig))
			{
				hideFig(x, y);
				validCount++;
			}
			else invalidCount++;
			ostringstream oss;
			oss << "Valid: " << validCount << "          Invalid: " << invalidCount;
			pOut->PrintMessage(oss.str());
		}
		break;
	case 1://FILL color
		while (validCount < TotalvalidCount)
		{
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight)// click on toolbar
				break;
			Fig = pManager->GetFigure(x, y);
			if (Fig == NULL)
				continue;
			if (Fig->getGfxInfo().FillClr == hostFig->getGfxInfo().FillClr && Fig->getGfxInfo().isFilled == hostFig->getGfxInfo().isFilled)
			{
				hideFig(x, y);
				validCount++;
			}
			else invalidCount++;
			ostringstream oss;
			oss << "Valid: " << validCount << "          Invalid: " << invalidCount;
			pOut->PrintMessage(oss.str());
		}
		break;
	case 2://type and fill color
		while (validCount < TotalvalidCount)
		{
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight)// click on toolbar
				break;
			Fig = pManager->GetFigure(x, y);
			if (Fig == NULL)
				continue;
			if (typeid(*Fig) == typeid(*hostFig) && Fig->getGfxInfo().FillClr == hostFig->getGfxInfo().FillClr &&Fig->getGfxInfo().isFilled == hostFig->getGfxInfo().isFilled)
			{
				hideFig(x, y);
				validCount++;
			}
			else invalidCount++;
			ostringstream oss;
			oss << "Valid: " << validCount << "          Invalid: " << invalidCount;
			pOut->PrintMessage(oss.str());
		}
		break;
	case 3://Area
		setnextarea();
		while (validCount < TotalvalidCount)
		{
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight)// click on toolbar
				break;
			Fig = pManager->GetFigure(x, y);
			if (Fig == NULL)
				continue;
			if ((desc && Fig->getArea() == max_area) || (!desc && Fig->getArea() == min_area))// descending and this figure as max area or ascc and ..
			{
				hideFig(x, y);
				validCount++;
				if(validCount !=TotalvalidCount)
					setnextarea();
			}
			else invalidCount++;
			ostringstream oss;
			oss << "Valid: " << validCount << "          Invalid: " << invalidCount;
			pOut->PrintMessage(oss.str());
		}
		break;
	}
	//reset to prev values
	ostringstream oss;
	oss <<"Congratulations :) " <<"you have mistaken " <<invalidCount<<" times" << " and choosed  all the  " << validCount;
	pOut->PrintMessage(oss.str());
	copy(FigList.begin(), FigList.end(), pManager->getFigList());
	pManager->setFigCount(FigCount);
	Sleep(500);// to show last figure hiding
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

