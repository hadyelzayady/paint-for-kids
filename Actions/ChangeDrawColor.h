#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ChangeDrawColor : public Action
{
	ColorRectangle colorsWin;
	color oldColor;
	color ActColor;
public:
	ChangeDrawColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	void changeAllSelected()const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~ChangeDrawColor();
};

