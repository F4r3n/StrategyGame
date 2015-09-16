#include "group.h"
#include <iostream>

int Group::idGroup = 0;

Group::Group(std::vector<Unit*> *listUnits) {
	
	idGroup++;
	units = new std::map<int,Unit*>();
	for(auto *unit : *listUnits) {

	units->insert(std::pair<int, Unit*>(unit->getId(), unit));
	unit->idGroup = idGroup;
	}
}

Group::Group(Unit *unit) {

	idGroup++;
	units = new std::map<int,Unit*>();

	units->insert(std::pair<int, Unit*>(unit->getId(), unit));
	unit->idGroup = idGroup;
}

Group::Group() {
}

Group::~Group() {
	delete units;
}

bool Group::isExist(int id) {
	for(auto &m : *units) {
		if(m.second->getId() == id)
			return true;
	}
	return false;
}

void Group::refreshGroup() {

	for(auto &m : *units) {
		if(m.second->idGroup != idGroup) {
			units->erase(m.first);
		}
	}
}

void Group::addUnit(Unit *unit) {
	units->insert(std::pair<int, Unit*>(unit->getId(), unit));
	unit->idGroup = idGroup;
}
