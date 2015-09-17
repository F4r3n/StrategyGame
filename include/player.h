#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "group.h"
#include "interface.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "villager.h"
#include "point.h"
#include "action.h"
class Player {
	public :
		Player();
		void update(float dt, Map *map, Interface *interface, Point pos);
		void draw(sf::RenderWindow &window);
		void refreshGroups();
		void sendActionsInterface(Interface *interface);
		~Player();

	private:
		std::vector<Unit*> *units; 
		std::vector<Group*> *groups; 
		Interface *interface;
		Group *currentGroup;
		Action *selectedAction;


};


#endif
