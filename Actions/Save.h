#ifndef Save_ACTION_H
#define Save_ACTION_H

#include "Action.h"

class Save : public Action
{
	string filename;
public:
	Save(ApplicationManager *pApp);
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

}; 
enum Colors {

};
#endif