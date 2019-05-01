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


// I shold move these into their respective tool classes -----------------------------------------------------

void Canvas::moveShape(int shapeIndex, int x, int y)
{
	BoundingArea * current = canvasElements.at(shapeIndex)->getBoudingArea();
	BoundingArea * currentColision = canvasElements.at(shapeIndex)->getCollisionArea();

	int x1 = x; //+(x - current->getX());
	int y1 = y;// +(y - current->getY());
	int x2 = x + (current->getX1() - current->getX());
	int y2 = y + (current->getY1() - current->getY());
	
	currentColision->setAll(x1, y1, x2, y2);
	current->setAll(x1, y1, x2, y2);
}

void Canvas::fillShape(int shapeIndex, int colour)
{
	canvasElements.at(shapeIndex)->setFillColour(colour);
}


void Canvas::deleteShape(int shapeIndex)
{
	// Erase calls delete on the pointer obejct I think...
	canvasElements.erase(canvasElements.begin() + shapeIndex);
}

void Canvas::fillOutline(int shapeIndex, int colour, int thickness)
{
	canvasElements.at(shapeIndex)->setOutlineColour(colour, thickness);
}

// ---------------------------------------------------------------------------------------------------

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

const vector<CanvasShape*> Canvas::getCanvasElements()
{
	return canvasElements;
}
