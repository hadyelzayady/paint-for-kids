#ifndef ZoomIn_ACTION_H
#define ZoomIn_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class ZoomIn : public Action
{
public:
	ZoomIn(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif