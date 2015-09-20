#include "player.h"

Player::Player() {
	units = new std::vector<Unit*>();
	groups = new std::vector<Group*>();
	units->push_back(new Villager(0, Point(100,100),100,10));
}

void Player::update(float dt, Map *map, Interface *interface, Point pos, Point posMouseWindow) {
	for(auto *unit : *units) {
		unit->update(dt, pos,map);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if(unit->isSelected(pos)) {
				if(!unit->isGrouped()) {
					unit->setGroup(true);
					Group *gr = new Group(unit);
					groups->push_back(gr);
					currentGroup = gr;
					sendActionsInterface(interface);
					groupSelected = true;
				}
			}
		}
	}
	if(groupSelected) {
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			for(auto *act : actions) {
				if(act->cursorIn(posMouseWindow)) {
					std::cout << act->getAct() << std::endl;
				}
			}
		}
	}
}


void Player::sendActionsInterface(Interface *interface) {
	actions = currentGroup->allowedAction();
	interface->sendInterfaceActions(actions);
	std::cout << actions[0]->getBox()->x << std::endl;
}

Player::~Player() {

	for(auto *u :*units)
		delete u;

	delete units;
	for(auto *gr :*groups)
		delete gr;
	delete groups;
}
void Player::refreshGroups() {
	for(auto *group : *groups)
		group->refreshGroup();
}

void Player::draw(sf::RenderWindow &window) {

	for(auto *unit : *units)
		unit->draw(window);
}
