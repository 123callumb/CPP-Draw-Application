#include "LoadTool.h"


LoadTool::LoadTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : Tool(currentInterface, iconName, currentCanvas)
{
}

LoadTool::~LoadTool()
{
}

void LoadTool::onClickDown(int x, int y)
{
	ifstream savedFile;
	savedFile.open("saveFile.txt", ifstream::in);
	try {
		if (savedFile.is_open() && !savedFile.fail()) {
			// Empty Current Canvas
			canvas->clear();
			while (!savedFile.eof()) {
				int shapeType, fColour, oColour, xPos, yPos, xPos1, yPos1;
				savedFile >> shapeType >> fColour >> oColour >> xPos >> yPos >> xPos1 >> yPos1;
				if (shapeType == BoundingArea::SCRIBBLE) {
					int pointCount;
					savedFile >> pointCount;
					vector<CanvasScribble::Point> points;
					for (int i = 0; i < pointCount; i++) {
						int pX, pY;
						savedFile >> pX >> pY;
						points.push_back({ pX, pY });
					}
					canvas->addScribble(points, new BoundingArea(xPos, yPos, xPos1, yPos1, shapeType), oColour);
				}
				else {
					canvas->addToCanvas(new BoundingArea(xPos, yPos, xPos1, yPos1, shapeType), fColour, oColour);
				}

			}
			savedFile.close();
		}
		else {

		}
	}
	catch (ios_base::failure) {
		error = true;
	}
}

void LoadTool::onClickUp(int x, int y)
{
}

void LoadTool::renderGraphics()
{
	UI->selectBackColour(UI->clDarkGrey);
	UI->setPenColour(UI->clBlack, 2);
	UI->drawRectangle(0, 0, 200, 30, true);
	UI->selectTextColour(UI->clWhite);
	UI->drawText(!error ? L"Click Canvas to Load File" : L"Could not Load File", 5, 5);
	UI->selectBackColour(GlobalSettings::getInstance()->getFillColour());
	UI->setPenColour(GlobalSettings::getInstance()->getOutlineColour(), 2);
}

void LoadTool::onMove(int x, int y)
{
	updateMouseIcon(x, y);
}
