#ifndef CLICKABLE_OBJECT_H
#define CLICKABLE_OBJECT_H

#include <SFML/Graphics.hpp>
#include "point.h"
#include "statusBar.h"

class ClickableObject {
	public:
		ClickableObject();
		ClickableObject(int belonging);
		void draw(sf::RenderWindow &window);
		void update(float dt, Point posMouse, StatusBar *statusBar);
		~ClickableObject();

	protected:
		int belonging;
		sf::RectangleShape *shape;


};

#endif
