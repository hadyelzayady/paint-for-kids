#pragma once
#include "Action.h"
class WidthPallet : public Action
{
	Point P1, P2; //color window Corners(rectangle); second corner is known
	const int width =150;// rectangle of one color
	const int height = 100;
	int chosenwidth;
	int x, y;// pos of clicked color
public:
	WidthPallet(ApplicationManager*pApp, int x);
	void DrawRect() ;
	virtual void ReadActionParameters();
	bool selectWidth();// if color selected returned true and the color in chosencolor 
	int getWidth() const;
	void closeRect() const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	~WidthPallet();
};

