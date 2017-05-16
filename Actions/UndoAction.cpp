#include "UndoAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
UndoAction::UndoAction(ApplicationManager * pApp) :Action(pApp)
{
	
}
void UndoAction::ReadActionParameters()
{

}


//Execute the action
void UndoAction::Execute()
{
	Action*ac=pManager->popAction();
	ac->Undo();
	pManager->GetOutput()->ClearDrawArea();
}
