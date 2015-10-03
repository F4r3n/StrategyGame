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

void Bucket::update(float dt, Map *map) {}

void Bucket::draw(sf::RenderWindow &window) {}
