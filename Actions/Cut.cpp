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
	pManager->GetOutput()->PrintMessage("Cutted");
	CFigure** FigList = pManager->getFigList();
	vector<CFigure*>&copiedArr = pManager->copied;
	pManager->deletecopied(copiedArr);// remember to delete cutted figures
	size_t numOfCopied = 0;
	int minx = UI.width;// to get the fig with min x as my reference to for pasting later
	Point &refPointPaste = pManager->refPointPaste = { UI.width,0 };// to determine the min x and take it as my ref
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			CFigure*newFig = FigList[i]->copy();
			CutList.push_back(FigList[i]);
			copiedArr.push_back(newFig);
			numOfCopied++;
			refPointPaste = FigList[i]->getCenter().x < refPointPaste.x ? FigList[i]->getCenter() : refPointPaste;
			//remove the fig from figlist
			
			pManager->removeFigFromList(i);
			i--;// to check the fig that moved from end of figlist to the new pos
		}

	}
	copiedArr.resize(numOfCopied);
	pManager->GetOutput()->ClearDrawArea();
}

void Cut::Undo()
{
	for (size_t i = 0; i < CutList.size(); i++)
	{
		pManager->AddFigure(CutList[i]);
	}
}

void Cut::Redo()
{
	for (size_t i = 0; i < CutList.size(); i++)
	{
		pManager->removeFigFromList(CutList[i]);
	}
}
