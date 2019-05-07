#pragma once
#include "Element.h"
#include "CanvasShape.h"
// Layer box
class LayerBox :
	public Element
{
public:
	LayerBox(EasyGraphics * currentInterface, int xPos, int yPos, int shapeType, int layerNumber);
	~LayerBox();
	void onClickUp(int x, int y), onMove(int x, int y);
	static const int LAYER_H = 50, LAYER_W = 60;
protected:
	void onClick(int x, int y), onRender();
private:
	int shape = 0;
	int dy[2];
	bool dragging = false;
	int layerNo;
};

