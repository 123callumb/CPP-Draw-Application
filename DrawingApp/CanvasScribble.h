#pragma once
#include "CanvasShape.h"
#include <vector>
#include <algorithm>

using namespace std;

class CanvasScribble :
	public CanvasShape
{
public:
	struct Point { 
		int x, y; 
	};

	CanvasScribble(EasyGraphics * currentInterface, BoundingArea * shapeArea, int outlineColour, vector<Point> points);
	~CanvasScribble();

	inline vector<Point> getPoints();
protected:
	inline void onRender();
private:
	vector<Point> linePoints;
};

inline CanvasScribble::CanvasScribble(EasyGraphics * currentInterface, BoundingArea * shapeArea, int outlineColour, vector<Point> points) : CanvasShape(currentInterface, shapeArea, 0, outlineColour)
{
	// We then take into account the bouding box and negate the top left coords so we can move the scribble with respect to the bouding box.
	for (vector<Point>::iterator p = points.begin(); p < points.end(); p++) {
		linePoints.push_back({
			p->x - area->getX(),
			p->y - area->getY()
			});
	}
}

inline void CanvasScribble::onRender()
{
	UI->setPenColour(outlineColour, lineThickness);
	for (int i = 1; i < linePoints.size(); i++){
		UI->drawLine(area->getX() + linePoints.at(i - 1).x,area->getY() + linePoints.at(i - 1).y, area->getX() + linePoints.at(i).x, area->getY() + linePoints.at(i).y);
	}
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), lineThickness);
}

inline vector<CanvasScribble::Point> CanvasScribble::getPoints()
{
	return linePoints;
}



