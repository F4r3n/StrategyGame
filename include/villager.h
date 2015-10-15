#ifndef VILLAGER_H
#define VILLAGER_H

#include "unit.h"
#include <SFML/Graphics.hpp>
#include "point.h"

class Villager final : public Unit {
	public:
		Villager();
		~Villager();
		Villager(int belonging, Point pos, int life, float attack);
		void changeColor();
		void draw(sf::RenderWindow &window);
		void update(float dt, Point posMouse, Map *map, std::vector<Unit*> &otherUnits);
	private:
		sf::CircleShape *shape;
		sf::Color normalColor;
		sf::Color selectedColor;
		float attack;
};

#endif
