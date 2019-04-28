#pragma once
#include "Element.h"


// The only thing that is really differnet betwee this and an element is the face that it draws the given shape and also sets a colour.
class CanvasShape :
	public Element
{
public:
	CanvasShape(EasyGraphics * currentInterface, BoundingArea * shapeArea, int fillColour, int outlineColour);
	~CanvasShape();
protected:
	void onRender(), onClick(int x, int y);
private:
	int fillColour, outlineColour;
};
