#pragma once
#include "Tool.h"
#include "ColourPickerUI.h"

class ColourPicker : public Tool
{
public:
	ColourPicker(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * canvas, HINSTANCE currentInstance, bool forOutline);
	~ColourPicker();
	inline void onClickDown(int x, int y), onClickUp(int x, int y), renderGraphics();
protected:
	inline void onMove(int x, int y);
private:
	HINSTANCE currentInstance;
	bool isOutline = false, isOpen = false;
};

inline ColourPicker::ColourPicker(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * canvas, HINSTANCE currentInstance, bool forOutline) : Tool(currentInterface, iconName, canvas), currentInstance(currentInstance), isOutline(forOutline)
{
}

inline ColourPicker::~ColourPicker()
{
}

inline void ColourPicker::onClickDown(int x, int y)
{
	if (!isOpen) {
		ColourPickerUI * picker = new ColourPickerUI(isOutline, isOpen);
		picker->prepareOpen(currentInstance);
	}
}

inline void ColourPicker::onClickUp(int x, int y)
{
}

inline void ColourPicker::renderGraphics()
{
	UI->selectBackColour(UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 2);
	UI->drawRectangle(0, 0, 240, 30, true);
	UI->selectTextColour(UI->clWhite);
	UI->drawText(L"Click to Load Colour Palette", 5, 5);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

inline void ColourPicker::onMove(int x, int y)
{
}


