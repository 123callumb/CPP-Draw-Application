#pragma once
#include "Control.h"
class ControlColour :
	public Control
{
public:
	ControlColour(EasyGraphics * currentInterface, int x, int y, int x1, int y1, int shapeType, const wchar_t * imageFile, const wchar_t * imageHover, int colour, bool isOutline);
	~ControlColour();
protected: 
	void onRender(), onClick(int x, int y);
private:
	int colour; 
	bool outline = false;
};

