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
	speed.x = 100;
	speed.y = 100;
}

Point Unit::getPos() {
	return currentPos;
}

void Unit::changeColor() {

}

void Unit::setSelected(bool v) {
	selected = v;
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

void Unit::setBucket(int id) {
	idBucket = id;
}

int Unit::getIdBucket() {
	return idBucket;
}

void Unit::initPathFinder(Map *map) {
	pathFinder = new PathFinder(map);
}

void Unit::setDestination(Map *map, Point posArrival) {
	Point dest = posArrival - offsetDraw;
	arrivalPos = dest;
	arrivalCasePos = Map::getPos(dest);
	if(!map->isWalkable(arrivalCasePos)) return;	

	if(casePosition == Map::getPos(dest)) return;
	pathFinder->setDestination(casePosition,arrivalCasePos);
	path = pathFinder->getPoints();
	hasDestination = true;
}

bool Unit::isSelected(const Point &posMouse) {
	bool touched = box->pointer(posMouse);
	if(touched) {
		return true;
	}
	return false; 
}
bool Unit::isSelected(Rect &rect) {
	bool touched = box->AABB(rect);
	if(touched) {
		return true;
	}
	return false; 
}
void Unit::setGroup(bool val) {
	hasGroup = val;
}

void Unit::update(float dt, Point posMouse, Map *map) {
	casePosition = Map::getPos(currentPos);
	if(hasDestination) {
		Point tempPos;
		Point tempSpeed = speed;

		float dx;
		float dy;
		Point pos = path->front();
		tempPos = Map::getCenterCase(pos); 
		float norme = sqrt(pow((currentPos.x - tempPos.x), 2) + pow((currentPos.y - tempPos.y), 2));
		float dtempx = -currentPos.x + tempPos.x;
		float dtempy = -currentPos.y + tempPos.y;
		dx = (dtempx)/norme;
		dy = (dtempy)/norme;

		if((abs(dtempx) == 0 || abs(dtempx) <= 3) && (abs(dtempy) == 0 || abs(dtempy) <= 3)) {
			if(path->size() > 0)
				path->erase(path->begin());
		}

		if(casePosition == arrivalCasePos) {
			if(currentPos != arrivalPos) {
				norme = sqrt(pow((currentPos.x - arrivalPos.x), 2) + pow((currentPos.y - arrivalPos.y), 2));
				dtempx = -currentPos.x + arrivalPos.x;
				dtempy = -currentPos.y + arrivalPos.y;
				dx = (dtempx)/norme;
				dy = (dtempy)/norme;
				//TODO a normaliser en fonction de la vitesse
				if((abs(dtempx) == 0 || abs(dtempx) <= 3) && (abs(dtempy) == 0 || abs(dtempy) <= 3)) {
					hasDestination = false;
					dx = 0;
					dy = 0;
				}
			}
			else {
				hasDestination = false;
				dx = 0;
				dy = 0;
			}
		}

		x += tempSpeed.x * dt * dx;
		y += tempSpeed.y * dt * dy;
		box->x = x;
		box->y = y;
		currentPos.x = box->x;
		currentPos.y = box->y;
	}
}

Unit::~Unit() {}
