#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Start;
	Point End;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual bool isPointInFigure(int x, int y)const;
	virtual void Draw(Output* pOut) const;
};

#endif