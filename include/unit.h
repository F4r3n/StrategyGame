#ifndef UNIT_H
#define UNIT_H
#include "clickableObject.h"
#include "point.h"
#include "map.h"

class Unit: public ClickableObject {
	public:
		Unit();
		Unit(int belonging, Point pos, int life);
		virtual ~Unit();
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float dt, Point posMouse, Map *map);
		bool isGrouped();
		void setGroup(bool val);
		int idGroup = -1;
		int type = -1;

	protected:
		Point currentPos;
		Point arrivalPos;
		int life;
		bool hasGroup = false;


};

#endif
