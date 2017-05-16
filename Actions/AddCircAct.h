#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"
#include "../Figures/CCircle.h"
//Add Rectangle Action class
class AddCircAction : public Action
{
private:
	Point Center,P1; //Rectangle Corners
	GfxInfo CircGfxInfo;
	CCircle * Circ;
public:
	AddCircAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif