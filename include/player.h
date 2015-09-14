#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "interface.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "villager.h"
#include "point.h"

class Player {
	public :
		Player();
		void update(float dt, Map *map, Interface *interface, Point pos);
		void draw(sf::RenderWindow &window);

	private:
		std::vector<Unit*> *units; 
		Interface *interface;

};


#endif
