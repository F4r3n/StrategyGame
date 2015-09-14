#include "statusBar.h"
#include "engineConst.h"

StatusBar::StatusBar(float position, sf::Color color): position(position), color(color) {
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(EngineConst::WIDTH, EngineConst::HEIGHT/5));
	shape->setPosition(0, EngineConst::HEIGHT*position);
	shape->setFillColor(color);
}

void StatusBar::draw(sf::RenderWindow &window) {
	window.draw(*shape);	
}


void StatusBar::drawPortrait(sf::RenderWindow &window, sf::RectangleShape *shape){
	window.draw(*shape);
}

void StatusBar::update(float dt) {

}


StatusBar::~StatusBar() {
	delete shape;
}
