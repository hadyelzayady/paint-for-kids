#include "Move.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Move::Move(ApplicationManager * pApp) :Action(pApp)
{}
void Move::ReadActionParameters()
{
	int x, y;
	pManager->GetOutput()->PrintMessage("Moving ,click on the new position");
	pManager->GetInput()->GetPointClicked(x, y);
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			int newx = x + FigList[i]->getCenter().x - pManager->refPoint.x;//get the new shifted center of copied figures
			int newy = y + FigList[i]->getCenter().y - pManager->refPoint.y;
			FigList[i]->Move(newx, newy);// move -> moves the figure center to newx,newy
		}
	}
	pManager->GetOutput()->ClearDrawArea();
}

//Execute the action
void Move::Execute()
{
	ReadActionParameters();
}
