#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "point.h"
#include "map.h"
#include <vector>
#include <math.h>

typedef struct Node {
	Point currentPos;
	float weight;
}Node;

class PathFinder {
	public:
		PathFinder(Map *map);
		PathFinder();
		std::vector<Node> nearestCases();
		float euclideanDistance(Point newDistance);

		~PathFinder();
		void setDestination(Point currentPos,Point dest);
		
	private:
		Point destination;
		Point currentPosition;
		std::vector<Point> points;
		Map *map;
		bool **bmap;
};

#endif
