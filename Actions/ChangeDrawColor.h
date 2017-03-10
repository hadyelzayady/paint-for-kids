#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ChangeDrawColor : public Action
{
	ColorRectangle colorsWin;
public:
	ChangeDrawColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	~ChangeDrawColor();
};
