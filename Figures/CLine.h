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
	CLine();
	virtual bool isPointInFigure(int x, int y)const;
	virtual void Draw(Output* pOut) const;
	virtual bool Move(int newx, int newy);
	virtual bool Resize(float);
	virtual CFigure* copy();
	virtual double getArea()const;
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
};

#endif