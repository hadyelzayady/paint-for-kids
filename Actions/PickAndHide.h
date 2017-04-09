#ifndef Pick_Hide_PLAY_H
#define Pick_Hide_PLAY_H

#include "Action.h"

//Add Rectangle Action class
class PickAndHide : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	PickAndHide(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif