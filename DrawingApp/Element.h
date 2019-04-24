#pragma once
#include "EasyGraphics.h"
#include "BoundingRect.h"
// I plan for this class to be the core of most visual objects. Most objects seem like they require some sort of interaction like on click and drawing. (buttons and shapes etc)
// This is an abstract class, I don't beleive I want to use it on it's own.
class Element
{
public:
	Element(EasyGraphics* uiTool, BoundingRect bRect);
	~Element();
	inline void render(), click(int x, int y), hover(int x, int y);
protected:
	virtual void onClick() = 0, onRender() = 0;
	inline virtual void onHover(), offHover(); // This is incase we want to use the onHover with certain inheriters of the element
	bool hovering = false;
	EasyGraphics *UI;
	BoundingRect rect;
};

inline void Element::render() {
	this->onRender();
}

inline void Element::click(int x, int y) {
	if (rect.isInside(x, y)) {
		this->onClick();
		this->onRender();
	}
}

inline void Element::hover(int x, int y) {
	if (rect.isInside(x, y)) {
		hovering = true;
		this->onHover();
	}
	else if (hovering) {
		hovering = false;
		this->offHover();
	}
}

inline void Element::offHover()
{
	this->onRender();
}

inline void Element::onHover()
{
	this->onRender();
}



