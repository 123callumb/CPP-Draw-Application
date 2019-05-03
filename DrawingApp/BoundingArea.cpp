#include "BoundingArea.h"

BoundingArea::BoundingArea(int x, int y, int x1, int y1, int shapeType) : x(x), y(y), x1(x1), y1(y1), shapeType(shapeType)
{
}

BoundingArea::~BoundingArea()
{
}

bool BoundingArea::isInside(int xPos, int yPos)
{
	int sX = x < x1 ? x : x1;
	int bX = sX == x ? x1 : x;
	int sY = y < y1 ? y : y1;
	int bY = sY == y ? y1 : y;

	switch (shapeType)
	{
	case CIRCLE:
		return (pow(xPos - x, 2) + pow(yPos - y, 2)) < pow(x1 - x, 2);
		break;
	default:
		return ((xPos >= sX) && (xPos <= bX) && (yPos >= sY) && (yPos < bY));
		break;
	} 

}
// This will return a bounding box that surrounds both elements.
const BoundingArea BoundingArea::operator+(const BoundingArea & rhs) const
{
	int coords[8] = {x, y, x1, y1, rhs.getX(), rhs.getY(), rhs.getX1(), rhs.getY1()};
	int sX(x), sY(y), bX(x), bY(y);  // Smallest x/y Biggest x/y determine the new box!
	for (int i = 2; i < 8; i+=2) {
		sX = sX > coords[i] ? coords[i] : sX;
		sY = sY > coords[i + 1] ? coords[i + 1] : sY;
		bX = bX < coords[i] ? coords[i] : bX;
		bY = bY < coords[i + 1] ? coords[i + 1] : bY;
	}
	return BoundingArea(sX, sY, bX, bY, RECT);
}
