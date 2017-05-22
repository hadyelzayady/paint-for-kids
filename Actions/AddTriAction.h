#pragma once
#include "Action.h"
#include "../Figures/CTriangle.h"
class AddTriAction : public Action
{
private:
	Point P1, P2,P3; //Triangle Corners
	GfxInfo TriGfxInfo;
	CTriangle*Tri;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~AddTriAction();
};

