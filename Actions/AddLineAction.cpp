#include "AddLineAction.h"
#include "..\Figures\CLine.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at start point");
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y<UI.ToolBarHeight || P1.y >UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("invalid position");
		if (pIn->GetPointClicked(P1.x, P1.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			return;
		}
	}
	///////////////////////////////////////////////////////////////////
	pOut->PrintMessage("New Line: Click at end point ,right click for filled");
	//Read 2nd corner and store in point P2
	clicktype clk = pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("invalid position,click right click to cancel action");
	while (P2.y<UI.ToolBarHeight || P2.y >UI.height - UI.StatusBarHeight)
	{
		if (pIn->GetPointClicked(P2.x, P2.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->popAction();
			return;
		}
	}
	LineGfxInfo.isFilled =false;	//default is not filled
	pOut->PrintMessage("Action done");									//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (cancelAction)
		return;
	//Create a Line with the parameters read from the user
	Line = new CLine(P1, P2,LineGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(Line);
}

void AddLineAction::Undo()
{
	pManager->DelFigure(Line);
}

void AddLineAction::Redo()
{
	Line = new CLine(P1, P2, LineGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(Line);
}


AddLineAction::~AddLineAction()
{
}
