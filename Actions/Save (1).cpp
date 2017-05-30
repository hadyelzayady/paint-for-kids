#include "Save.h"

#include "..\ApplicationManager.h"
#include<fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iomanip>
Save::Save(ApplicationManager * pApp) :Action(pApp)
{}
void Save::ReadActionParameters()
{
	Output*pOut=pManager->GetOutput();
	Input*pIn = pManager->GetInput();
	pOut->PrintMessage("enter file name");
	filename=pIn->GetSrting(pOut);
	if (filename.empty())
		filename = "save";
	filename.append(".txt");
	pOut->PrintMessage("file saved");
}

//Execute the action
void Save::Execute()
{
	ReadActionParameters();
	size_t Count=pManager->getFigCount();
	ofstream file;
	file.open(filename);
	CFigure** FigList = pManager->getFigList();
	Output*pOut = pManager->GetOutput();
	int drawcolorindex = pManager->getcolorIndex(pOut->getCrntDrawColor());
	int fillcolorindex = pManager->getcolorIndex(pOut->getCrntFillColor());
	int bgrcolorindex = pManager->getcolorIndex(UI.BkGrndColor);
	file << drawcolorindex <<setw(8)<<fillcolorindex<<setw(8)<<bgrcolorindex<<endl<<pManager->getFigCount()<<endl;
	for (size_t i = 0; i < Count; i++)
	{
		FigList[i]->Save(file);
	}
}
