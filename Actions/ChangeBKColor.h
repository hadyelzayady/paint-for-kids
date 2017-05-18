#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ChangeBKColor : public Action
{
	ColorRectangle colorsWin;
	color oldColor;
	color ActColor;
public:
	ChangeBKColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~ChangeBKColor();
};

