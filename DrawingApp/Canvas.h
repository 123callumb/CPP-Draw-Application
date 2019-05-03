#pragma once
#include "CanvasShape.h"
#include "BoundingArea.h"
#include "EasyGraphics.h"
#include "GlobalSettings.h"
#include <algorithm>

// Class that stores the position, colours etc of all draw elements.
using namespace std;

class Canvas
{
public:
	Canvas(EasyGraphics * currentInterface);
	~Canvas();
	void addToCanvas(BoundingArea * elementBounds, int fillColour, int outlineColour);
	void render(), moveShape(int shapeIndex, int x, int y, int dxy[3]), fillShape(int shapeIndex), fillOutline(int shapeIndex), deleteShape(int shapeIndex), clear();
	bool shapeExistsAt(int x, int y);
	int getShapeIndexAt(int x, int y);
	const vector<CanvasShape*> getCanvasElements();
private:
	vector<CanvasShape*> canvasElements;
	EasyGraphics * UI;
};

