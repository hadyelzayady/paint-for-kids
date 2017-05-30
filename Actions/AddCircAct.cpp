#include "AddCircAct.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(Center.x,Center.y);
	while (Center.y<UI.ToolBarHeight || Center.y >UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("invalid position");
		pIn->GetPointClicked(Center.x, Center.y);
	}
	pOut->PrintMessage("click at point to determine radius");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P1.x, P1.y);
	int Rad = (int)sqrt(pow(Center.x - P1.x, 2) + pow(Center.y - P1.y, 2));
	pOut->PrintMessage("invalid position,click right click to cancel action");
	while (Center.y-Rad <UI.ToolBarHeight || Center.y+Rad >UI.height - UI.StatusBarHeight || Center.x-Rad<0 || Center.x+Rad>UI.width)
	{
		if (pIn->GetPointClicked(P1.x, P1.y) == RIGHT_CLICK)
		{
			pOut->PrintMessage("Action cancelled");
			cancelAction = true;
			pManager->destrList.push(pManager->popAction());
			return;
		}
		Rad = (int)sqrt(pow(Center.x - P1.x, 2) + pow(Center.y - P1.y, 2));
	}
	CircGfxInfo.isFilled = pManager->isFilled;	//default is not filled
	pOut->PrintMessage("action done");							//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (cancelAction)
		return;
	//Create a rectangle with the parameters read from the user
	int Rad = (int)sqrt(pow(Center.x - P1.x, 2) + pow(Center.y - P1.y, 2));
	Circ = new CCircle(Center,Rad, CircGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(Circ);
}

void AddCircAction::Undo()
{
	pManager->DelFigure(Circ);
}

void AddCircAction::Redo()
{
	int Rad = (int)sqrt(pow(Center.x - P1.x, 2) + pow(Center.y - P1.y, 2));
	Circ = new CCircle(Center, Rad, CircGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(Circ);
}
