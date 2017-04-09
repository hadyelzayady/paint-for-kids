#include "Scramble.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Scramble::Scramble(ApplicationManager * pApp) :Action(pApp)
{}

void Scramble::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Play Scamble And Find");

}

//Execute the action
void Scramble::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
}
