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



