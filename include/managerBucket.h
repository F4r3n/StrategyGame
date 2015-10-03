#ifndef MANAGER_BUCKET_H
#define MANAGER_BUCKET_H

#include <array>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "bucket.h"

class ManagerBucket {
	public:
		ManagerBucket(int pos, Bucket *bucket);
		~ManagerBucket();
		void update(float dt, Map *map);
		void draw(sf::RenderWindow &window);
		void addUnit(Unit *unit);

	private:
		std::array<std::shared_ptr<Bucket> , 4> buckets;
};


#endif
