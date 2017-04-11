#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar()const;
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2,Point P3 ,GfxInfo TriGfxInfo, bool selected = false) const;  //Draw a triangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const; // Draw Line
	void DrawCirc(Point Cent, int Rad, GfxInfo RectGfxInfo, bool selected) const;
	///Make similar functions for drawing all other figures.
	void drawImg(int x, int y,int width,int height) const;
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void PrintNumber(int N)const;
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif