#include "buildGround.h"

BuildGround::BuildGround(Point pos, Point size): Ground(pos,size) {
	shape = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape());
	shape->setSize(sf::Vector2f(size.x, size.y));
	shape->setPosition(pos.x, pos.y);
	shape->setFillColor(sf::Color(100,200,50));
}

BuildGround::~BuildGround() {

}

void BuildGround::draw(sf::RenderWindow &window) {
	window.draw(*shape);
}

void BuildGround::update(float dt) {

}
