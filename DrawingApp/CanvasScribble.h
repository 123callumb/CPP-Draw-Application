#pragma once
#include "CanvasShape.h"
#include <vector>

using namespace std;

class CanvasScribble :
	public CanvasShape
{
public:
	CanvasScribble(EasyGraphics * currentInterface, BoundingArea * shapeArea, int outlineColour);
	~CanvasScribble();

	struct Point {int x, y;};
private:
	vector<Point> linePoints;
};

