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
		bool isSelected(const Point &posMouse);
		bool isSelected(Rect &rect);
		void draw(sf::RenderWindow &window);
		void update(float dt, Point posMouse, Map *map);
	private:
		sf::CircleShape *shape;
		sf::Color normalColor;
		sf::Color selectedColor;
	//	sf::Color currentColor;
	//	Box *box;
		float attack;
};

#endif
