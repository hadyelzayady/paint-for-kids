#pragma once
#include "Action.h"
#include "../Figures/CLine.h"
class AddLineAction : public Action
{
private:
	Point P1, P2; //Line start and end points
	GfxInfo LineGfxInfo;
	CLine*Line;
public:
	AddLineAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~AddLineAction();
};

