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
	void addToCanvas(BoundingArea * elementBounds, int fillColour, int outlineColour);
	void render(), moveShape(int shapeIndex, int x, int y), fillShape(int shapeIndex, int colour), fillOutline(int shapeIndex, int colour, int thickness), deleteShape(int shapeIndex);
	bool shapeExistsAt(int x, int y);
	int getShapeIndexAt(int x, int y);
private:
	vector<CanvasShape*> canvasElements;
	EasyGraphics * UI;
};

