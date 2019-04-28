#include "Canvas.h"

Canvas::Canvas(EasyGraphics * currentInterface) : UI(currentInterface)
{
}


Canvas::~Canvas()
{
}

void Canvas::addToCanvas(BoundingArea elementBounds, int fillColour, int outlineColour) 
{
	CanvasShape * newShape = new CanvasShape(UI, elementBounds, fillColour, outlineColour);
	canvasElements.push_back(newShape);
}

void Canvas::render()
{
	for (int i = 0; i < canvasElements.size(); i++) {
		canvasElements.at(i)->render();
	}
}
