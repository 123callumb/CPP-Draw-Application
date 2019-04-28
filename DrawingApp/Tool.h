#pragma once
#include "EasyGraphics.h"
#include "Canvas.h"

// Tool is an abstract class for tools such as a shape drawer, deleter and transformer etc.
// GOD THIS CLASS REALLY NEEDS CLEANING UP LIKE IT'S AWFUL
class Tool
{
public:
	Tool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas);
	~Tool();
	inline void move(int x, int y), renderIcon(), updateMouseIcon(int x, int y);
	virtual void onClickDown(int x, int y) = 0, onClickUp(int x, int y) = 0, renderGraphics() = 0;
protected:
	bool clickHeld = false;
	virtual void onMove(int x, int y) = 0;

	EasyGraphics * UI;
	Canvas * canvas;
private:
	int iconX = -50, iconY = -50;
	const wchar_t * iconFile;
};

inline void Tool::move(int x, int y) 
{
	onMove(x, y);
}

// This is just to draw the tool icon next to the mouse so the user knows what tool is selected!
inline void Tool::renderIcon()
{
	UI->drawBitmap(iconFile, iconX + 10, iconY + 10, 20, 20, UI->clWhite);
}


inline void Tool::updateMouseIcon(int x, int y)
{
	iconX = x;
	iconY = y;
}