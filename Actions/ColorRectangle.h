#pragma once
#include "Action.h"
class ColorRectangle : public Action
{
	Point P1,P2; //color window Corners(rectangle); second corner is known
	const int width = 13;// rectangle of one color
	const int height = 13;
	color chosencolor;
	bool isFilled;
	int x, y;// pos of clicked color
public:
	ColorRectangle(ApplicationManager*pApp,int x);
	void DrawRect() const;
	virtual void ReadActionParameters();
	bool selectColor() ;// if color selected returned true and the color in chosencolor 
	bool isfilled();
	color getcolor() const;
	void closeRect() const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	~ColorRectangle();
};

