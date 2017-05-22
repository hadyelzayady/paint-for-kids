#pragma once
#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
class DeleteAction : public Action
{
	vector<CFigure*> DeletedList;
public:
	DeleteAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
	~DeleteAction();
};

