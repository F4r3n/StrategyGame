#include "villager.h"
#include <iostream>
Villager::Villager() {

}

Villager::~Villager(){

}

Villager::Villager(int belonging, Point pos, int life, float attack): Unit(belonging,  pos, life) {
	this->attack = attack;
	shape = new sf::CircleShape();
	shape->setRadius(10);
	shape->setOutlineColor(sf::Color::Red);
	shape->setOutlineThickness(5);
	shape->setPosition(pos.x, pos.y);
}


void Villager::draw(sf::RenderWindow &window) {
	window.draw(*shape);
}

void Villager::update(float dt, Point posMouse) {
}
