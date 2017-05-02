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
	//image screenshot("C:\\Users\HADY\\Google Drive\\CUFE\term4\\OOP\Project Framework\\Actions");
	//pManager->GetOutput()->screenshot(screenshot, 0, UI.ToolBarHeight, UI.width, UI.height-UI.StatusBarHeight-UI.ToolBarHeight);
	//pManager->GetOutput()->drawImg(0,UI.ToolBarHeight,UI.width,UI.height-UI.ToolBarHeight-UI.StatusBarHeight,"C:\\Users\HADY\\Google Drive\\CUFE\term4\\OOP\Project Framework\\Actions");
}
