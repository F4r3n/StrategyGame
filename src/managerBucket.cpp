#include "managerBucket.h"

ManagerBucket::ManagerBucket(int pos,Bucket *bucket) {
	buckets.at(pos) = std::shared_ptr<Bucket>(bucket);
}

void ManagerBucket::addUnit(Unit *unit) {
	int oldIdBucket = unit->getIdBucket();
	int id = unit->getId();

	for(auto bucket : buckets) {
		if(bucket->contains(unit)) {
			bucket->addUnit(unit);
		}
	}
}

ManagerBucket::~ManagerBucket() {}

void ManagerBucket::update(float dt, Map *map) {}

void ManagerBucket::draw(sf::RenderWindow &window) {}
