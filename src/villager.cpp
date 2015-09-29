#include "villager.h"
#include <iostream>
#include "typeUnit.h"
Villager::Villager() {

}

Villager::~Villager(){
	//delete pathFinder;
	delete shape;
	delete box;
}

Villager::Villager(int belonging, Point pos, int life, float attack): Unit(belonging,  pos, life) {
	type = TypeUnit::VILLAGER;
	normalColor = sf::Color::Red;
	selectedColor = sf::Color::Green;
	this->attack = attack;
	shape = new sf::CircleShape();
	shape->setRadius(10);
	shape->setOutlineColor(normalColor);
	shape->setOutlineThickness(5);
	shape->setPosition(pos.x, pos.y);
	box = new Box(pos.x, 20, pos.y ,20);
	actions.push_back(new Action(Move::STRAIGHT_AT_CLICK));
	offsetDraw.x = 10;
	offsetDraw.y = 10;


}

void Villager::changeColor() {
	if(selected) shape->setOutlineColor(selectedColor);
	else shape->setOutlineColor(normalColor);
}

void Villager::draw(sf::RenderWindow &window) {
	window.draw(*shape);
	//window.draw(*box->getShape());

}
bool Villager::isSelected(Rect &rect) {
		bool touched = box->AABB(rect);
		if(touched) {
			return true;
		}
		return false; 
}

bool Villager::isSelected(Point posMouse) {
		bool touched = box->pointer(posMouse);
		if(touched) {
			return true;
		}
		return false; 
}
void Villager::update(float dt, Point posMouse, Map *map) {
	Unit::update(dt,posMouse,map);
//	box->updateOffset(offsetDraw, Point(box->x, box->y));
	shape->setPosition(box->x, box->y);
	
	//if(box == 0) std::cout << "null" << std::endl;
}
