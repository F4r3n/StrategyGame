#include "group.h"
#include <iostream>

int Group::idGroupTemp = 0;

Group::Group(std::vector<Unit*> *listUnits) {
	
	idGroupTemp++;
	idGroup = idGroupTemp;
	units = new std::map<int,Unit*>();
	for(auto *unit : *listUnits) {

	units->insert(std::pair<int, Unit*>(unit->getId(), unit));
	unit->setIdGroup(idGroup);
	}
}


void Group::setDestination(Point arrivalCasePos, Point arrivalPos) {
	for(auto &m : *units) {
		m.second->setDestination(arrivalCasePos, arrivalPos);
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

void Group::refreshGroup() {

	for(auto &m : *units) {
		if(m.second->getIdGroup() != idGroup) {
			units->erase(m.first);
		}
	}
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
