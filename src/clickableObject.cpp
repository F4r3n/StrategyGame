#include "clickableObject.h"
#include "engineConst.h"

ClickableObject::ClickableObject(int belonging, StatusBar *statusBar): belonging(belonging), statusBar(statusBar) {
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(50, 50));
	shape->setPosition(20, EngineConst::WIDTH*0.7);
	shape->setFillColor(sf::Color::White);
}

void ClickableObject::draw(sf::RenderWindow &window){
	statusBar->drawPortrait(window,shape);
}

ClickableObject::~ClickableObject() {

}


