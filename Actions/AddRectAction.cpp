#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("invalid position,click right click to cancel action");
	while (P1.y<UI.ToolBarHeight || P1.y >UI.height - UI.StatusBarHeight)
	{
		if (pIn->GetPointClicked(P1.x, P1.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->destrList.push(pManager->popAction());
			return;
		}
	}
	pOut->PrintMessage("New Rectangle: Click at second corner,right click for filled");

	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("invalid position,click right click to cancel action");
	while (P2.y<UI.ToolBarHeight || P2.y >UI.height - UI.StatusBarHeight)
	{
		if (pIn->GetPointClicked(P2.x, P2.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->destrList.push(pManager->popAction());
			return;
		}
	}
	pOut->PrintMessage("Action done");
	RectGfxInfo.isFilled = pManager->isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (cancelAction)
		return;
	//Create a rectangle with the parameters read from the user
	Rect=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(Rect);
}

void AddRectAction::Undo()
{
	pManager->DelFigure(Rect);
}

void AddRectAction::Redo()
{
	Rect= new CRectangle(P1, P2, RectGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(Rect);
}
