#include "Canvas.h"

Canvas::Canvas(EasyGraphics * currentInterface) : UI(currentInterface)
{
}


Canvas::~Canvas()
{
}

void Canvas::addToCanvas(BoundingArea * elementBounds, int fillColour, int outlineColour) 
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
	BoundingArea * current = canvasElements.at(shapeIndex)->getBoudingArea();
	current->setX(x - (current->getX() - x));
	current->setY(y - (current->getY() - y));
	current->setX1(x + (x - current->getX1()));
	current->setY1(y + (y - current->getY1()));
}

void Canvas::fillShape(int shapeIndex, int colour)
{
	canvasElements.at(shapeIndex)->setFillColour(colour);
}

bool Canvas::shapeExistsAt(int x, int y)
{
	bool exists(false);
	int index(canvasElements.size() - 1);
	while (!exists && index > -1) {
		exists = canvasElements.at(index--)->getBoudingArea()->isInside(x, y);
	}
	return exists;
}



int Canvas::getShapeIndexAt(int x, int y)
{
	// ADD ASSERT HERE
	int index(canvasElements.size() - 1);
	CanvasShape * currentShape = canvasElements.at(index);
	while (!currentShape->getBoudingArea()->isInside(x, y)) {
		currentShape = canvasElements.at(index--);
	}
	return index + 1;
}
