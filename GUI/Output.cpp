#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1500;
	UI.height = 800;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 5;	//width of the figures frames

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\UnFill.jpg";
	MenuItemImages[ITM_FILLCOLOR] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_DRAWCOLOR] = "images\\MenuItems\\Menu_Draw.jpg";
	MenuItemImages[ITM_BGRCOLOR] = "images\\MenuItems\\Menu_BKColor.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Move.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_CHANGEWIDTH] = "images\\MenuItems\\ChangeWidth.jpg";
	MenuItemImages[ITM_ZOOM_IN] = "images\\MenuItems\\ZoomIn.jpg";
	MenuItemImages[ITM_ZOOM_OUT]= "images\\MenuItems\\ZoomOut.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[PLAYMODE] = "images\\MenuItems\\PlayMode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Redo.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0, UI.width, UI.ToolBarHeight);
}
void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayModesImages[PLAY_ITM_COUNT];
	PlayModesImages[PICKHIDE] = "images\\MenuItems\\Pick_Hide.jpg";
	PlayModesImages[SCRAMBLE] = "images\\MenuItems\\Scramble_Find.jpg";
	PlayModesImages[DRAWMODE] = "images\\MenuItems\\DrawMode.jpg";

	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayModesImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
void Output::PrintNumber(int N)const
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawInteger(5, UI.height - UI.StatusBarHeight+7, N);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

void Output::drawImg(int x, int y,int width,int height,const  string imagePath) const
{
	pWind->DrawImage(imagePath, x, y, width, height);
}
void Output::screenshot(image & img, int x, int y, int width, int height)
{
	pWind->StoreImage(img, x, y, width, height);
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawString(int x, int y, string str) const
{
	pWind->DrawString(x, y, str);
}

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawCirc(Point Cent, int Rad, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(Cent.x, Cent.y, Rad, style);

}

void Output::DrawTri(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x,P1.y, P2.x, P2.y,P3.x,P3.y,style);

}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const // Draw Line
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y,style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

