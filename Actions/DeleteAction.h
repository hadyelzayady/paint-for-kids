#pragma once
#include "Action.h"
class DeleteAction : public Action
{
public:
	DeleteAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	~DeleteAction();
};

