#include "bucket.h"
#include <iostream>
Bucket::Bucket(int id, Rect rect): id(id), rect(rect) {

	shape = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape());
	shape->setFillColor(sf::Color(0,0,0,0));
	shape->setOutlineThickness(5);
	shape->setOutlineColor(sf::Color(100,0,0));
	shape->setPosition(rect.x, rect.y);
	shape->setSize(sf::Vector2f(rect.w, rect.h));
}

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
//	window.draw(*shape);
	for(auto &unit: units) 
		unit.second->draw(window);
}
