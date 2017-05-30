#pragma once
#include "Action.h"
#include "ColorRectangle.h"
#include <vector>
#include "../Figures/CFigure.h"
class ChangeDrawColor : public Action
{
	ColorRectangle colorsWin;
	color newColor;
	vector<CFigure*>ChangedList;
	vector<color> colorsList;
public:
	ChangeDrawColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	void changeAllSelected();
	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~ChangeDrawColor();
};

