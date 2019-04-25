#include "Interface.h"


Interface::Interface(HINSTANCE hInstance) : controlMenu(this)
{
	setImmediateDrawMode(false);

	create(hInstance, 1024, 720, 120, true);
}

Interface::~Interface()
{
}

void Interface::onCreate()
{
	EasyGraphics::onCreate();
	::SetWindowText(getHWND(), L"Drawing Application");
}

void Interface::onDraw() {
	clrscr(clWhite);
	controlMenu.onDraw();
	EasyGraphics::onDraw();
}

void Interface::onMouseMove(UINT nFlags, int x, int y)
{
	controlMenu.hoverInteraction(x, y);
	onDraw();
;}

void Interface::onLButtonDown(UINT nFlags, int x, int y)
{
	controlMenu.clickInteraction(x, y);
	onDraw();
}
