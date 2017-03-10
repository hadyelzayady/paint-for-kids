#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillColor::ChangeFillColor(ApplicationManager*pApp):Action(pApp) ,colorsWin(pApp,319){}// 319 is the most left xpos of changedill icon

void ChangeFillColor::ReadActionParameters()
{

}

void ChangeFillColor::Execute()
{
	colorsWin.Execute();
	UI.FillColor = colorsWin.getcolor();
}