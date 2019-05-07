#pragma once
#include "EasyGraphics.h"
#include "Canvas.h"
#include <vector>
#include <algorithm>
#include "CanvasShape.h"
#include "LayerBox.h"

class LayerUI
{
public:
	LayerUI(EasyGraphics * currentInterface, Canvas * canvas);
	~LayerUI();
	void render(), onLDown(int x, int y), onLUp(int x, int y), onMove(int x, int y), updateLayers();
	inline BoundingArea getLayersArea();
private:
	EasyGraphics * UI;
	Canvas * canvas;
	vector<LayerBox*> layers;

	int startingIndex = 0;
	const int viewableLayers = 8;
	int pPosition = -1; // The position that the layer may be placed in
};

inline BoundingArea LayerUI::getLayersArea() {
	return BoundingArea(1010 - LayerBox::LAYER_W, 80, 1024, (LayerBox::LAYER_H * 8) + 120, BoundingArea::RECT);
}

