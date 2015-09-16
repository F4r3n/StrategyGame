#include "unit.h"
#include <iostream>

Unit::Unit() {
}

Unit::Unit(int belonging, Point pos, int life):ClickableObject(belonging) {
	currentPos = pos;
	this->life = life;
}

void Unit::draw(sf::RenderWindow &window){

}

bool  Unit::isGrouped() {
	return hasGroup;
}

void Unit::setGroup() {
	hasGroup = true;
}

void Unit::update(float dt, Point posMouse) {
}

Unit::~Unit() {

}
