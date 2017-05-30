#pragma once
#include "WidthPallet.h"
#include "Action.h"
class ChangeWidth : public Action
{
	WidthPallet widthsWin;
public:
	ChangeWidth(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	bool changeAllSelected(int width)const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~ChangeWidth();
};

