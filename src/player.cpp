#include "player.h"
#include "input.h"

Player::Player() {
	units = new std::vector<Unit*>();
	groups = new std::vector<Group*>();
	units->push_back(new Villager(0, Point(300,300),100,10));
	units->push_back(new Villager(0, Point(200,200),100,10));
}

void Player::update(float dt, Map *map, Interface *interface, Point pos, Point posMouseWindow) {
	for(auto *unit : *units) {
		unit->update(dt, pos,map);
	}

	if(Input::isMousePressed(sf::Mouse::Right, false)) {
		if(groupSelected) {
			currentGroup->setDestination(map->getPos(pos));
			std::cout << "yo" << std::endl;
		}
	}

		if(Input::isMousePressed(sf::Mouse::Left, false)) {
	for(auto *unit : *units) {
			if(unit->isSelected(pos)) {
				std::cout << unit->getId() << " " << unit->idGroup <<" " <<unit->getBelonging() <<  std::endl;
				if(!unit->isGrouped() && unit->getBelonging() == 0) {
					unit->setGroup(true);
					Group *gr = new Group(unit, map);
					groups->push_back(gr);
					currentGroup = gr;
					sendActionsInterface(interface);
					groupSelected = true;
				}
				else if(unit->getBelonging() !=0) {
					interface->resetActionsStatusBar();
				}
			}
		}
	}

	if(groupSelected) {
		if(Input::isMousePressed(sf::Mouse::Left, false)) {
			for(auto *act : actions) {
				if(act->cursorIn(posMouseWindow)) {
					//	std::cout << act->getAct() << std::endl;
				}
			}
		}
	}
	//	std::cout << Input::myMouseButtons[sf::Mouse::Button::Left] << std::endl;
	//	Input::myMouseButtons[sf::Mouse::Button::Left] = false;
}


void Player::sendActionsInterface(Interface *interface) {
	actions = currentGroup->allowedAction();
	interface->sendInterfaceActions(actions);
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
