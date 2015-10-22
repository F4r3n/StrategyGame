#include "managerBucket.h"

ManagerBucket::ManagerBucket() {}

ManagerBucket::ManagerBucket(Point sizeMap, Point sizeTile) {
	int k = 0;
	int sizeBucket = 2;
	int numberBucketLine = sizeMap.x/sizeBucket;
	int numberBucketCol = sizeMap.y/sizeBucket;

	for(int i=0;i<sizeMap.y/sizeBucket;++i) {
		for(int j=0;j<sizeMap.x/sizeBucket ;++j) {
			buckets.push_back(std::shared_ptr<Bucket>(new Bucket(k,Point(j,i),
							  Rect(j*sizeTile.x*sizeBucket, i*sizeTile.y*sizeBucket, sizeTile.x*sizeBucket, sizeTile.y*sizeBucket))));
			k++;
		}
	}

	for(auto bucket : buckets) {
		int idBucket = bucket->getId();
		Point pos = bucket->getPos();
		for(int i = -1; i < 2; ++i) {
			for(int j = -1; j < 2; ++j) {
				Point n;
				n.x = pos.x + i;
				n.y = pos.y + j;
				if(n.x >= 0 && n.y >= 0 && n.x < numberBucketLine && n.y < numberBucketCol) {
					groupBucket[idBucket].push_back(buckets[n.y*numberBucketLine + n.x]);
				}
			}
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
		std::vector<Unit*> change = bucket->refresh();
		changeBucket.insert(changeBucket.end(),change.begin(), change.end());
	}

	for(auto bucket : buckets) {
		for(auto *unit: changeBucket) {
			if(bucket->contains(unit))
				bucket->addUnit(unit);
		}
		bucket->update(dt,posMouse,map, groupBucket[bucket->getId()]);
	}
	changeBucket.clear();
}

void ManagerBucket::draw(sf::RenderWindow &window) {

	for(auto bucket : buckets)
		bucket->draw(window);
}
