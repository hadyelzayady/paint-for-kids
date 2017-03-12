#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class SelectAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	SelectAction(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif