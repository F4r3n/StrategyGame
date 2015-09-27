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
	speed.x = 1000;
	speed.y = 1000;

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

void Unit::setDestination(Point casePosArrival, Point posArrival) {
	arrivalPos = posArrival;
	arrivalCasePos = casePosArrival;
	if(casePosition == casePosArrival) return;
	pathFinder->setDestination(casePosition,casePosArrival);
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
		bool precised = false;
		Point tempSpeed = speed;

		float dx;
		float dy;
		if(casePosition == arrivalCasePos) {
			if(currentPos != arrivalPos) {
				precised = true;
			//	tempSpeed = 100;
				float norme = sqrt(pow((currentPos.x-arrivalPos.x),2) + pow((currentPos.y - arrivalPos.y),2));
				float dtempx = -currentPos.x + arrivalPos.x;
				float dtempy = -currentPos.y +arrivalPos.y;
				dx = (dtempx)/norme;
				dy = (dtempy)/norme;
			//	std::cout << dtempx << " " << dtempy << std::endl;
//TODO a normaliser en fonction de la vitesse
				if((abs(dtempx) == 0 || abs(dtempx) <=3) && (abs(dtempy) ==0 || abs(dtempy)<=3)) {
					hasDestination = false;
					dx = 0;
					dy = 0;
				}
			//	std::cout << currentPos.x << " " << currentPos.y << " " << arrivalPos.x << " " << arrivalPos.y <<" " << dx << " " << dy << std::endl;
			}
			else {
				hasDestination = false;
				dx = 0;
				dy = 0;
			}
		}
		else {
			Point pos = path->front();
			float coeffx = 1;
			float coeffy = 1;
			if(casePosition != pos) {

				dx = -casePosition.x + pos.x;
				dy = -casePosition.y + pos.y;
				//	coeffx = cos(distance.y/distance.x);
				//	coeffy = sin(distance.y/distance.x);
			}
			else if(casePosition == arrivalPos) {
			}
			else if(casePosition == pos) {
				dx = abs(casePosition.x - pos.x);
				dy = abs(casePosition.y - pos.y);
				if(path->size()>0)
					path->erase(path->begin());
			}
		}
		x += tempSpeed.x*dt*dx;
		y += tempSpeed.y*dt*dy;
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
