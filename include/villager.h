#ifndef VILLAGER_H
#define VILLAGER_H

#include "unit.h"
#include <SFML/Graphics.hpp>
#include "point.h"
class Villager : public Unit {
	public:
		Villager();
		~Villager();
		Villager(int belonging, Point pos, int life, float attack);

		void draw(sf::RenderWindow &window);
		void update(float dt, Point posMouse);
	private:
		float attack;
		sf::CircleShape *shape;
};

#endif
