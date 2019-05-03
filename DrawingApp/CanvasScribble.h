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
protected:
	inline void onRender();
private:
	vector<Point> linePoints;
};

inline void CanvasScribble::onRender()
{
	UI->setPenColour(outlineColour, lineThickness);
	for (int i = 1; i < linePoints.size(); i++){
		UI->drawLine(linePoints.at(i - 1).x, linePoints.at(i - 1).y, linePoints.at(i).x, linePoints.at(i).y);
	}
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), lineThickness);
}


