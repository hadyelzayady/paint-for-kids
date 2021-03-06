#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\ChangeFillColor.h"
#include "Actions\ChangeDrawColor.h"
#include "Actions\ChangeBKColor.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\Scramble.h"
#include "Actions\PickAndHide.h"
#include "Actions\Copy.h"
#include "Actions\Paste.h"
#include "Actions\Cut.h"
#include "Actions\AddCircAct.h"
#include "Actions\FillingAct.h"
#include "Actions\Move.h"
#include "Actions\ResizeAction.h"
#include "Actions\ZoomIn.h"
#include "Actions\Save.h"
#include "Actions\ChangeWidth.h"
#include "Actions\Load.h"
#include <fstream>
#include "Actions\UndoAction.h"
using namespace std;
void ApplicationManager::pushAction(Action * ac)
{
	actions.push_front(ac);
	if (actions.size() == 101)
	{
		ac=actions.back();
		delete ac;
		actions.pop_back();
	}
}
Action* ApplicationManager::popAction()
{
	if (!actions.empty())
	{
		Action* ac = actions.front();
		actions.pop_front();
		return ac;
	}
	return NULL;

}
void ApplicationManager::popDelAction()
{
	if (!destrList.empty())
	{
		delete destrList.top();
		destrList.pop();
	}
}
void ApplicationManager::popActions()
{
	for (size_t i = 0; i < actions.size(); i++)
	{
		delete actions[i];
	}
	actions.clear();
	for (size_t i = 0; i < Redo.size(); i++)
	{
		delete Redo.top();
		Redo.pop();
	}

	
}
Action * ApplicationManager::RedoTop()
{
	if (!Redo.empty())
	{
		Action*ac = Redo.top();
		Redo.pop();
		return ac;
	}
	return NULL;
}
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	isFilled = false;
	FigCount = 0;
//	copied = NULL;
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
			pAct = new AddCircAction(this);
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
		case FILL:
			pAct = new FillingAct(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawColor(this);
			break;
		case CHNG_BK_CLR:
			pAct = new ChangeBKColor(this);
			break;
		case SELECT:
			unselectAll();
			pAct = new SelectAction(this);
			break;
		case MOVE:
			pAct = new Move(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case RESIZE:
			pAct = new ResizeAction(this);
			break;
		case ZOOMIN:
			pAct = new ZoomIn(this);
			break;
		case SAVE:
			unselectAll();
			pAct = new Save(this);
			break;
		case LOAD:
			unselectAll();
			popActions();
			pAct = new Load(this);
			break;
		case UNDO:
		{
			Action*ac = popAction();
			if (ac != NULL)
			{
				Redo.push(ac);
				ac->Undo();
				pOut->ClearDrawArea();
			}
			break;
		}
		case REDO:
		{
			Action*ac =  RedoTop();
			if (ac != NULL)
			{
				pushAction(ac);
				ac->Redo();
				pOut->ClearDrawArea();
			}
			break;
		}
		case TO_PLAY:
			unselectAll();// unselect all selected figures
			pOut->PrintMessage("Play Mode");
			pOut->CreatePlayToolBar();
			break;
		case CHANGE_WIDTH:
			pAct = new ChangeWidth(this);
			break;
		case EXIT:
			break;
		/////////////////////////////////////////////////////// Play Mode
		case PLAY_PICK_HIDE:
			pAct = new PickAndHide(this);
			break;
		case TO_DRAW:
		{
			pOut->PrintMessage("Draw Mode");
			pOut->CreateDrawToolBar();
			break;
		}
		
		case STATUS:	//a click on the status bar ==> no action
			return;
		default:
			unselectAll();// unselect all selected figures
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pushAction(pAct);
		pAct->Execute();//Execute// if exectute return true then action works well
		popDelAction();//to delete cancelled actions
		pAct = NULL;
	}
}
void ApplicationManager::setColors(ifstream & file)
{
	int colorindex;
	file >> colorindex;
	UI.DrawColor = colors[colorindex];
	file >> colorindex; 
	UI.FillColor = colors[colorindex];
	file >> colorindex; 
	UI.BkGrndColor = colors[colorindex];
}
void ApplicationManager::deleteFigList()
{
	for (size_t i = 0; i <FigCount ; i++)
	{
		delete FigList[i];
	}
	FigCount = 0;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
void ApplicationManager::unselectAll() const // clicks on empty drawing area -> unselecct all
{
	SelectAction::numOfSelected = 0;
	pOut->PrintMessage("All Unselected");
	for (int i = 0; i < FigCount; i++)
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
void ApplicationManager::DelFigure(CFigure * pFig)
{
	for (size_t i = 0; i < FigCount; i++)
	{
		if (FigList[i] == pFig)
		{
			delete pFig;
			FigCount--;
			FigList[i] = FigList[FigCount];
			FigList[FigCount] = NULL;
		}
	}
}
void ApplicationManager::removeFigFromList(int i)
{
	FigCount--;
	FigList[i] = FigList[FigCount];
	FigList[FigCount] = NULL;
}
void ApplicationManager::removeFigFromList(CFigure * fig)
{
	for (size_t i = 0; i < FigCount; i++)
	{
		if (FigList[i] ==fig)
		{
			FigCount--;
			FigList[i] = FigList[FigCount];
			FigList[FigCount] = NULL;
		}
	}
}
void ApplicationManager::deletecopied(vector<CFigure*>&arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		delete arr[i];
	}
	arr.clear();
}
void ApplicationManager::setFigCount(int n)
{
	FigCount = n;
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
int ApplicationManager::getcolorIndex(color cl)
{
	for (size_t i = 0; i < 144; i++)
	{
		if (cl == colors[i])
			return i;
	}
	return 0;
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
	for (size_t i = 0; i < actions.size(); i++)
	{
		delete actions[i];
	}
	for (size_t i = 0; i < Redo.size(); i++)
	{
		delete Redo.top();
		Redo.pop();
	}
}

void ApplicationManager::SaveFig(ofstream & os)
{
	for (size_t i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(os);
	}
}


bool ApplicationManager::getSelectedFigs(vector<CFigure*>& SelectedList)
{
	int i;
	for (i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			SelectedList.push_back(FigList[i]);
		}

	}
	return i == 0 ? false : true;
}
