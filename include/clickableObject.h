#ifndef CLICKABLE_OBJECT_H
#define CLICKABLE_OBJECT_H

#include <SFML/Graphics.hpp>
#include "point.h"
#include "statusBar.h"

#include "action.h"
class ClickableObject {
	public:
		ClickableObject();
		ClickableObject(int belonging);
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float dt, Point posMouse, StatusBar *statusBar);
		bool isSelected(Point posMouse);
		std::vector<Action*> getActions();
		int getId();
		void deselect();
		virtual ~ClickableObject();

	protected:
		int belonging;
		bool selected;
		sf::RectangleShape *shape;
		Point casePosition;
		Box *box;
		std::vector<Action*> actions;
		static int id;

};

#endif
