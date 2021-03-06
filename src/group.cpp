#include "group.h"
#include <iostream>

int Group::idGroupTemp = 0;

Group::Group(std::vector<Unit*> &listUnits, Map *map) {

	idGroupTemp++;
	idGroup = idGroupTemp;
	units = new std::map<int,Unit*>();

	for(auto *unit : listUnits) {
		unit->setGroup(true);
		unit->initPathFinder(map);
		units->insert(std::pair<int, Unit*>(unit->getId(), unit));
		unit->setIdGroup(idGroup);
		unit->runningAction = true;
	}
}


void Group::setDestination(Map *map, Point arrivalPos) {
	for(auto &m : *units) {
		m.second->setDestination(map, arrivalPos);
	}
}


Group::Group(Unit *unit, Map *map) {

	idGroupTemp++;
	idGroup = idGroupTemp;
	units = new std::map<int,Unit*>();
	unit->initPathFinder(map);
	units->insert(std::pair<int, Unit*>(unit->getId(), unit));
	unit->setIdGroup(idGroup);
	unit->runningAction = true;
	for(Action *act :unit->getActions()) {
		moves[act->getAct()] = act;
	}
}

int Group::getIdGroup() {
	return idGroup;
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

void Group::resetColor() {

	for(auto &m : *units) {
		m.second->setSelected(false);
		m.second->changeColor();
	}
}

bool Group::refreshGroup() {

	for(auto &m : *units) {
		if(m.second->getIdGroup() != idGroup) {
			units->erase(m.first);
		}
	}
	if(units->empty()) {
		toDelete = true;
		return true;
	}

	return false;
}

bool Group::getDelete() {
	return toDelete;
}

void Group::addUnit(Unit *unit) {
	units->insert(std::pair<int, Unit*>(unit->getId(), unit));
	unit->setIdGroup(idGroup);
}

std::vector<Action*> Group::allowedAction() {
	std::vector<Action*> mo;
	if(!isMixed) {
		for(auto m : moves){
			mo.push_back(m.second);
		}
	}
	return mo;
}
