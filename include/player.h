#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include <SFML/Graphics.hpp>

class Player {
	public :
		Player();
		void update(float dt, Map *map);
		void draw(sf::RenderWindow &window);

	private:

};


#endif
