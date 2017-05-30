#include "Paste.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Paste::Paste(ApplicationManager * pApp) :Action(pApp)
{}
void Paste::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Pasting");
	int x, y;
	pManager->GetInput()->GetPointClicked(x,y);

	const vector<CFigure*>&copiedArr = pManager->copied;
	int size = copiedArr.size();
	for (int i = 0; i <size; i++)
	{
		CFigure*newFig=copiedArr[i]->copy();
		int newx = x + newFig->getCenter().x - pManager->refPointPaste.x;//get the new shifted center of copied figures
		int newy = y + newFig->getCenter().y - pManager->refPointPaste.y;
		if (!newFig->Move(newx, newy))
		{
			pManager->GetOutput()->PrintMessage("invalid ,pasting cancelled");
			recover(i);

			return;
		}// move -> moves the figure center to newx,newy
		mycopyList.push_back(newFig);
		pManager->AddFigure(newFig);
	}
	pManager->GetOutput()->PrintMessage("Pasted");

}

void Paste::recover(int numOfadded)//removes last added figures
{
	int count=pManager->getFigCount();
	CFigure**FigList = pManager->getFigList();
	for (size_t i =0; i < numOfadded  ; i++)
	{
		--count;
		pManager->DelFigure(FigList[count], count);
	}
}


//Execute the action
void Paste::Execute()
{
	ReadActionParameters();

}

void Paste::Undo()
{
	int count = mycopyList.size();
	for (size_t i = 0; i < count; i++)
	{
		pManager->removeFigFromList(mycopyList[i]);
	}
}

void Paste::Redo()
{
	for (size_t i = 0; i < mycopyList.size(); i++)
	{
		pManager->AddFigure(mycopyList[i]);
	}
}
