#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ResizeAction : public Action
{
	ColorRectangle colorsWin;
public:
	ResizeAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	void changeAllSelected()const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	~ResizeAction();
};

