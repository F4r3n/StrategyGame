#include "player.h"

Player::Player() {
	units = new std::vector<Unit*>();
	units->push_back(new Villager(0, Point(100,100),100,10));
}

void Player::update(float dt, Map *map, Interface *interface, Point pos) {
	for(auto *unit : *units) {
		unit->update(dt, pos);
		if(unit->isSelected(pos)) {
			if(!unit->isGrouped()) {
				Group gr;
				gr.addUnit(unit);
				groups.push_back(gr);
			}
		}
	}
}

void Player::refreshGroups() {
	for(auto &group : groups)
		group.refreshGroup();
}

void Player::draw(sf::RenderWindow &window) {
	
	for(auto *unit : *units)
		unit->draw(window);
}
