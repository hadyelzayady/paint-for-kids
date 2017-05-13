#ifndef Load_ACTION_H
#define Load_ACTION_H

#include "Action.h"

class Load : public Action
{
	string filename;
public:
	Load(ApplicationManager *pApp);
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
#endif