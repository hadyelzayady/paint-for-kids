#pragma once
#include "WidthPallet.h"
#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
class ChangeWidth : public Action
{
	WidthPallet widthsWin;
	vector<CFigure*> ChangedList;
	vector<int>widths;//old width of each figure
	int newwidth;
public:
	ChangeWidth(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	bool changeAllSelected(int width);
	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~ChangeWidth();
};

