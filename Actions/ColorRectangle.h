#pragma once
#include "Action.h"
class ColorRectangle : public Action
{
	Point P1,P2; //color window Corners(rectangle); second corner is known
	const int width = 13;// rectangle of one color
	const int height = 13;
	color chosencolor;
	int x, y;// pos of clicked color
	const color colors[144] = { SNOW,GHOSTWHITE,WHITESMOKE,GAINSBORO,FLORALWHITE,OLDLACE,LINEN,ANTIQUEWHITE,PAPAYAWHIP,
		BLANCHEDALMOND,BISQUE,PEACHPUFF,NAVAJOWHITE,MOCCASIN,CORNSILK,IVORY,LEMONCHIFFON,SEASHELL
		,HONEYDEW,MINTCREAM,AZURE,ALICEBLUE,LAVENDER,LAVENDERBLUSH,MISTYROSE,WHITE,
		BLACK,DARKSLATEGRAY,DARKSLATEGREY,DIMGRAY,DIMGREY,SLATEGRAY,SLATEGREY,
		LIGHTSLATEGRAY,LIGHTSLATEGREY,GRAY,GREY,LIGHTGREY,LIGHTGRAY,MIDNIGHTBLUE,
		NAVY,NAVYBLUE,CORNFLOWERBLUE,DARKSLATEBLUE,SLATEBLUE,MEDIUMSLATEBLUE,
		LIGHTSLATEBLUE,MEDIUMBLUE,ROYALBLUE,BLUE,DODGERBLUE,DEEPSKYBLUE,SKYBLUE,
		LIGHTSKYBLUE,STEELBLUE,LIGHTSTEELBLUE,LIGHTBLUE,POWDERBLUE,PALETURQUOISE,
		DARKTURQUOISE,MEDIUMTURQUOISE,TURQUOISE,CYAN,LIGHTCYAN,CADETBLUE,MEDIUMAQUAMARINE,AQUAMARINE,DARKGREEN,DARKOLIVEGREEN,DARKSEAGREEN,SEAGREEN,MEDIUMSEAGREEN,LIGHTSEAGREEN,PALEGREEN,SPRINGGREEN,LAWNGREEN,GREEN,CHARTREUSE,MEDIUMSPRINGGREEN,GREENYELLOW,LIMEGREEN,YELLOWGREEN,FORESTGREEN,OLIVEDRAB,DARKKHAKI,KHAKI,PALEGOLDENROD,LIGHTGOLDENRODYELLOW,LIGHTYELLOW,YELLOW,GOLD,LIGHTGOLDENROD,GOLDENROD,DARKGOLDENROD,ROSYBROWN,INDIAN,INDIANRED,SADDLEBROWN,SIENNA,PERU,BURLYWOOD,BEIGE,WHEAT,SANDYBROWN,TAN,CHOCOLATE,FIREBRICK,BROWN,DARKSALMON,SALMON,LIGHTSALMON,ORANGE,DARKORANGE,CORAL,LIGHTCORAL,TOMATO,ORANGERED,RED,HOTPINK,DEEPPINK,PINK,LIGHTPINK,PALEVIOLETRED,MAROON,MEDIUMVIOLETRED,VIOLETRED,MAGENTA,VIOLET,PLUM,ORCHID,MEDIUMORCHID,DARKORCHID,DARKVIOLET,BLUEVIOLET,PURPLE,MEDIUMPURPLE,THISTLE,DARKGREY,DARKGRAY,DARKBLUE,DARKCYAN,DARKMAGENTA,DARKRED,LIGHTGREEN };
public:
	ColorRectangle(ApplicationManager*pApp,int x);
	void DrawRect() const;
	virtual void ReadActionParameters();
	bool selectColor() ;// if color selected returned true and the color in chosencolor 
	color getcolor() const;
	void closeRect() const;
	//Add Line to the ApplicationManager
	virtual void Execute();
	~ColorRectangle();
};

