#pragma once

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInFigure(int x, int y)const;
	virtual CFigure* copy();
	virtual bool Move(int x, int y);
	virtual bool Resize(float);
	Point getCenter()const;
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	virtual double getArea()const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};
