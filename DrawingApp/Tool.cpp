#include "Tool.h"


Tool::Tool(EasyGraphics * currentInterface, const wchar_t * iconName, Canvas * currentCanvas) : UI(currentInterface), iconFile(iconName), canvas(currentCanvas)
{
}

Tool::~Tool()
{
	/*delete UI;
	delete iconFile;
	delete canvas;*/
}


