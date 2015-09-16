#include "clickableObject.h"
#include "engineConst.h"


int ClickableObject::id = 0; 
ClickableObject::ClickableObject(int belonging): belonging(belonging){
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(50, 50));
	shape->setPosition(20, EngineConst::WIDTH*0.7);
	shape->setFillColor(sf::Color::White);
	id++;
	
}

ClickableObject::ClickableObject() {}

void ClickableObject::update(float dt, Point posMouse, StatusBar *statusBar) {

}

int ClickableObject::getId() {
	return id;
}

bool ClickableObject::isSelected(Point posMouse) {
		bool touched = box->pointer(posMouse);
		if(touched) {
			return true;
		}
		return false; 
}

void ClickableObject::deselect() {
	selected = false;
}

void ClickableObject::draw(sf::RenderWindow &window){
}

ClickableObject::~ClickableObject() {

}


