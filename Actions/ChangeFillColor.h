#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ChangeFillColor : public Action
{
	ColorRectangle colorsWin;
	bool filled;
public:
	ChangeFillColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	bool changeAllSelected(color c)const;
	void Undo();
	void Redo();
	~ChangeFillColor();
};

