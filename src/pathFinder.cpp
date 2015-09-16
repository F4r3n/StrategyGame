#include "pathFinder.h"

PathFinder::PathFinder(Map *map):map(map) {
	Point size = map->getSizeMap();
	bmap = new bool*[size.y];
	for(int i=0;i<size.y;i++) {
		bmap[i] = new bool[size.x];
	}

	for(int i=0;i<size.y;i++)
		for(int j = 0; j < size.x; j++)
			bmap[i][j] = false;
}

std::vector<Node> PathFinder::nearestCases() {

}

float PathFinder::euclideanDistance() {
	return sqrt(pow((currentPosition.x-destination.x),2) + pow((currentPosition.y - destination.x),2));
}

PathFinder::PathFinder() {

}

PathFinder::~PathFinder() {

}

void PathFinder::setDestination(Point dest) {
	destination = dest;
}
