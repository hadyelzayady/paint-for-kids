#pragma once
#include "Action.h"
#include "ColorRectangle.h"
class ResizeAction : public Action
{
	const double options[4] = { .25,.5,2.4 };
public:
	ResizeAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	void changeAllSelected(float resize)const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	void CreateResizePallete()const;
	~ResizeAction();
};

