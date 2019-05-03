#include "CanvasScribble.h"


CanvasScribble::CanvasScribble(EasyGraphics * currentInterface, BoundingArea * shapeArea, int outlineColour, vector<Point> points) : CanvasShape(currentInterface, shapeArea, 0, outlineColour), linePoints(points)
{
}

CanvasScribble::~CanvasScribble()
{
}

