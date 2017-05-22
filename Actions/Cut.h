#ifndef Cut_ACTION_H
#define Cut_ACTION_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class Cut : public Action
{
	vector<CFigure*> CutList;
public:
	Cut(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif