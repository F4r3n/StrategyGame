#include "case.h"
#include "engineConst.h"
#include <iostream>
Case::Case(Ground *gr){
	ground = std::unique_ptr<Ground>(gr);
	box = std::unique_ptr<Box>(new Box(gr->getPos(), gr->getSize()));
}

bool Case::isWalkable() {
	return ground->isWalkable();
}

void Case::setUnitOn(bool value) {
	ground->unitOn = value;
}

void Case::setString(const std::string &s) {
    ground->setString(s);
}

void Case::setVector(Point vector) {
    this->vector = vector;
}

Point Case::getVector() {
    return vector;
}

bool Case::isUnitOn() {
	return ground->unitOn;
}

void Case::draw(sf::RenderWindow &window) {
	sf::Vector2f s(window.getView().getSize());
	sf::Vector2f p(window.getView().getCenter());
//	std::cout << b.x << " " << b.y << " " << b.w << " " << b.h << std::endl;
	if(box->AABB(Point(p,-400,-300),Point(s)))
		ground->draw(window);
}
void Case::setWeight(int w) {
    weight = w;
    ground->setString(std::to_string(w));
}
int Case::getWeight() {
    return weight;
}

void Case::update(float dt) {
	ground->update(dt);
}

Case::~Case() {

}
