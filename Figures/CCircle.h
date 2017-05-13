#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"
#include <iomanip>
class CCircle : public CFigure
{
private:
	int Rad;
public:
	CCircle(Point,int, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInFigure(int x, int y)const;
	virtual void Move(int newx, int newy);
	virtual void Resize(float);
	virtual CFigure* copy();
	virtual double getArea()const;
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
};

#endif