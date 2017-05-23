#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	FILL,
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	SELECT,			// select figures
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	CHANGE_WIDTH,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	PLAY_PICK_HIDE,
	PLAY_SCAMBLE_FIND,
	COPY,
	PASTE,
	CUT,
	ZOOMIN,
	ZOOMOUT,
	///TODO: Add more action types (if needed)
	UNDO,
	REDO,
};
enum Type {
	rect,
	circ,
	lin,
	tri
};
struct Point	//To be used for figures points
{ int x,y; };

const color colors[144] = { SNOW,
GHOSTWHITE,
WHITESMOKE,
GAINSBORO,
FLORALWHITE,
OLDLACE,
LINEN,
ANTIQUEWHITE,
PAPAYAWHIP,
BLANCHEDALMOND,
BISQUE,
PEACHPUFF,
NAVAJOWHITE,
MOCCASIN,
CORNSILK,
IVORY,
LEMONCHIFFON,
SEASHELL,
HONEYDEW,
MINTCREAM,
AZURE,
ALICEBLUE,
LAVENDER,
LAVENDERBLUSH,
MISTYROSE,
WHITE,
BLACK,
DARKSLATEGRAY,
DARKSLATEGREY,
DIMGRAY,
DIMGREY,
SLATEGRAY,
SLATEGREY,
LIGHTSLATEGRAY,
LIGHTSLATEGREY,
GRAY,
GREY,
LIGHTGREY,
LIGHTGRAY,
MIDNIGHTBLUE,
NAVY,
NAVYBLUE,
CORNFLOWERBLUE,
DARKSLATEBLUE,
SLATEBLUE,
MEDIUMSLATEBLUE,
LIGHTSLATEBLUE,
MEDIUMBLUE,
ROYALBLUE,
BLUE,
DODGERBLUE,
DEEPSKYBLUE,
SKYBLUE,
LIGHTSKYBLUE,
STEELBLUE,
LIGHTSTEELBLUE,
LIGHTBLUE,
POWDERBLUE,
PALETURQUOISE,
DARKTURQUOISE,
MEDIUMTURQUOISE,
TURQUOISE,
CYAN,
LIGHTCYAN,
CADETBLUE,
MEDIUMAQUAMARINE,
AQUAMARINE,
DARKGREEN,
DARKOLIVEGREEN,
DARKSEAGREEN,
SEAGREEN,
MEDIUMSEAGREEN,
LIGHTSEAGREEN,
PALEGREEN,
SPRINGGREEN,
LAWNGREEN,
GREEN,
CHARTREUSE,
MEDIUMSPRINGGREEN,
GREENYELLOW,
LIMEGREEN,
YELLOWGREEN,
FORESTGREEN,
OLIVEDRAB,
DARKKHAKI,
KHAKI,
PALEGOLDENROD,
LIGHTGOLDENRODYELLOW,
LIGHTYELLOW,
YELLOW,
GOLD,
LIGHTGOLDENROD,
GOLDENROD,
DARKGOLDENROD,
ROSYBROWN,
INDIAN,
INDIANRED,
SADDLEBROWN,
SIENNA,
PERU,
BURLYWOOD,
BEIGE,
WHEAT,
SANDYBROWN,
TAN,
CHOCOLATE,
FIREBRICK,
BROWN,
DARKSALMON,
SALMON,
LIGHTSALMON,
ORANGE,
DARKORANGE,
CORAL,
LIGHTCORAL,
TOMATO,
ORANGERED,
RED,
HOTPINK,
DEEPPINK,
PINK,
LIGHTPINK,
PALEVIOLETRED,
MAROON,
MEDIUMVIOLETRED,
VIOLETRED,
WHITERED,
VIOLET,
PLUM,
ORCHID,
MEDIUMORCHID,
DARKORCHID,
DARKVIOLET,
BLUEVIOLET,
PURPLE,
MEDIUMPURPLE,
THISTLE,
DARKGREY,
DARKGRAY,
DARKBLUE,
DARKCYAN,
DARKMAGENTA,
DARKRED,
LIGHTGREEN };

enum ecolors {
	eSNOW,
	eGHOSTWHITE,
	eWHITESMOKE,
	eGAINSBORO,
	eFLORALWHITE,
	eOLDLACE,
	eLINEN,
	eANTIQUEWHITE,
	ePAPAYAWHIP,
	eBLANCHEDALMOND,
	eBISQUE,
	ePEACHPUFF,
	eNAVAJOWHITE,
	eMOCCASIN,
	eCORNSILK,
	eIVORY,
	eLEMONCHIFFON,
	eSEASHELL,
	eHONEYDEW,
	eMINTCREAM,
	eAZURE,
	eALICEBLUE,
	eLAVENDER,
	eLAVENDERBLUSH,
	eMISTYROSE,
	eWHITE,
	eBLACK,
	eDARKSLATEGRAY,
	eDARKSLATEGREY,
	eDIMGRAY,
	eDIMGREY,
	eSLATEGRAY,
	eSLATEGREY,
	eLIGHTSLATEGRAY,
	eLIGHTSLATEGREY,
	eGRAY,
	eGREY,
	eLIGHTGREY,
	eLIGHTGRAY,
	eMIDNIGHTBLUE,
	eNAVY,
	eNAVYBLUE,
	eCORNFLOWERBLUE,
	eDARKSLATEBLUE,
	eSLATEBLUE,
	eMEDIUMSLATEBLUE,
	eLIGHTSLATEBLUE,
	eMEDIUMBLUE,
	eROYALBLUE,
	eBLUE,
	eDODGERBLUE,
	eDEEPSKYBLUE,
	eSKYBLUE,
	eeBLUE,
	eLIGHTSKYBLUE,
	eSTEELBLUE,
	eLIGHTSTEELBLUE,
	eLIGHTBLUE,
	ePOWDERBLUE,
	ePALETURQUOISE,
	eDARKTURQUOISE,
	eMEDIUMTURQUOISE,
	eTURQUOISE,
	eCYAN,
	eLIGHTCYAN,
	eCADETBLUE,
	eMEDIUMAQUAMARINE,
	eAQUAMARINE,
	eDARKGREEN,
	eDARKOLIVEGREEN,
	eDARKSEAGREEN,
	eSEAGREEN,
	eMEDIUMSEAGREEN,
	eLIGHTSEAGREEN,
	ePALEGREEN,
	eSPRINGGREEN,
	eLAWNGREEN,
	eGREEN,
	eCHARTREUSE,
	eMEDIUMSPRINGGREEN,
	eGREENYELLOW,
	eLIMEGREEN,
	eYELLOWGREEN,
	eFORESTGREEN,
	eOLIVEDRAB,
	eDARKKHAKI,
	eKHAKI,
	ePALEGOLDENROD,
	eLIGHTGOLDENRODYELLOW,
	eLIGHTYELLOW,
	eYELLOW,
	eGOLD,
	eLIGHTGOLDENROD,
	eGOLDENROD,
	eDARKGOLDENROD,
	eROSYBROWN,
	eINDIAN,
	eINDIANRED,
	eSADDLEBROWN,
	eSIENNA,
	ePERU,
	eBURLYWOOD,
	eBEIGE,
	eWHEAT,
	eSANDYBROWN,
	eTAN,
	eCHOCOLATE,
	eFIREBRICK,
	eBROWN,
	eDARKSALMON,
	eSALMON,
	eLIGHTSALMON,
	eORANGE,
	eDARKORANGE,
	eCORAL,
	eLIGHTCORAL,
	eTOMATO,
	eORANGERED,
	eRED,
	eHOTPINK,
	eDEEPPINK,
	ePINK,
	eLIGHTPINK,
	ePALEVIOLETRED,
	eMAROON,
	eMEDIUMVIOLETRED,
	eVIOLETRED,
	eVIOLET,
	ePLUM,
	eORCHID,
	eMEDIUMORCHID,
	eDARKORCHID,
	eDARKVIOLET,
	eBLUEVIOLET,
	ePURPLE,
	eMEDIUMPURPLE,
	eTHISTLE,
	eDARKGREY,
	eDARKGRAY,
	eDARKBLUE,
	eDARKCYAN,
	eDARKMAGENTA,
	eDARKRED,
	eLIGHTGREEN
};
struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif