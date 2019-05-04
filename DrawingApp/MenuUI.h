#pragma once
#include "EasyGraphics.h"
#include <vector>
#include "Control.h"
#include "BoundingArea.h"
#include "ControlExpand.h"
#include "ControlColour.h"
#include "GlobalSettings.h"

using namespace std;

// This class is for the side menu.
class MenuUI 
{
public:
	MenuUI(EasyGraphics *currentUI);
	~MenuUI();
	void onDraw(), clickInteraction(int x, int y), hoverInteraction(int x, int y);
private:
	EasyGraphics *ui;
	vector<Control*> controls;
	const int controlW = 68, controlH = 55;

	const wchar_t * controlTextures[22] = { 
		L"Btn_Shapes.bmp", L"Btn_Shapes_Hover.bmp",
		L"Btn_Square.bmp", L"Btn_Square_Hover.bmp",
		L"Btn_Circle.bmp", L"Btn_Circle_Hover.bmp",
		L"Btn_Line.bmp", L"Btn_Line_Hover.bmp",
		L"Btn_Pen.bmp", L"Btn_Pen_Hover.bmp",
		L"Btn_Move.bmp", L"Btn_Move_Hover.bmp",
		L"Btn_Bin.bmp", L"Btn_Bin_Hover.bmp",
		L"Btn_Save.bmp", L"Btn_Save_Hover.bmp",
		L"Btn_Load.bmp", L"Btn_Load_Hover.bmp",
		L"Btn_Fill.bmp", L"Btn_Fill_Hover.bmp",
		L"Btn_Outline.bmp", L"Btn_Outline_Hover.bmp",
	};
};


