#include "bucket.h"

Bucket::Bucket(int id, Rect rect): id(id), rect(rect) {}

Bucket::~Bucket() {}

bool Bucket::contains(Unit *unit) {
	if(unit->isSelected(rect))
		return true;
	return false;
}

void Bucket::remove(int id) {
	units.erase(id);
}

void Bucket::addUnit(Unit *unit) {
	units[unit->getId()]=unit;
}

void Bucket::update(float dt, Point posMouse, Map *map) {
	for(auto &unit: units) 
		unit.second->update(dt,posMouse,map);
	
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
