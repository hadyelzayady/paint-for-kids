#ifndef Cut_ACTION_H
#define Cut_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class Cut : public Action
{
public:
	Cut(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif