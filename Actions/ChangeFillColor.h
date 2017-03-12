#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ChangeFillColor : public Action
{
	ColorRectangle colorsWin;
public:
	ChangeFillColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	void changeAllSelected()const;
	~ChangeFillColor();
};

