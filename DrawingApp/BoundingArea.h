#pragma once
// This is a bounding area surrouned by an element, used for seeing if the mouse is inside of the object.
class BoundingArea
{
public:
	BoundingArea(int x, int y, int x1, int y1, int shapeType);
	~BoundingArea();

	inline const int getX() const, getY() const, getX1() const, getY1() const;
	inline const int getShapeType();
	inline void setX(int v), setY(int v), setX1(int v), setY1(int v), setAll(int x, int y, int x1, int y1);
	bool isInside(int xPos, int yPos);

	const BoundingArea operator+ (const BoundingArea & rhs) const;

	static const int RECT = 0, CIRCLE = 1, LINE = 2;
protected:
	int x, y, x1, y1, shapeType;
};

inline const int BoundingArea::getX() const
{
	return x;
}

inline const int BoundingArea::getY() const
{
	return y;
}

inline const int BoundingArea::getX1() const
{
	return x1;
}

inline const int BoundingArea::getY1() const
{
	return y1;
}

inline const int BoundingArea::getShapeType() 
{
	return shapeType;
}

inline void BoundingArea::setX(int v)
{
	x = v;
}

inline void BoundingArea::setY1(int v)
{
	y1 = v;
}

inline void BoundingArea::setAll(int x, int y, int x1, int y1)
{
	this->x = x;
	this->y = y;
	this->x1 = x1;
	this->y1 = y1;
}

inline void BoundingArea::setY(int v)
{
	y = v;
}

inline void BoundingArea::setX1(int v)
{
	x1 = v;
}
