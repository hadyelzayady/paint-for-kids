#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.
	Point Center;
	static unsigned int IDcounter;
public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void setCenter(int x,int y);
	Point getCenter()const;
	virtual double getArea()const=0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool isPointInFigure(int x, int y)const=0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void chngIsFilled(bool);
	void chngBorderWidth(int wid);
	GfxInfo getGfxInfo()const;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual CFigure* copy()=0;

	//virtual void Rotate() = 0;	//Rotate the figure
	virtual bool Resize(float) = 0;	//Resize the figure
	virtual bool Move(int x,int y)=0 ;		//Move the figure
	int getcolorIndex(color cl);
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) ;	//print all figure info on the status bar
};

#endif