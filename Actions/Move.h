#ifndef Move_ACTION_H
#define Move_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class Move : public Action
{
	int x, y;
public:
	Move(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();
	void recover(int lastindex);
	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif