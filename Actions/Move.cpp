#include "Move.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Move::Move(ApplicationManager * pApp) :Action(pApp),refPoint(pManager->refPoint),oldrefPoint(pManager->refPoint)
{}
void Move::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Moving ,click on the new position");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	oldrefPoint = pManager->refPoint;
	int x, y;
	//get selected Fig
	for (size_t i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			MovedFig.push_back(FigList[i]);
		}
	}
	//
	while (pManager->GetInput()->GetButtonState(x, y) == BUTTON_UP) {
		if (pManager->GetInput()->GetMouseFromBuffer(x, y) == RIGHT_CLICK)//action cancelled
		{
			pManager->popAction();
			return;
		}
	}
	int xold=-10, yold=-10;
	while (pManager->GetInput()->GetButtonState(x, y) == BUTTON_DOWN)
	{
		if (x != xold && y != yold)// if there is a change in mouse position
		{
			for (int i = 0; i < MovedFig.size(); i++)
			{
				int newx = MovedFig[i]->getCenter().x + x - pManager->refPoint.x;//get the new shifted center of copied figures
				int newy = MovedFig[i]->getCenter().y + y - pManager->refPoint.y;
				if (!MovedFig[i]->Move(newx, newy))// move -> moves the figure center to newx,newy
				{
					pManager->GetOutput()->PrintMessage("Invalid position,click rigth click to exit action");
					Point temprefPoint = { x,y };
					Point tempoldrefPoint = pManager->refPoint;
					recover(tempoldrefPoint, temprefPoint, i);
					x = pManager->refPoint.x;// to not change refpoint if moving canceled
					y = pManager->refPoint.y;// to not change refpoint if moving canceled
					break;
				}
			}

			pManager->refPoint.x = x;// for moving more than once in one action
			pManager->refPoint.y = y;
			pManager->GetOutput()->ClearDrawArea();
			pManager->UpdateInterface();
		}
		else 
			pManager->UpdateInterface();
		xold = x;
		yold = y;

	}
	refPoint = pManager->refPoint;
	pManager->GetOutput()->PrintMessage("moving finished");

}

void Move::recover(Point OldP,Point CurrP,int last)
{
	for (int i = 0; i < last; i++)
	{
		int newx = MovedFig[i]->getCenter().x + OldP.x - CurrP.x;//get the new shifted center of copied figures
		int newy = MovedFig[i]->getCenter().y + OldP.y - CurrP.y;
		MovedFig[i]->Move(newx, newy);
	}
}

//Execute the action
void Move::Execute()
{
	ReadActionParameters();
}

void Move::Undo()
{
	for (int i = 0; i < MovedFig.size(); i++)
	{
		int newx = MovedFig[i]->getCenter().x + oldrefPoint.x - refPoint.x;//get the new shifted center of copied figures
		int newy = MovedFig[i]->getCenter().y + oldrefPoint.y - refPoint.y;
		MovedFig[i]->Move(newx, newy);
	}
}

void Move::Redo()
{
	for (int i = 0; i < MovedFig.size(); i++)
	{
		int newx = MovedFig[i]->getCenter().x + refPoint.x- oldrefPoint.x;//get the new shifted center of copied figures
		int newy = MovedFig[i]->getCenter().y + refPoint.y -oldrefPoint.y;
		MovedFig[i]->Move(newx, newy);
	}
	
}
