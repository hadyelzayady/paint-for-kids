#include "Paste.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Paste::Paste(ApplicationManager * pApp) :Action(pApp)
{}
void Paste::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Pasted");
	int x, y;
	pManager->GetInput()->GetPointClicked(x,y);

	const vector<CFigure*>&copiedArr = pManager->copied;
	int size = copiedArr.size();
	for (int i = 0; i <size; i++)
	{
		CFigure*newFig=copiedArr[i]->copy();
		int newx = x + newFig->getCenter().x - pManager->refPoint.x;//get the new shifted center of copied figures
		int newy = y + newFig->getCenter().y - pManager->refPoint.y;
		newFig->Move(newx, newy);// move -> moves the figure center to newx,newy
		pManager->AddFigure(newFig);
	}


}


//Execute the action
void Paste::Execute()
{
	ReadActionParameters();

}
