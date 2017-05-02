#include "PickAndHide.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
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
	pOut->PrintMessage("Play Pick and Hide");
	while (true)
	{
		pIn->GetPointClicked(x, y);
		if (y < UI.ToolBarHeight)// click on toolbar
			break;
		hideFig(x, y);
	}
	//reset to prev values
	copy(FigList.begin(), FigList.end(), pManager->getFigList());
	pManager->setFigCount(FigCount);
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
	//This action needs to read some parameters first
	ReadActionParameters();
}
