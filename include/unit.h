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
		virtual void update(float dt, Point posMouse, Map *map, std::vector<Unit*> &otherUnits);
		bool isSelected(const Point &posMouse);
		bool isSelected(Rect &rect);
		bool isGrouped();
		void setGroup(bool val);
		int getIdGroup();
		void setIdGroup(int id);
		void setSelected(bool v);
		virtual void changeColor();
		int type = -1;
		bool runningAction = false;
		void initPathFinder(Map *map);
		void setDestination(Map *map, Point posArrival);
		void setBucket(int id);
		Point getPos();
		int getIdBucket();
		void onCollision(Map *map, Unit *other);
		float dx,dy;

	protected:
		int idBucket = -1;
		int idGroup = -1;
		Point speed;
		float x = 0;
		float y = 0;
		bool isIdling = true;
		bool isAttacking = false;
		Point currentPos;
		Point arrivalCasePos;
		Point arrivalPos;
		std::vector<Point> *path;
		Point nextPosition;
		int life;
		bool selected = false;
		bool hasGroup = false;
		bool hasDestination = false;
		PathFinder *pathFinder;
		Point offsetDraw;


};


#endif
