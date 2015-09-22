#include "pathFinder.h"
#include <iostream>
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
	std::vector<Node> nodes;
	for(int i=-1; i< 2;i++) {
		for(int j=-1; j<2;j++) {
			if(abs(i) == abs(j)) continue;
			std::cout << i << " " << j << std::endl;
			Point pos(currentPosition.x + i, currentPosition.y + j);
			if(map->validPoint(pos)) {
				Node n;
				n.currentPos = pos;
				n.weight = euclideanDistance(pos);
				nodes.push_back(n);
			}
		}
	}
	return nodes;
}

float PathFinder::euclideanDistance(Point newDistance) {
	return sqrt(pow((newDistance.x-destination.x),2) + pow((newDistance.y - destination.x),2));
}

PathFinder::PathFinder() {

}

PathFinder::~PathFinder() {

}

void PathFinder::setDestination(Point currentPos,Point dest) {
	destination = dest;
	this->currentPosition = currentPos;
	nearestCases();
}
