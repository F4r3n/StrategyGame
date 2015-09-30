#ifndef CLICKABLE_OBJECT_H
#define CLICKABLE_OBJECT_H

#include <SFML/Graphics.hpp>
#include "rect.h"
#include "statusBar.h"

#include "action.h"
class ClickableObject {
	public:
		ClickableObject();
		ClickableObject(int belonging);
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float dt, Point posMouse, StatusBar *statusBar);
		virtual bool isSelected(const Point &posMouse);
		std::vector<Action*> getActions();
		int getId();
		void deselect();
		virtual ~ClickableObject();
		int getBelonging();
	protected:
		Box *box;
		int belonging;
		bool selected;
		Point casePosition;
		std::vector<Action*> actions;
		static int idTemp;
		int id;

};

#endif
