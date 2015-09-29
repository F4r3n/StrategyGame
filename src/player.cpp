#include "player.h"
#include "input.h"
#include <cmath>

Player::Player() {
	shape = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape());
	shape->setFillColor(sf::Color(0,0,0,0));
	shape->setOutlineThickness(5);
	shape->setOutlineColor(sf::Color(0,100,0));
	units = new std::vector<Unit*>();
	groups = new std::vector<Group*>();
	units->push_back(new Villager(0, Point(300,300),100,10));
	units->push_back(new Villager(0, Point(200,200),100,10));
	Input::actionsClick["selectSingle"] = true;
	Input::actionsClick["selectGroup"] = true;
	Input::actionsClick["selectRect"] = true;
	Input::actionsClick["selectAction"] = true;
	Input::actionsClick["selectDestination"] = true;
}

void Player::resetGroups() {
}

void Player::update(float dt, Map *map, Interface *interface, Point pos, Point posMouseWindow) {
	for(auto *unit : *units) {
		unit->update(dt, pos,map);
	}
	if(!Input::isMousePressed(sf::Mouse::Left)) {
		Input::actionsClick["selectSingle"] = true;
		Input::actionsClick["selectGroup"] = true;
		Input::actionsClick["selectAction"] = true;
		Input::actionsClick["selectRect"] = true;
	}

	if(!Input::isMousePressed(sf::Mouse::Left) && isSelecting) {
		isSelecting = false;
		//	std::cout << "end" << std::endl;
		Rect r(posStartRect, posEndRect);
		//	std::cout << posStartRect << " " << posEndRect << " " <<r << std::endl;
		//	Point rect(posStartRect, Point(posStartRect.x - posEndRect.x, posStartRect.y - posEndRect.y));
		std::vector<Unit*> unitGroup;
		bool s = false;
		for(auto *unit : *units) {
			if(unit->isSelected(r)) {
				unit->setGroup(true);
				unit->setSelected(true);
				unit->changeColor();
				unitGroup.push_back(unit);
				s = true;
				//			std::cout << "select" << std::endl;
			}
		}
		if(s) {
			if(currentGroup != nullptr){
				currentGroup->resetColor();
				interface->resetActionsStatusBar();
			}
			Group *gr = new Group(unitGroup,map);

			groups->push_back(gr);
			currentGroup = gr;

			groupSelected = true;
		}
	}

	if(!Input::isMousePressed(sf::Mouse::Right)) {
		Input::actionsClick["selectDestination"] = true;
	}



	if(Input::isMousePressed(sf::Mouse::Left) && Input::actionsClick["selectRect"]) {
		posStartRect = pos;
		isSelecting = true;
		Input::actionsClick["selectRect"] = false;
	}

	if(isSelecting) {
		posEndRect = pos;
		shape->setPosition(posStartRect.x, posStartRect.y);
		shape->setSize(sf::Vector2f(-posStartRect.x+posEndRect.x, -posStartRect.y+posEndRect.y));
		//	std::cout << posStartRect.x << " " << posEndRect.x << std::endl;
	}


	if(Input::isMousePressed(sf::Mouse::Right) && Input::actionsClick["selectDestination"]) {
		Input::actionsClick["selectDestination"] = false;
		if(groupSelected && currentGroup != nullptr && map->isWalkable(map->getPos(pos))) {
			currentGroup->setDestination(map->getPos(pos), pos);
		}
	}

	if(Input::isMousePressed(sf::Mouse::Left) && Input::actionsClick["selectGroup"]) {
		Input::actionsClick["selectGroup"] = false;
		if(currentGroup != nullptr) {
			currentGroup->resetColor();

			interface->resetActionsStatusBar();
		}
		for(auto *unit : *units) {
			if(unit->isSelected(pos)) {
				if(unit->getBelonging() == 0) {
					//	if(currentGroup != nullptr) currentGroup->resetColor();
					unit->setGroup(true);
					unit->setSelected(true);
					unit->changeColor();
					Group *gr = new Group(unit, map);
					groups->push_back(gr);
					currentGroup = gr;
					sendActionsInterface(interface);
					groupSelected = true;
					refreshGroups();
				}
				else if(unit->getBelonging() !=0) {
					interface->resetActionsStatusBar();
				}
				else if(unit->isGrouped()) {

				}
				break;
			} else {
				interface->resetActionsStatusBar();
				map->reset();
				groupSelected = false;
				currentGroup = nullptr;
			}
		}
	}

	if(groupSelected) {
		if(Input::isMousePressed(sf::Mouse::Left) && Input::actionsClick["selectAction"]) {
			Input::actionsClick["selectAction"] = false;
			for(auto *act : actions) {
				if(act->cursorIn(posMouseWindow)) {
					//	std::cout << act->getAct() << std::endl;
				}
			}
		}
	}
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
	int i =0;
	for(auto *group : *groups) {
		if(group->refreshGroup()) {
			groups->erase(groups->begin() + i);
		}
		i++;
	}
}

void Player::draw(sf::RenderWindow &window) {

	if(isSelecting) {
		window.draw(*shape);
	}

	for(auto *unit : *units)
		unit->draw(window);
}
