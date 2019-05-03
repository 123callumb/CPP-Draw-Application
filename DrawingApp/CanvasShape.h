#pragma once
#include "Element.h"
#include "GlobalSettings.h"


// The only thing that is really differnet betwee this and an element is the face that it draws the given shape and also sets a colour.
class CanvasShape :
	public Element
{
public:
	CanvasShape(EasyGraphics * currentInterface, BoundingArea * shapeArea, int fillColour, int outlineColour);
	~CanvasShape();
	void setFillColour(int colour), setOutlineColour(int colour);
	int getFillColour(), getOutlineColour();
protected:
	void onRender(), onClick(int x, int y);
	int outlineColour, lineThickness = 2;
private:
	int fillColour;
};
