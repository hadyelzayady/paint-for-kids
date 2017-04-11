#ifndef Move_ACTION_H
#define Move_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class Move : public Action
{
public:
	Move(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif