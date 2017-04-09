#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\ChangeFillColor.h"
#include "Actions\ChangeDrawColor.h"
#include "Actions\ChangeBKColor.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	copied = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			unselectAll();// unselect all selected figures
			break;
		case DRAW_CIRC:

			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			unselectAll();// unselect all selected figures
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			unselectAll();// unselect all selected figures
			break;
		case CHNG_FILL_CLR:
			pAct = new ChangeFillColor(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawColor(this);
			break;
		case CHNG_BK_CLR:
			pAct = new ChangeBKColor(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case TO_PLAY:
			pOut->PrintMessage("Play Mode");
			pOut->CreatePlayToolBar();
			break;
		case TO_DRAW:
		{
			pOut->PrintMessage("Play Mode");
			pOut->CreateDrawToolBar();
			break;
		}
		case EXIT:
			///create ExitAction here
			
			break;
		default:
			unselectAll();// unselect all selected figures
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
void ApplicationManager::unselectAll() const // clicks on empty drawing area -> unselecct all
{
	SelectAction::numOfSelected = 0;
	pOut->PrintMessage("All Unselected");
	for (size_t i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
}
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
void ApplicationManager::DelFigure(CFigure* pFig,int index)
{
	//pOut->DrawRect(pFig->)
	delete pFig;
	FigCount--;
	FigList[index] = FigList[FigCount];
	FigList[FigCount] = NULL;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (size_t i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isPointInFigure(x, y))
			return FigList[i];
	}

	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
