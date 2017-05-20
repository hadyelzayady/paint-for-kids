#ifndef Move_ACTION_H
#define Move_ACTION_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class Move : public Action
{
	int x, y;
	vector<CFigure*> MovedFig;
	Point refPoint;
public:
	Move(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();
	void recover(int lastindex);
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();

};

#endif