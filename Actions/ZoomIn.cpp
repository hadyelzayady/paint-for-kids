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
	image screenshot;
	pManager->GetOutput()->screenshot(screenshot, 0, UI.ToolBarHeight, UI.width, UI.height-UI.StatusBarHeight-UI.ToolBarHeight);
	//pManager->GetOutput()->drawImg();
}
