#include "Load.h"
#include "../Figures/CCircle.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CLine.h"
#include "..\ApplicationManager.h"
#include<fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iomanip>
Load::Load(ApplicationManager * pApp) :Action(pApp)
{}
void Load::ReadActionParameters()
{
	Output*pOut = pManager->GetOutput();
	Input*pIn = pManager->GetInput();
	pOut->PrintMessage("enter file name");
	filename = pIn->GetSrting(pOut);
	if (filename.empty())
		filename = "save";
	filename.append(".txt");
	pOut->PrintMessage("file Loaded");
}

//Execute the action
void Load::Execute()
{
	ifstream file;
	ReadActionParameters();
	file.open(filename);
	Output*pOut = pManager->GetOutput();
	pManager->deleteFigList();
	pManager->setColors(file);
	int Count;
	file >> Count;//number if figures
	for (size_t i = 0; i < Count; i++)
	{
		int type;
		file >> type;
		CFigure*fig = NULL;
		switch (type)
		{
		case circ:
			fig = new CCircle();
			break;
		case tri:
			fig = new CTriangle();
			break;
		case lin:
			fig = new CLine();
			break;
		case rect:
			fig = new CRectangle();
			break;
		}
		fig->Load(file);
		pManager->AddFigure(fig);
	}
	//pOut->ClearDrawArea();
	//pManager->UpdateInterface();
}
