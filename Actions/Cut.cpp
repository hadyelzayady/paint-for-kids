#include "Cut.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Cut::Cut(ApplicationManager * pApp) :Action(pApp)
{}
void Cut::ReadActionParameters()
{

}


//Execute the action
void Cut::Execute()
{
	pManager->GetOutput()->PrintMessage("Copying");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	vector<CFigure*>&copiedArr = pManager->copied;
	copiedArr.clear();// remember to delete cutted figures
	size_t numOfCopied = 0;
	int minx = UI.width;// to get the fig with min x as my reference to for pasting later
	Point &refPoint = pManager->refPoint = { UI.width,0 };// to determine the min x and take it as my ref
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			copiedArr.push_back(FigList[i]);
			numOfCopied++;
			pManager->refPoint = FigList[i]->getCenter().x < refPoint.x ? FigList[i]->getCenter() : refPoint;
			//remove the fig from figlist
			FigCount--;
			FigList[i] = FigList[FigCount];
			FigList[FigCount] = NULL;
			i--;// to check the fig that moved from end of figlist to the new pos
		}

	}
	pManager->setFigCount(FigCount);
	copiedArr.resize(numOfCopied);
	pManager->GetOutput()->ClearDrawArea();
}
