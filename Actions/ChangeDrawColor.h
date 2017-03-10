#pragma once
#include "Action.h"
class ChangeFillColor : public Action
{
	Point P1, P2; //color window Corners(rectangle)
	GfxInfo RectGfxInfo;
	const int width = 13;// rectangle of one color
	const int height = 13;
public:
	ChangeFillColor(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	~ChangeFillColor();
};

