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
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInFigure(int x, int y)const;
	virtual bool Move(int newx, int newy);
	virtual bool Resize(float resize);
	virtual CFigure* copy();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	virtual double getArea()const;
};

#endif