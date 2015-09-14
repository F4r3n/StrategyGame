#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "GUI.h"
#include "screen.h"
#include "portrait.h"

class StatusBar : public Screen {
	public:
		StatusBar(float position, sf::Color color);
		~StatusBar();
		void draw(sf::RenderWindow &window);
		void drawPortrait(sf::RenderWindow &window, sf::RectangleShape *shape);
		void update(float dt);

		void setPortrait(Portrait *por);
	private:
		float position;
		sf::Color color;
		Portrait *por;
		sf::RectangleShape *shape;



};

#endif
