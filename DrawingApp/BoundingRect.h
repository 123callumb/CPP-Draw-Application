#pragma once
// This class is fo the bounding box of objects, this will get the position of each corner + width/height
class BoundingRect
{
public:
	BoundingRect(int x, int y, int w, int h);
	~BoundingRect();
	int x, y, w, h;
	int p1[2], p2[2], p3[2]; // 0 = x & 1 = y e.g. top right coords would be x1 bottom right x3
	inline void setX(int x), setY(int y), setW(int w), setH(int h);
	inline bool isInside(int xPos, int yPos);
private:
	inline void resetCorners();
};

inline void BoundingRect::setX(int x) 
{ 
	this->x = x; 
	this->resetCorners();
}
inline void BoundingRect::setY(int y) 
{
	this->y = y;
	this->resetCorners();
}
inline void BoundingRect::setW(int w)
{ 
	this->w = w; 
	this->resetCorners();
}
inline void BoundingRect::setH(int h) { 
	this->h = h; 
	this->resetCorners();
}
inline void BoundingRect::resetCorners() {
	p1[0] = x + w;
	p1[1] = y;
	p2[0] = x;
	p2[1] = y + h;
	p3[0] = x + w;
	p3[1] = y + h;
}

inline bool BoundingRect::isInside(int xPos, int yPos){
	return ((xPos >= x) && (xPos <= p1[0]) && (yPos >= y) && (yPos <= p2[1]));
}