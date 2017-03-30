#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
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
	while (true)
	{
		pIn->GetPointClicked(x, y);
		if (y < UI.ToolBarHeight)// user clicks on icons to make action on selected figures ;selected figures still selected
			return;
		CFigure* selectedFig = pManager->GetFigure(x, y);
		if (selectedFig == NULL)// if clicks on empty space on drawing area ->unselect all
			return;
		bool Selected = selectedFig->IsSelected();
		selectedFig->SetSelected(!Selected);
		selectedFig->Draw(pOut);
		if (Selected)// it is now unselected as selected has the prev state
		{
			numOfSelected--;

		}
		else// it is now selected
		{
			numOfSelected++;
		}
		if (numOfSelected == 1)
		{
			// print fig info
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

}
