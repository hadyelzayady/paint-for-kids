#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute()
{
	CFigure** FigList = pManager->getFigList();
	int FigCount = pManager->getFigCount();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			pManager->DelFigure(FigList[i], i);
			FigCount--;
			i--;
		}

	}
	pManager->GetOutput()->ClearDrawArea();
}


DeleteAction::~DeleteAction()
{
}
