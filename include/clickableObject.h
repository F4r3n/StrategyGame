#ifndef CLICKABLE_OBJECT_H
#define CLICKABLE_OBJECT_H

#include "player.h"
#include "statusBar.h"
#include <SFML/Graphics.hpp>
#include "point.h"

class ClickableObject {
	public:
		ClickableObject(int belonging, StatusBar *statusBar);
		void draw(sf::RenderWindow &window);	
		~ClickableObject();

	protected:
		int belonging;
		StatusBar *statusBar;
		Point currentPos;
		Point arrivalPos;
		sf::RectangleShape *shape;


};

#endif
