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
	void changeAllSelected()const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	~ChangeWidth();
};

