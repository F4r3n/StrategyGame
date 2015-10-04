#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "map.h"
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

typedef struct Node {
	Point currentPos;
	float weight;
	struct Node *parent;
	bool operator<(Node *n) const {
		return weight > n->weight;
	}
}Node;
class Comparator {
	public:
		bool operator()(const Node* a, const Node* b)
		{
			return (a->weight > b->weight);
		}
};
class PathFinder {
	public:
		PathFinder(Map *map);
		PathFinder();
		std::vector<Node*> nearestCases(Node *nextPosition, float offset);
		float euclideanDistance(Point point);
		float chebyshevDistance(Point newDistance);
		void fillNodes(std::priority_queue<Node*, std::vector<Node*>,Comparator> &nodes, std::vector<Node*> &vnode);
		~PathFinder();
		void setDestination(Point currentPos,Point dest);
		void retrievePath(Node *lastNode);
		void reset();
		std::vector<Point>* getPoints();

	private:
		Point destination;
		Point currentPosition;
		std::vector<Point> points;
		Map *map;
		bool **bmap;
};

#endif
