#include "clickableObject.h"
#include "engineConst.h"


ClickableObject::ClickableObject(int belonging): belonging(belonging){
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(50, 50));
	shape->setPosition(20, EngineConst::WIDTH*0.7);
	shape->setFillColor(sf::Color::White);
}

ClickableObject::ClickableObject() {}

void ClickableObject::update(float dt, Point posMouse, StatusBar *statusBar) {

}

void ClickableObject::draw(sf::RenderWindow &window){
}

ClickableObject::~ClickableObject() {

}


