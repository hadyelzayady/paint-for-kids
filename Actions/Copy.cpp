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
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	CFigure**copiedArr = new CFigure*[FigCount];//max size
	size_t index;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			CFigure* Fig;
			//copiedArr[index] = ;
			index++;
		}

	}
	pManager->GetOutput()->ClearDrawArea();
}
