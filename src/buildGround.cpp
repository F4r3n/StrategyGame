#include "buildGround.h"

BuildGround::BuildGround(Point pos, Point size, sf::Font *font): Ground(pos,size, font) {
	shape = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape());
	shape->setSize(sf::Vector2f(size.x, size.y));
	shape->setPosition(pos.x, pos.y);
	shape->setFillColor(sf::Color(100,200,50));
	shape->setOutlineThickness(5);
	shape->setOutlineColor(sf::Color::Black);
	walkable = true;
}

BuildGround::~BuildGround() {

}


void BuildGround::draw(sf::RenderWindow &window) {
	window.draw(*shape);
    Ground::draw(window);
}

void BuildGround::update(float dt) {

}
