#ifndef FILLING_CIRC_ACTION_H
#define FILLING_CIRC_ACTION_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class FillingAct : public Action
{
	vector<CFigure*>ChangedList;
	vector<bool>isFilledList;
	bool oldisFilled;
public:
	FillingAct(ApplicationManager *pApp);
	void changeAllSelected();
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif