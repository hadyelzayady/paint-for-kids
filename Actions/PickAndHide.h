#ifndef Pick_Hide_PLAY_H
#define Pick_Hide_PLAY_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class PickAndHide : public Action
{
	int tempFigCount;
	vector<CFigure*>tempFigList;
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	PickAndHide(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	CFigure* getFig(int x, int y)const;
	//Add rectangle to the ApplicationManager
	void hideFig(int x,int y);
	virtual void Execute();

};

#endif