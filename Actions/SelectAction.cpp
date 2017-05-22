#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
int SelectAction::numOfSelected = 0;
SelectAction::SelectAction(ApplicationManager * pApp) :Action(pApp)
{}
void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select Figure(s)...");
	int x, y;
	vector <CFigure*> selected;
	while (pIn->GetPointClicked(x, y)==LEFT_CLICK)
	{

		if (y < UI.ToolBarHeight)// user clicks on icons to make action on selected figures ;selected figures still selected
			return;
		CFigure* selectedFig = pManager->GetFigure(x, y);
		pOut->PrintNumber(x);
		if (selectedFig == NULL)// if clicks on empty space on drawing area ->unselect all
			continue;
		bool Selected = selectedFig->IsSelected();
		selectedFig->SetSelected(!Selected);
		selectedFig->Draw(pOut);
		Selected=!Selected ;//
		if (Selected)// e
		{
			selected.push_back(selectedFig);
			numOfSelected++;

		}
		else// 
		{
			numOfSelected--;
		    vector<CFigure*>::iterator it= find(selected.begin(), selected.end(), selectedFig);
			*it = selected.at(selected.size() - 1);
			selected.pop_back();
		}
		if (numOfSelected == 1)
		{
			// print fig info
			selected.at(0)->PrintInfo(pOut);
		}
		else
			pOut->PrintNumber(numOfSelected);
		}


}


//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	// set ref point to use it in paste and move
	int FigCount = pManager->getFigCount();
	CFigure**FigList = pManager->getFigList();
	Point &refPoint = pManager->refPoint = { UI.width,0 };// to determine the min x and take it as my ref
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			pManager->refPoint = FigList[i]->getCenter().x < refPoint.x ? FigList[i]->getCenter() : refPoint;
		}

	}


}
