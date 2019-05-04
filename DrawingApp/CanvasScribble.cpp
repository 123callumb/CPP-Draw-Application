#include "CanvasScribble.h"


CanvasScribble::CanvasScribble(EasyGraphics * currentInterface, BoundingArea * shapeArea, int outlineColour, vector<Point> points) : CanvasShape(currentInterface, shapeArea, 0, outlineColour)
{
	// We then take into account the bouding box and negate the top left coords so we can move the scribble with respect to the bouding box.
	for (vector<Point>::iterator p = points.begin(); p < points.end(); p++) {
		linePoints.push_back({ 
			p->x - area->getX(),
			p->y - area->getY() 
		});
	}
}

CanvasScribble::~CanvasScribble()
{
}

