#include "unit.h"
#include <math.h>
#include <iostream>
Unit::Unit() {
}

Unit::Unit(int belonging, Point pos, int life):ClickableObject(belonging) {
	currentPos = pos;
	this->life = life;
	x = pos.x;
	y = pos.y;
	path = new std::vector<Point>();

}

void Unit::draw(sf::RenderWindow &window){

}

bool  Unit::isGrouped() {
	return hasGroup;
}

int Unit::getIdGroup() {
	return idGroup;
}

void Unit::setIdGroup(int id) {
	idGroup = id;
}

void Unit::initPathFinder(Map *map) {
	pathFinder = new PathFinder(map);
}

void Unit::setDestination(Point pos) {
	arrivalPos = pos;
	pathFinder->setDestination(casePosition,pos);
	path = pathFinder->getPoints();
	hasDestination = true;
}

bool Unit::isSelected(Point posMouse) {
	return false;
}
void Unit::setGroup(bool val) {
	hasGroup = val;
}

void Unit::update(float dt, Point posMouse, Map *map) {
	casePosition = map->getPos(currentPos);
	if(hasDestination) {
		Point distance;
		Point pos = path->front();
		float coeffx = 1;
		float coeffy = 1;
	//	std::cout << currentPos.x << " " << currentPos.y << " " << pos.x << " " << pos.y << std::endl;
		if(casePosition != pos) {

			distance.x = -casePosition.x + pos.x;
			distance.y = -casePosition.y + pos.y;
		//	coeffx = cos(distance.y/distance.x);
		//	coeffy = sin(distance.y/distance.x);
		//	std::cout << coeffx << " " << coeffy << std::endl;
		}
		else if(casePosition == arrivalPos) {
			hasDestination = false;
			distance.x = 0;
			distance.y = 0;
		}
		else if(casePosition == pos) {
			distance.x = abs(casePosition.x - pos.x);
			distance.y = abs(casePosition.y - pos.y);
			if(path->size()>0)
			path->erase(path->begin());
		}
		x += speed*dt*distance.x;
		y += speed*dt*distance.y;
	//	std::cout << distance.x << std::endl;
		box->x = x;
		box->y = y;
		currentPos.x = box->x;
		currentPos.y = box->y;
		//	box->x = currentPos.x;
		//	box->y = currentPos.y;
	}
}

Unit::~Unit() {
}
