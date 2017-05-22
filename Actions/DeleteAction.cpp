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
			DeletedList.push_back(FigList[i]);
			pManager->removeFigFromList(i);
			FigCount--;
			i--;
		}

	}
	pManager->GetOutput()->ClearDrawArea();
}

void DeleteAction::Undo()
{
	for (size_t i = 0; i < DeletedList.size(); i++)
	{
		pManager->AddFigure(DeletedList[i]);
	}
}


void DeleteAction::Redo()
{
	for (size_t i = 0; i < DeletedList.size(); i++)
	{
		pManager->removeFigFromList(DeletedList[i]);
	}
}

DeleteAction::~DeleteAction()
{
}
