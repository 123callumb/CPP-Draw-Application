#include "SaveTool.h"



SaveTool::SaveTool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : Tool(currentInterface, iconName, currentCanvas)
{
}


SaveTool::~SaveTool()
{
}

void SaveTool::onClickDown(int x, int y)
{
	OutputDebugStringW(L"Calling Save method");
	// Save to file function
	ofstream saveFile;
	saveFile.open("saveFile.txt");
	if (saveFile.is_open()) {
		vector<CanvasShape*> s = canvas->getCanvasElements();
		saveFile.clear();
		//TODO: itterator here
		for (size_t i = 0; i < s.size(); i++) {
			saveFile << s.at(i)->getBoudingArea()->getShapeType() << " ";
			saveFile << s.at(i)->getFillColour() << " ";
			saveFile << s.at(i)->getOutlineColour() << " ";
			saveFile << s.at(i)->getBoudingArea()->getX() << " ";
			saveFile << s.at(i)->getBoudingArea()->getY() << " ";
			saveFile << s.at(i)->getBoudingArea()->getX1() << " ";
			saveFile << s.at(i)->getBoudingArea()->getY1() << " ";
			// If the rest of the shape is a scribble then store all the line points after it.
			if (s.at(i)->getBoudingArea()->getShapeType() == BoundingArea::SCRIBBLE) {
				vector<CanvasScribble::Point> scribPoints = dynamic_cast<CanvasScribble*>(s.at(i))->getPoints();
				saveFile << scribPoints.size() << " "; // Store the amount of points so loading the file is easier.
				for (int p = 0; p < scribPoints.size(); p++) {
					saveFile <<  scribPoints.at(p).x  + s.at(i)->getBoudingArea()->getX() << " " << scribPoints.at(p).y + s.at(i)->getBoudingArea()->getY() << " ";
				}
			}
			saveFile << "\n";
		}
		saveFile.close();
	}
}

void SaveTool::onClickUp(int x, int y)
{
}

void SaveTool::renderGraphics()
{
	UI->selectTextColour(UI->clBlack);
	UI->drawText(L"Click to save file", 0, 0);
}

void SaveTool::onMove(int x, int y)
{
}
