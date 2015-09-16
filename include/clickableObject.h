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
		bool isSelected(Point posMouse);
		int getId();
		void deselect();
		~ClickableObject();

	protected:
		int belonging;
		bool selected;
		sf::RectangleShape *shape;
		Box *box;

		static int id;

};

#endif
