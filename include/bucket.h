#ifndef BUCKET_H
#define BUCKET_H

#include "unit.h"
#include <map>
#include <memory>
#include <algorithm>
class Bucket {
	public:
		Bucket(int id,Point pos ,Rect rect);
		~Bucket();
		void update(float dt, Point posMouse, Map *map, std::vector<std::shared_ptr<Bucket> > &otherBuckets);
		void draw(sf::RenderWindow &window);
		bool contains(Unit *unit);
		void addUnit(Unit *unit);
		void remove(int id);
		int getSize() const;
		std::vector<Unit*> refresh();
		int getId() const;
		Point getPos() const;
		std::vector<Unit*> getVectorUnits(int id);
	private:

		std::unique_ptr<sf::RectangleShape> shape;
		int id;
		Point pos;
		Rect rect;
		std::map<int ,Unit*> units;
};

#endif
