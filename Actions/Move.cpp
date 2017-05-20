#include "Move.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Move::Move(ApplicationManager * pApp) :Action(pApp),refPoint(pManager->refPoint)
{}
void Move::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Moving ,click on the new position");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	while (pManager->GetInput()->GetPointClicked(x, y) == LEFT_CLICK)
	{
		for (int i = 0; i < pManager->getFigCount(); i++)
		{
			if (FigList[i]->IsSelected())
			{
				int newx = x + FigList[i]->getCenter().x - pManager->refPoint.x;//get the new shifted center of copied figures
				int newy = y + FigList[i]->getCenter().y - pManager->refPoint.y;
				if (!FigList[i]->Move(newx, newy))// move -> moves the figure center to newx,newy
				{
					pManager->GetOutput()->PrintMessage("Invalid position,click rigth click to exit action");
					recover(i);
					x = pManager->refPoint.x;// to not change refpoint if moving canceled
					y = pManager->refPoint.y;// to not change refpoint if moving canceled
					break;
				}
				MovedFig.push_back(FigList[i]);
			}
		}
		pManager->GetOutput()->ClearDrawArea();
		pManager->UpdateInterface();
		pManager->refPoint.x = x;
		pManager->refPoint.y = y;
	}

	pManager->GetOutput()->PrintMessage("moving finished");

}

void Move::recover(int lastindex)
{
	CFigure** FigList = pManager->getFigList();
	for (int i = 0; i < lastindex; i++)
	{
		if (FigList[i]->IsSelected())
		{
			int newx = FigList[i]->getCenter().x - (x - pManager->refPoint.x);//get the new shifted center of copied figures
			int newy = FigList[i]->getCenter().y - (y - pManager->refPoint.y);
			FigList[i]->Move(newx, newy);
			MovedFig.pop_back();
		}
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
		int newx = MovedFig[i]->getCenter().x - (x - refPoint.x);//get the new shifted center of copied figures
		int newy = MovedFig[i]->getCenter().y - (y - refPoint.y);
		MovedFig[i]->Move(newx, newy);
	}
}

void Move::Redo()
{
}
