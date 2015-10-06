#include "managerBucket.h"

ManagerBucket::ManagerBucket() {}

ManagerBucket::ManagerBucket(Point sizeMap, Point sizeTile) {
	int k = 0;
	int sizeBucket = 4;
	std::cout << sizeMap.x/sizeBucket << std::endl;
	for(int i=0;i<sizeMap.y/sizeBucket;++i) {
		for(int j=0;j<sizeMap.x/sizeBucket ;++j) {
			buckets.push_back(std::shared_ptr<Bucket>(new Bucket(k,
							  Rect(j*sizeTile.x*sizeBucket, i*sizeTile.y*sizeBucket, sizeTile.x*sizeBucket, sizeTile.y*sizeBucket))));
			k++;
		}
	}
}
void ManagerBucket::addBucket(int pos, Bucket *bucket) {

	buckets.push_back(std::shared_ptr<Bucket>(bucket));
}

void ManagerBucket::addUnit(Unit *unit) {
	int oldIdBucket = unit->getIdBucket();
	int id = unit->getId();

	for(auto bucket : buckets) {
		if(bucket->contains(unit)) {
			bucket->addUnit(unit);
			if(oldIdBucket != -1)
				buckets[oldIdBucket]->remove(id);
			break;
		}
	}
}

void ManagerBucket::addUnit(std::vector<Unit*> *units) {
	for(auto *unit: *units) {
		addUnit(unit);
	}
}
ManagerBucket::~ManagerBucket() {}

void ManagerBucket::update(float dt, Point posMouse, Map *map) {
	for(auto bucket : buckets) {
		bucket->update(dt,posMouse,map);
		bucket->getSize();
		std::vector<Unit*> change = bucket->refresh();
		changeBucket.insert(changeBucket.end(),change.begin(), change.end());
	}

	for(auto bucket : buckets) {
		for(auto *unit: changeBucket) {
			if(bucket->contains(unit))
				bucket->addUnit(unit);
		}
	}
}

void ManagerBucket::draw(sf::RenderWindow &window) {

	for(auto bucket : buckets)
		bucket->draw(window);
}
