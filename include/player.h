#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "group.h"
#include "interface.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "villager.h"
#include "point.h"
#include "action.h"
class Player {
	public :
		Player();
		void update(float dt, Map *map, Interface *interface, Point pos, Point posMouseWindow);
		void draw(sf::RenderWindow &window);
		void refreshGroups();
		void resetGroups();
		void fillGroup(Map *map, Interface *interface);
		void sendActionsInterface(Interface *interface);
		~Player();

	private:
		std::vector<Unit*> *units; 
		std::vector<Group*> *groups;
		std::vector<Unit*> selectedUnits;
		Interface *interface;
		Group *currentGroup;
		Action *selectedAction;
		std::vector<Action*> actions;
		bool groupSelected = false;
		bool isSelecting = false;
		Point mousePosWindow;
		Point posStartRect;
		std::unique_ptr<sf::RectangleShape> shape;
		Point posEndRect;


};


#endif
