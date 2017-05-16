#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	bool cancelAction=false;
public:
	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;

	//To undo this action (code depends on action type)
	virtual void Undo();//abstract

	//To redo this action (code depends on action type)
	virtual void Redo();//abstarct

};
#endif
