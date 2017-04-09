#include "PickAndHide.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickAndHide::PickAndHide(ApplicationManager * pApp) :Action(pApp)
{}

void PickAndHide::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Play Pick and Hide");

}

//Execute the action
void PickAndHide::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
}
