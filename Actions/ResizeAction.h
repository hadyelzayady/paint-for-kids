#pragma once
#include "Action.h"
#include "ColorRectangle.h"
#include <vector>
#include "../Figures/CFigure.h"
class ResizeAction : public Action
{
	const double options[4] = { .25,.5,2,4 };
	vector<CFigure*>ResizedList;//list of resized figures
	double resize;
public:
	ResizeAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	void changeAllSelected();
	//Add Line to the ApplicationManager
	virtual void Execute();
	void recover(double resize,int lastelemindex)const;
	void CreateResizePallete();
	void Undo();
	void Redo();
	~ResizeAction();
};

