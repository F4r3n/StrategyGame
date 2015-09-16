#ifndef UNIT_H
#define UNIT_H
#include "clickableObject.h"
#include "point.h"

class Unit: public ClickableObject {
	public:
		Unit();
		Unit(int belonging, Point pos, int life);
		~Unit();
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float dt, Point posMouse);
		bool isGrouped();
		void setGroup();
		int idGroup;

	protected:
		Point currentPos;
		Point arrivalPos;
		int life;
		bool hasGroup = false;

};

#endif
