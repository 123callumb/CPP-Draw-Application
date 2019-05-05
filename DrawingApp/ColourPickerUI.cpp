#include "ColourPickerUI.h"



ColourPickerUI::ColourPickerUI(bool forOutline)
{
	setImmediateDrawMode(false);
	//SetWindowPos(getHWND(), NULL, 720, 200, 0, 0, SWP_NOZORDER | SWP_NOSIZE); // Err idk why ths doesn't work
	for (size_t i = 0; i < 12; i++) {
		int colNum = (i % 3);
		int rowNum = (i - colNum) / 3;
		controlColours.push_back(new ControlColour(Control(this, new BoundingArea(colNum * 68, rowNum * 55, (colNum * 68) + 68, (rowNum * 55) + 55, BoundingArea::RECT), L"Btn_FillColour.bmp", L"Btn_FillColour_Hover.bmp", i), colourList[i], forOutline));
	}
}


ColourPickerUI::~ColourPickerUI()
{
	for (size_t i = 0; i < controlColours.size(); i++) {
		delete controlColours.at(i);
	}
	controlColours.clear();
}

void ColourPickerUI::prepareOpen(HINSTANCE hInstance)
{
	open = true;
	create(hInstance, 220, 258, 120, true);
	
}

bool ColourPickerUI::isOpen()
{
	return open;
}

void ColourPickerUI::onCreate()
{
	EasyGraphics::onCreate();
	::SetWindowText(getHWND(), L"Colour Picker");
}

void ColourPickerUI::onDraw()
{
	clrscr(clWhite);
	for (size_t i = 0; i < controlColours.size(); i++) {
		controlColours.at(i)->render();
	}
	EasyGraphics::onDraw();
}

void ColourPickerUI::onMouseMove(UINT nFlags, int x, int y)
{
	for (size_t i = 0; i < controlColours.size(); i++) {
		controlColours.at(i)->hover(x, y);
	}
	onDraw();
}

void ColourPickerUI::onLButtonDown(UINT nFlags, int x, int y)
{
	for (size_t i = 0; i < controlColours.size(); i++) {
		controlColours.at(i)->click(x, y);
	}
	onDraw();
}

void ColourPickerUI::onDestroy()
{
	waitForClose();
	EasyGraphics::onDestroy();
	delete this;
}
