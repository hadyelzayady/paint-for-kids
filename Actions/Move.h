#ifndef Move_ACTION_H
#define Move_ACTION_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class Move : public Action
{
	Point oldrefPoint;
	vector<CFigure*> MovedFig;
	Point refPoint;
	int x, y;
public:
	Move(ApplicationManager *pApp);
	//Reads rectangle parameters
	static int numOfSelected; //
	virtual void ReadActionParameters();
	void recover(Point,Point,int last);
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();

};

#endif