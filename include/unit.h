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
		virtual bool isSelected(const Point &posMouse);
		virtual bool isSelected(Rect &rect);
		bool isGrouped();
		void setGroup(bool val);
		int getIdGroup();
		void setIdGroup(int id);
		void setSelected(bool v);
		virtual void changeColor();
		int type = -1;
		bool runningAction = false;
		void initPathFinder(Map *map);
		void setDestination(Point casePosArrival, Point posArrival);
		void setBucket(int id);
		Point getPos();
		int getIdBucket();

	protected:
		int idBucket = -1;
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
		bool selected = false;
		bool hasGroup = false;
		bool hasDestination = false;
		PathFinder *pathFinder;
		Point offsetDraw;


};


#endif
