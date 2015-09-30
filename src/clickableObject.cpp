#include "clickableObject.h"
#include "engineConst.h"
#include <iostream>

int ClickableObject::idTemp = 0; 

ClickableObject::ClickableObject(int belonging): belonging(belonging){
	std::cout << "create unit " << ClickableObject::idTemp << std::endl;
	ClickableObject::idTemp++;
	id = idTemp;
	
	std::cout << "unit created " << id << std::endl;
}

ClickableObject::ClickableObject() {}

void ClickableObject::update(float dt, Point posMouse, StatusBar *statusBar) {

}

int ClickableObject::getBelonging() {
	return belonging;
}

int ClickableObject::getId() {
	return id;
}

bool ClickableObject::isSelected(const Point &posMouse) {
		bool touched = box->pointer(posMouse);
		if(touched) {
			return true;
		}
		return false; 
}

void ClickableObject::deselect() {
	selected = false;
}

std::vector<Action*> ClickableObject::getActions() {
	return actions;
}
void ClickableObject::draw(sf::RenderWindow &window){
}

ClickableObject::~ClickableObject() {

}


