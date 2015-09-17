#include "GUI.h"
#include <iostream>
GUI::GUI() {

}

GUI::GUI( Box *box, sf::Color color, sf::Color highlightColor): box(box), color(color), highlightColor(highlightColor) {
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(box->w, box->h));
	shape->setPosition(box->x, box->y);
	shape->setFillColor(color);
}

void GUI::draw(sf::RenderWindow &window) {
	window.draw(*shape);
}


Box* GUI::getBox() {
	return box;
}

bool GUI::cursorIn(float x, float y) {
	bool val = box->pointer(x,y);
	if(val) {
		shape->setFillColor(highlightColor);
	} else shape->setFillColor(color);
	return val;
}

GUI::~GUI() {
	delete shape;
	delete box;
//	delete shape;
}
