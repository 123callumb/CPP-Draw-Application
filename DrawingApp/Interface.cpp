#include "Interface.h"


Interface::Interface(HINSTANCE hInstance) : hInst(hInstance), canvas(Canvas(this)), controlMenu(MenuUI(this)), tools(Tools(this, &canvas, hInst))
{
	setImmediateDrawMode(false);

	create(hInst, 1024, 720, 120, true);
}

Interface::~Interface()
{
}

void Interface::onClose()
{
	canvas.onClose();
	tools.onClose();
	controlMenu.onClose();
	GlobalSettings::getInstance()->onClose();
}

void Interface::onCreate()
{
	EasyGraphics::onCreate();
	::SetWindowText(getHWND(), L"Drawing Application");
}

void Interface::onDraw() {
	clrscr(clWhite);
	canvas.render();
	tools.renderCurrrentToolIcon();
	tools.renderCurrentToolGraphics();
	controlMenu.onDraw();
	EasyGraphics::onDraw();
}

void Interface::onMouseMove(UINT nFlags, int x, int y)
{
	controlMenu.hoverInteraction(x, y);
	tools.currentToolMovement(x, y);
	onDraw();
}

void Interface::onLButtonDown(UINT nFlags, int x, int y)
{
	controlMenu.clickInteraction(x, y);
	// Make sure we dont activate the tool while inside of the menu area.
	if (!controlMenu.getMenuArea().isInside(x, y)) {
		tools.currerntToolDown(x, y);
	}
	onDraw();
}

void Interface::onLButtonUp(UINT nFlags, int x, int y)
{
	if (!controlMenu.getMenuArea().isInside(x, y)) {
		tools.currrentToolUp(x, y);
	}
	onDraw();
}


void Interface::onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_SHIFT || nChar == VK_SHIFT) {
		GlobalSettings::getInstance()->setShiftDown(true);
	}
	clrscr(clWhite);
}

void Interface::onKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_SHIFT || nChar == VK_SHIFT) {
		GlobalSettings::getInstance()->setShiftDown(false);
	}
	clrscr(clWhite);
}
