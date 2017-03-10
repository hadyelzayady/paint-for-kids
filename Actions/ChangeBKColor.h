#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ChangeBKColor : public Action
{
	ColorRectangle colorsWin;
public:
	ChangeBKColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	~ChangeBKColor();
};

