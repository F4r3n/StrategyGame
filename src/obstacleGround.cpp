
#include "obstacleGround.h"

ObstacleGround::ObstacleGround(Point pos, Point size): Ground(pos,size) {
	shape = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape());
	shape->setSize(sf::Vector2f(size.x, size.y));
	shape->setPosition(pos.x, pos.y);
	shape->setFillColor(sf::Color(200,200,200));
	walkable = false;
}

ObstacleGround::~ObstacleGround() {

}

void ObstacleGround::draw(sf::RenderWindow &window) {
	window.draw(*shape);
}

void ObstacleGround::update(float dt) {

}
