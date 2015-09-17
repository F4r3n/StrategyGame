
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "box.h"

class GUI {
	public:
		GUI();
		~GUI();
		GUI(Box *box, sf::Color color, sf::Color highlightColor);
		void draw(sf::RenderWindow &window);
		bool cursorIn(float x, float y);
		Box* getBox();
	private:
		sf::RectangleShape *shape;

		Box *box;
		sf::Color color;
		sf::Color highlightColor;
		float x,y;
};

#endif
