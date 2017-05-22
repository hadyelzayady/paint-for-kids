#ifndef FILLING_CIRC_ACTION_H
#define FILLING_CIRC_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class FillingAct : public Action
{
public:
	FillingAct(ApplicationManager *pApp);
	void changeAllSelected()const;
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif