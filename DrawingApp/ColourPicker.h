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
	bool isOutline = false;
};

inline ColourPicker::ColourPicker(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * canvas, HINSTANCE currentInstance, bool forOutline) : Tool(currentInterface, iconName, canvas), currentInstance(currentInstance), isOutline(forOutline)
{
}

inline ColourPicker::~ColourPicker()
{
}

inline void ColourPicker::onClickDown(int x, int y)
{
	ColourPickerUI * picker = new ColourPickerUI(isOutline);
	picker->prepareOpen(currentInstance);
	picker->waitForClose();
}

inline void ColourPicker::onClickUp(int x, int y)
{
}

inline void ColourPicker::renderGraphics()
{
}

inline void ColourPicker::onMove(int x, int y)
{
}


