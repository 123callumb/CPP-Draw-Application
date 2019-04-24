#include "BoundingRect.h"

BoundingRect::BoundingRect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
{
	resetCorners();
}

BoundingRect::~BoundingRect()
{
}


