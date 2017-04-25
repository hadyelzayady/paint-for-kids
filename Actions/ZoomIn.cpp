#include "ZoomIn.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <vector>
ZoomIn::ZoomIn(ApplicationManager * pApp) :Action(pApp)
{}
void ZoomIn::ReadActionParameters()
{

}

//Execute the action
void ZoomIn::Execute()
{
	pManager->GetOutput()->PrintMessage("Zoom In");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	vector<CFigure*>&copiedArr = pManager->copied;
	pManager->deletecopied(copiedArr);// remember to delete cutted figures
	size_t numOfCopied = 0;
	Point &refPoint = pManager->refPoint = { UI.width,0 };// to determine the min x and take it as my ref
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			CFigure*newFig = FigList[i]->copy();
			copiedArr.push_back(newFig);
			numOfCopied++;
			pManager->refPoint = FigList[i]->getCenter().x < refPoint.x ? FigList[i]->getCenter() : refPoint;
			//remove the fig from figlist
			pManager->DelFigure(FigList[i], i);
			i--;// to check the fig that move from end of figlist to the new pos
		}

	}
	copiedArr.resize(numOfCopied);
	pManager->GetOutput()->ClearDrawArea();
}
