
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "box.h"

class GUI {
	public:
		GUI();
		GUI(Box box, sf::Color color);
		void draw(sf::RenderWindow &window);
	private:
		sf::RectangleShape *shape;
		sf::Color color;
		Box box;
		float x,y;
};

#endif
