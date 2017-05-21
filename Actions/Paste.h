#ifndef Paste_ACTION_H
#define Paste_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class Paste : public Action
{
public:
	Paste(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();
	void recover(int i);
	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif