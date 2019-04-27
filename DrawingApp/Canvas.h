#pragma once
#include "Element.h"
#include <vector>
// Class that stores the position, colours etc of all draw elements.
using namespace std;

class Canvas
{
public:
	Canvas();
	~Canvas();
	void addToCanvas(int p1[2], int p2[2], int fillColour, int outlineColour);
private:
	vector<Element*> canvasElements;
};

