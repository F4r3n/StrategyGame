#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "map.h"
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <algorithm>

typedef struct Node {
	Point currentPos;
	float weight;
	struct Node *parent;
    int dist;
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
		PathFinder(Map *map, Box *box);
		PathFinder();
		std::vector<Node*> nearestCases(Node *nextPosition, float offset);
		float euclideanDistance(Point point);
		float euclideanDistance(Point a, Point b);
		float chebyshevDistance(Point newDistance);
		void fillNodes(std::priority_queue<Node*, std::vector<Node*>,Comparator> &nodes, std::vector<Node*> &vnode);
		~PathFinder();
		void setDestination(Point currentPos,Point dest);
		void retrievePath(Node *lastNode);
		void reset();
		bool cornerCrossed(Point current, Point next);
        void setIntegrationField();
		std::vector<Point>* getPoints();

	private:
		Point destination;
		Point start;
		Point currentPosition;
		std::vector<Point> points;
		std::map<Point, Point> mapPoints;
		std::map<Point, int> cost;
		Map *map;
        Box *box;
		bool **bmap;
};

#endif
