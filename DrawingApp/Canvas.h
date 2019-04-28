#pragma once
#include "CanvasShape.h"
#include "BoundingArea.h"
#include "EasyGraphics.h"

// Class that stores the position, colours etc of all draw elements.
using namespace std;

class Canvas
{
public:
	Canvas(EasyGraphics * currentInterface);
	~Canvas();
	void addToCanvas(BoundingArea elementBounds, int fillColour, int outlineColour);
	void render();
private:
	vector<CanvasShape*> canvasElements;
	EasyGraphics * UI;
};

