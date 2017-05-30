#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddTriAction::AddTriAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddTriAction:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y<UI.ToolBarHeight || P1.y >UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("invalid position");
		if (pIn->GetPointClicked(P1.x, P1.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->destrList.push(pManager->popAction());
			return;
		}
	}
	///////////////////////////////////////////////////////////////////
	pOut->PrintMessage("New Rectangle: Click at second corner");
	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	while (P2.y<UI.ToolBarHeight || P2.y >UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("invalid position,click right click to cancel action");
		if (pIn->GetPointClicked(P2.x, P2.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->destrList.push(pManager->popAction());
			return;
		}
	}
	///////////////////////////////////////////////////////////////////
	pOut->PrintMessage("New Rectangle: Click at third corner ,right click for filled");
	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	pOut->PrintMessage("invalid position,click right click to cancel action");
	while (P3.y<UI.ToolBarHeight || P3.y >UI.height - UI.StatusBarHeight)
	{
		if (pIn->GetPointClicked(P3.x, P3.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->destrList.push(pManager->popAction());
			return;
		}
	}
	pOut->PrintMessage("Action done");
	TriGfxInfo.isFilled = pManager->isFilled;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (cancelAction)
		return;
	//Create a Triangle with the parameters read from the user
	Tri = new CTriangle(P1, P2,P3,TriGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(Tri);
}

void AddTriAction::Undo()
{
	pManager->DelFigure(Tri);
}


void AddTriAction::Redo()
{
	Tri = new CTriangle(P1, P2,P3 ,TriGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(Tri);

}

AddTriAction::~AddTriAction()
{
}
