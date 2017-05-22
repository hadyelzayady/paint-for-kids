#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class Copy : public Action
{
public:
	Copy(ApplicationManager *pApp);
	static int numOfSelected; //
	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif