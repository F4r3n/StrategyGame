#include "unit.h"
#include <iostream>

Unit::Unit() {
}

Unit::Unit(int belonging, Point pos, int life):ClickableObject(belonging) {
	currentPos = pos;
	this->life = life;
	actions.push_back(new Action(Move::STRAIGHT_AT_CLICK));
}

void Unit::draw(sf::RenderWindow &window){

}

bool  Unit::isGrouped() {
	return hasGroup;
}

void Unit::setGroup(bool val) {
	hasGroup = val;
}

void Unit::update(float dt, Point posMouse, Map *map) {
	casePosition = map->getPos(currentPos);
//	box->x = currentPos.x;
//	box->y = currentPos.y;
}

Unit::~Unit() {

}
