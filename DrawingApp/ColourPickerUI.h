#pragma once
#include "EasyGraphics.h"
#include "GlobalSettings.h"
#include <vector>
#include "ControlColour.h"
#include <algorithm>
// I know there is a windows colour picker but it felt like cheating, I wanted it to look like this, serves the same function, just not as many colour selection.
class ColourPickerUI :
	public EasyGraphics
{
public:
	ColourPickerUI(bool forOutline, bool &isOpen);
	~ColourPickerUI();
	void prepareOpen(HINSTANCE hInstance);
	bool isOpen();
private:
	void onCreate(), onDraw(), onMouseMove(UINT nFlags, int x, int y), onLButtonDown(UINT nFlags, int x, int y), onDestroy();
	bool &open;
	bool isOutline = false;
	vector<ControlColour*> controlColours;
	int colourList[12] = {
		EasyGraphics::clBlack, EasyGraphics::clBlue, EasyGraphics::clCyan,
		EasyGraphics::clGreen, EasyGraphics::clGrey, EasyGraphics::clMagenta,
		EasyGraphics::clYellow, EasyGraphics::clWhite, EasyGraphics::clRed,
		EasyGraphics::clDarkGreen, EasyGraphics::clDarkRed, EasyGraphics::clDarkYellow
	};
};


