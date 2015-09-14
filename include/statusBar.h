#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "GUI.h"
#include "screen.h"

class StatusBar : public Screen {
	public:
		StatusBar(float position, sf::Color color);
		~StatusBar();
		void draw(sf::RenderWindow &window);
		void drawPortrait(sf::RenderWindow &window, sf::RectangleShape *shape);
		void update(float dt);
	private:
		float position;
		sf::Color color;
		sf::RectangleShape *shape;



};

#endif
