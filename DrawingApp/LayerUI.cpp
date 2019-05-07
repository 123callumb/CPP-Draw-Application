#include "LayerUI.h"



LayerUI::LayerUI(EasyGraphics * currentInterface, Canvas * canvas) : UI(currentInterface), canvas(canvas)
{
}


LayerUI::~LayerUI()
{
}

void LayerUI::render()
{	
	// Create base for layers to sit on
	UI->drawBitmap(L"Btn_Up.bmp", 1010 - LayerBox::LAYER_W, 80, LayerBox::LAYER_W, 20, UI->clWhite);
	UI->drawBitmap(L"Btn_Down.bmp", 1010 - LayerBox::LAYER_W, 100 + LayerBox::LAYER_H * 8, LayerBox::LAYER_W, 20, UI->clWhite);
	UI->selectBackColour(UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 1);
	UI->drawRectangle(1010 - LayerBox::LAYER_W, 100, LayerBox::LAYER_W, LayerBox::LAYER_H * viewableLayers, true);
	 // then render the layers
	for (size_t i = 0; i < layers.size(); i++) {
		layers.at(i)->render();
	}
}

void LayerUI::onLDown(int x, int y)
{
	// This is a simple way to navigate the layers bar.
	startingIndex = (x > 950) && (x < 1024) && (y > 80) && (y < 100) && (startingIndex != 0) ? startingIndex - 1 : startingIndex;
	startingIndex = (x > 950) && (x < 1024) && (y > 500) && (y < 520) && ((startingIndex + viewableLayers) < canvas->getCanvasElements().size()) ? startingIndex + 1 : startingIndex;

	for (size_t i = 0; i < layers.size(); i++) {
		layers.at(i)->click(x, y);
	}
}

void LayerUI::onLUp(int x, int y)
{
	for (size_t i = 0; i < layers.size(); i++) {
		layers.at(i)->onClickUp(x, y);
	}

	int selectedLayer = GlobalSettings::getInstance()->getSelectedLayer();
	if (selectedLayer > -1 && y > 100 && y < 500) {
		// Current mid point of selected box
		int newPosition = ((y - y % 50) - 100) / 50;
		canvas->rearangePosition(selectedLayer, newPosition + startingIndex);
	}

	GlobalSettings::getInstance()->setSelectedLayer(-1);
	updateLayers();
}

void LayerUI::onMove(int x, int y)
{
	for (size_t i = 0; i < layers.size(); i++) {
		layers.at(i)->onMove(x, y);
		layers.at(i)->hover(x, y);
	}
}

void LayerUI::updateLayers()
{
	// Destry current layers to replace them with the new values
	for_each(layers.begin(), layers.end(), [](LayerBox * layer) {
		delete layer;
	});
	layers.erase(layers.begin(), layers.end());

	// Set new layers 
	vector<CanvasShape*> currentShapes = canvas->getCanvasElements();
	size_t loopAmount = currentShapes.size() < viewableLayers ? currentShapes.size() : viewableLayers;
	
	for (size_t i = startingIndex; i < (startingIndex + loopAmount); i++) {
		layers.push_back(new LayerBox(UI, 1010 - LayerBox::LAYER_W, 100 + (((int)i - startingIndex) * LayerBox::LAYER_H), currentShapes.at(i)->getBoudingArea()->getShapeType(), (int)i));
	}
}