#include "player.h"

Player::Player() {
	units = new std::vector<Unit*>();
	units->push_back(new Villager(0, Point(10,10),100,10));
}

void Player::update(float dt, Map *map, Interface *interface, Point pos) {
	for(auto *unit : *units)
		unit->update(dt, pos);
}

void Player::draw(sf::RenderWindow &window) {
	
}
