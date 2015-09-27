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
		int getIdGroup();
		void setIdGroup(int id);
		int type = -1;
		bool runningAction = false;
		void initPathFinder(Map *map);
		void setDestination(Point casePosArrival, Point posArrival);

	protected:
		int idGroup = -1;
		Point speed;
		float x = 0;
		float y = 0;
		Point currentPos;
		Point arrivalCasePos;
		Point arrivalPos;
		std::vector<Point> *path;
		Point nextPosition;
		int life;
		bool hasGroup = false;
		bool hasDestination = false;
		PathFinder *pathFinder;


};

#endif
