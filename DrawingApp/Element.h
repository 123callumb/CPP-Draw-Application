#pragma once
#include "EasyGraphics.h"
#include "BoundingArea.h"
// I plan for this class to be the core of most visual objects. Most objects seem like they require some sort of interaction like on click and drawing. (buttons and shapes etc)
// This is an abstract class, I don't beleive I want to use it on it's own.
class Element
{
public:
	Element(EasyGraphics* uiTool, BoundingArea bArea);
	~Element();

	inline void render(), click(int x, int y), hover(int x, int y);
	inline void setCollisionArea(BoundingArea bArea); // Some elements may have a collision box different to their actual visual size.
	inline void setNewArea(BoundingArea bArea);
	inline BoundingArea getBoudingArea();
protected:
	virtual void onClick(int x, int y) = 0, onRender() = 0;
	inline virtual void onHover(int x, int y), offHover(int x, int y); // This is incase we want to use the onHover with certain inheriters of the element
	bool hovering = false;
	EasyGraphics * UI;
	BoundingArea area,  collisionArea; // Set by default just outside of the screen just incase
};

inline void Element::render() {
	this->onRender();
}

inline BoundingArea Element::getBoudingArea()
{
	return area;
}

inline void Element::click(int x, int y) {
	if (collisionArea.isInside(x, y)) {
		this->onClick(x, y);
		this->onRender();
	}
}

inline void Element::hover(int x, int y) {
 	if (collisionArea.isInside(x, y)) {
		hovering = true;
		this->onHover(x, y);
	}
	else if (hovering) {
		hovering = false;
		this->offHover(x, y);
	}
}

inline void Element::setCollisionArea(BoundingArea bArea)
{
	collisionArea = bArea;
}

inline void Element::setNewArea(BoundingArea bArea)
{
	area = bArea;
}

inline void Element::offHover(int x, int y)
{
	this->onRender();
}

inline void Element::onHover(int x, int y)
{
	this->onRender();
}