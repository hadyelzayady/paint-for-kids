#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class UndoAction : public Action
{
public:
	UndoAction(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif