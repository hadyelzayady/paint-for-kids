#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <vector>
#include <stack>
#include <deque>
#include "Actions\Action.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	deque<Action*>actions;
	stack<Action*> Redo;
public:	
	void pushAction(Action*ac);
	Action* popAction();
	Action* RedoTop();
	//stack<Action*>undoed;
	bool isFilled;
	ApplicationManager();
	vector<CFigure*> copied;
	void deletecopied(vector<CFigure*>&arr);
	Point refPointPaste;
	Point refPoint;
	~ApplicationManager();
	int getFigCount()const
	{
		return FigCount;
	}
	CFigure** getFigList()
	{
		return FigList;
	}
	void unselectAll() const; // clicks on empty drawing area -> unselecct all
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void setColors(ifstream& file);
	void deleteFigList();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void DelFigure(CFigure* pFig,int index);
	void DelFigure(CFigure* pFig);
	void setFigCount(int n);
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int getcolorIndex(color cl);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif