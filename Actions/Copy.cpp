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
	pManager->GetOutput()->PrintMessage("Copyed");
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	vector<CFigure*>&copiedArr = pManager->copied;
	pManager->deletecopied(copiedArr);
	size_t numOfCopied=0;
	Point &refPointPaste = pManager->refPointPaste = { UI.width,0 };// to determine the min x and take it as my ref
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			CFigure*newFig = FigList[i]->copy();
			copiedArr.push_back(newFig);
			numOfCopied++;
			refPointPaste = FigList[i]->getCenter().x < refPointPaste.x ? FigList[i]->getCenter(): refPointPaste;
		}

	}
	copiedArr.resize(numOfCopied);
	pManager->GetOutput()->ClearDrawArea();
}
