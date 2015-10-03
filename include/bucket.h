#ifndef BUCKET_H
#define BUCKET_H

#include "unit.h"
#include <map>
class Bucket {
	public:
		Bucket(int id,Rect rect);
		~Bucket();
		void update(float dt, Map *map);
		void draw(sf::RenderWindow &window);
		bool contains(Unit *unit);
		void addUnit(Unit *unit);
		void remove(int id);
	private:
		int id;
		Rect rect;
		std::map<int ,Unit*> units;
};

#endif
