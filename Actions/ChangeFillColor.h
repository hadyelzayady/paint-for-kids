#pragma once
#include "Action.h"
#include "ColorRectangle.h"
#include <vector>
#include "../Figures/CFigure.h"
class ChangeFillColor : public Action
{
	ColorRectangle colorsWin;
	bool filled;
	vector<CFigure*>ChangedList;
	vector<color>Fillcolors;
	color newcolor;
public:
	ChangeFillColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	void changeAllSelected();
	void Undo();
	void Redo();
	~ChangeFillColor();
};

