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

void Canvas::addScribble(vector<CanvasScribble::Point> points, BoundingArea * elementBouds, int outlineColour)
{
	CanvasScribble * newScribble = new CanvasScribble(UI, elementBouds, outlineColour, points);
	canvasElements.push_back(newScribble);
}

void Canvas::render()
{
	// This seems more long windeed than a loop without the itterator?
	for_each(canvasElements.begin(), canvasElements.end(), [](CanvasShape * shape) {
		shape->render();
	});
}


// I shold move these into their respective tool classes -----------------------------------------------------

void Canvas::moveShape(int shapeIndex, int x, int y, int dxy[3])
{
	BoundingArea * current = canvasElements.at(shapeIndex)->getBoudingArea();
	BoundingArea * currentColision = canvasElements.at(shapeIndex)->getCollisionArea();

	int x1 = x + dxy[0];
	int y1 = y + dxy[1];
	int x2 = x + dxy[2];
	int y2 = y + dxy[3];
	
	currentColision->setAll(x1, y1, x2, y2);
	current->setAll(x1, y1, x2, y2);
}

void Canvas::fillShape(int shapeIndex)
{
	canvasElements.at(shapeIndex)->setFillColour(GlobalSettings::getInstance()->getFillColour());
}


void Canvas::deleteShape(int shapeIndex)
{
	// Erase calls delete on the pointer obejct I think...
	canvasElements.erase(canvasElements.begin() + shapeIndex);
}

void Canvas::clear()
{
	canvasElements.erase(canvasElements.begin(), canvasElements.end());
}

void Canvas::fillOutline(int shapeIndex)
{
	canvasElements.at(shapeIndex)->setOutlineColour(GlobalSettings::getInstance()->getOutlineColour());
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
	bool exists(false);
	int index(canvasElements.size() - 1);
	while (!exists && index > -1) {
		exists = canvasElements.at(index--)->getBoudingArea()->isInside(x, y);
	}
	return index + 1;
}

const vector<CanvasShape*> Canvas::getCanvasElements()
{
	return canvasElements;
}
