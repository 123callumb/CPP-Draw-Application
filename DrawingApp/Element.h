#pragma once
#include "EasyGraphics.h"
#include "BoundingArea.h"
// I plan for this class to be the core of most visual objects. Most objects seem like they require some sort of interaction like on click and drawing. (buttons and shapes etc)
// This is an abstract class, I don't beleive I want to use it on it's own.
class Element
{
public:
	Element(EasyGraphics* uiTool, int x, int y, int x1, int y1, int shapeType);
	~Element();

	inline void render(), click(int x, int y), hover(int x, int y);
	inline void setNewArea(BoundingArea * bArea);
	inline BoundingArea * getBoudingArea();
	inline BoundingArea * getCollisionArea();
protected:
	virtual void onClick(int x, int y) = 0, onRender() = 0;
	inline virtual void onHover(int x, int y), offHover(int x, int y); // This is incase we want to use the onHover with certain inheriters of the element
	bool hovering = false;
	EasyGraphics * UI;
	BoundingArea * area;
	BoundingArea * collisionArea; // To start with they have the same pointer address unless the collision area is altered
};

inline Element::Element(EasyGraphics * uiTool, int x, int y, int x1, int y1, int shapeType) : UI(uiTool), area(new BoundingArea(x, y, x1, y1, shapeType)), collisionArea(new BoundingArea(x, y, x1, y1, shapeType))
{
}

inline Element::~Element() {
	delete area;
	delete collisionArea;
}

inline void Element::render() {
	this->onRender();
}

inline BoundingArea * Element::getBoudingArea()
{
	return area;
}

inline BoundingArea * Element::getCollisionArea()
{
	return collisionArea;
}

inline void Element::click(int x, int y) {
	if (collisionArea->isInside(x, y)) {
		this->onClick(x, y);
		this->onRender();
	}
}

inline void Element::hover(int x, int y) {
 	if (collisionArea->isInside(x, y)) {
		hovering = true;
		this->onHover(x, y);
	}
	else if (hovering) {
		hovering = false;
		this->offHover(x, y);
	}
}

// This will also reset the collision area, so make sure if you need to change the collision change collisionArea after
inline void Element::setNewArea(BoundingArea * bArea)
{
	area = bArea;
	collisionArea = area;
}

inline void Element::offHover(int x, int y)
{
	this->onRender();
}

inline void Element::onHover(int x, int y)
{
	this->onRender();
}