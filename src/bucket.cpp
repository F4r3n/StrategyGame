#include "bucket.h"
#include <iostream>
Bucket::Bucket(int id, Rect rect): id(id), rect(rect) {}

Bucket::~Bucket() {}

bool Bucket::contains(Unit *unit) {
	if(rect.pointer(unit->getPos())) {
		return true;
	}
	return false;
}

void Bucket::remove(int id) {
	units.erase(id);
}

int Bucket::getSize() const{
	return units.size(); 
}

void Bucket::addUnit(Unit *unit) {
	unit->setBucket(id);
	units[unit->getId()]=unit;
}

void Bucket::update(float dt, Point posMouse, Map *map) {
	for(auto &unit: units) { 
	//	std::cout << id << " " << unit.second->getPos() << std::endl;
		unit.second->update(dt,posMouse,map);
	}
	
}

std::vector<Unit*> Bucket::refresh() {
	std::vector<Unit*> unitGarbage;
	for(auto &unit: units) {
		if(!unit.second->isSelected(rect)) {
			unitGarbage.push_back(unit.second);
			units.erase(unit.first);
		}
	}
	return unitGarbage;
}

void Bucket::draw(sf::RenderWindow &window) {

	for(auto &unit: units) 
		unit.second->draw(window);
}
