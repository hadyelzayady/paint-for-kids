#ifndef Paste_ACTION_H
#define Paste_ACTION_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class Paste : public Action
{
	vector<CFigure*>mycopyList;
public:
	Paste(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();
	void recover(int i);
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif