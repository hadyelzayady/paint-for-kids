#ifndef Pick_Hide_PLAY_H
#define Pick_Hide_PLAY_H

#include "Action.h"
#include <vector>
#include "../Figures/CFigure.h"
//Add Rectangle Action class
class PickAndHide : public Action
{
private:
	const double options[4] = { 0,1,2,3 };
	int PropType;
	CFigure*hostFig;
	int TotalvalidCount;
	double max_area;
	double min_area;
	bool desc;
public:
	PickAndHide(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	void createPropPallet();
	CFigure* getFig(int x, int y)const;
	//Add rectangle to the ApplicationManager
	void hideFig(int x,int y);
	virtual void Execute();
	void setCountOfValid();
	void setnextarea();

};

#endif