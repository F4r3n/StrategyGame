#ifndef UNIT_H
#define UNIT_H
#include "clickableObject.h"
#include "pathFinder.h"

class Unit: public ClickableObject {
	public:
		Unit();
		Unit(int belonging, Point pos, int life);
		virtual ~Unit();
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float dt, Point posMouse, Map *map);
		virtual bool isSelected(Point posMouse);
		bool isGrouped();
		void setGroup(bool val);
		int idGroup = -1;
		int type = -1;
		bool runningAction = false;
		void initPathFinder(Map *map);
		void setDestination(Point pos);
	protected:
		Point currentPos;
		Point arrivalPos;
		int life;
		bool hasGroup = false;
		PathFinder *pathFinder;


};

#endif
