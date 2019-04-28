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

void Canvas::moveShape(int shapeIndex, int x, int y)
{
	BoundingArea current = canvasElements.at(shapeIndex)->getBoudingArea();
	int newX = x - (current.getX() - x);
	int newY = y - (current.getY() - y);
	int newX1 = x + (x - current.getX1());
	int newY1 = y + (y - current.getY1());
	BoundingArea newArea(newX, newY, newX1, newY1, current.getShapeType());
	canvasElements.at(shapeIndex)->setNewArea(newArea);
}

bool Canvas::shapeExistsAt(int x, int y)
{
	bool exists(false);
	int index(canvasElements.size() - 1);
	while (!exists && index > -1) {
		exists = canvasElements.at(index--)->getBoudingArea().isInside(x, y);
	}
	return exists;
}



int Canvas::getShapeIndexAt(int x, int y)
{
	// ADD ASSERT HERE
	int index(canvasElements.size() - 1);
	CanvasShape * currentShape = canvasElements.at(index);
	while (!currentShape->getBoudingArea().isInside(x, y)) {
		currentShape = canvasElements.at(index--);
	}
	return index + 1;
}
