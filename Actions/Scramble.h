#ifndef SCRAMBLE_FIND_PLAY_H
#define SCRAMBLE_FIND_PLAY_H

#include "Action.h"

//Add Rectangle Action class
class Scramble : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	Scramble(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif