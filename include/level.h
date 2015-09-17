#ifndef LEVEL_H
#define LEVEL_H

#include "screen.h"
#include "player.h"

class Level: public Screen {
	public:
		Level();
		void update(float dt);
		void draw(sf::RenderWindow &window);
		~Level();
	private:
		sf::View view;
		Interface *interface;	
		Map *map;
		Player *player;
		int centerX, centerY;
		Point pos;
		Point posMouseWindow;

};

#endif
