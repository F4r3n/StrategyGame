#include "group.h"

int Group::idGroup = 0;

Group::Group() {
	idGroup++;
	units = new std::map<int,Unit*>();
}

Group::~Group() {}

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
