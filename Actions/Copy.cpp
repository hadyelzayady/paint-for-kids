#include "Copy.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
Copy::Copy(ApplicationManager * pApp) :Action(pApp)
{}
void Copy::ReadActionParameters()
{

}


//Execute the action
void Copy::Execute()
{
	pManager->GetOutput()->PrintMessage("Copying");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	vector<CFigure*>&copiedArr = pManager->copied;
	pManager->deletecopied(copiedArr);
	size_t numOfCopied=0;
	int minx = UI.width;// to get the fig with min x as my reference to for pasting later
	Point &refPoint = pManager->refPoint = { UI.width,0 };// to determine the min x and take it as my ref
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			CFigure*newFig = FigList[i]->copy();
			copiedArr.push_back(newFig);
			numOfCopied++;
			pManager->refPoint = FigList[i]->getCenter().x < refPoint.x ? FigList[i]->getCenter(): refPoint;
		}

	}
	copiedArr.resize(numOfCopied);
	pManager->GetOutput()->ClearDrawArea();
}
