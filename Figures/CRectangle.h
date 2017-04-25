#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInFigure(int x, int y)const;
	virtual void Move(int newx, int newy);
	virtual void Resize(float resize);
	virtual CFigure* copy();
};

#endif