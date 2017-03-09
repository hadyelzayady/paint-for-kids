#pragma once
#include "Action.h"
class AddTriAction : public Action
{
	Point P1, P2,P3; //triangle Corners
	GfxInfo RectGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	~AddTriAction();
};

