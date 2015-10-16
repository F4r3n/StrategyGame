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
			bmap[i][j] = true;
}

bool PathFinder::cornerCrossed(Point current, Point next) {
	Point dir = next - current;
	if(map->isWalkable(Point(current.x+dir.x,current.y)) && map->isWalkable(Point(current.x, current.y + dir.y))) {
		return true;
	}
	return false;
}

std::vector<Node*> PathFinder::nearestCases(Node *nextPosition, float offset) {
	std::vector<Node*> nodes;
	float new_cost = 0;
	for(int i=-1; i< 2;i++) {
		for(int j=-1; j<2;j++) {
			//	if(abs(i) == abs(j)) continue;
			Point pos(nextPosition->currentPos.x + i, nextPosition->currentPos.y + j);
			if(map->isWalkable(pos) && bmap[pos.x][pos.y] && cornerCrossed(nextPosition->currentPos, pos)) {

				new_cost = cost[nextPosition->currentPos] +  euclideanDistance(nextPosition->currentPos, pos);
				cost[pos] = new_cost;

				map->setColorTile(pos, sf::Color(100,0,0));
				mapPoints.insert(std::pair<Point,Point>(pos, nextPosition->currentPos));
				Node *n = new Node();
				n->currentPos = pos;
				n->weight = new_cost + euclideanDistance(pos);
				n->parent = nextPosition;
				nodes.push_back(n);
				bmap[pos.x][pos.y] = false;
			}
		}
	}
	return nodes;
}

float PathFinder::euclideanDistance(Point pa, Point pb) {
	float a  = pow((pa.x - pb.x),2);
	float b  = pow((pa.y - pb.y),2);
	return sqrt(a+b);
}

float PathFinder::euclideanDistance(Point newDistance) {
	float a  = pow((newDistance.x-destination.x),2);
	float b  = pow((newDistance.y-destination.y),2);
	return sqrt(a+b);
}

float PathFinder::chebyshevDistance(Point newDistance) {
	float a = abs(newDistance.x - destination.x);
	float b = abs(newDistance.y - destination.y);
	return std::max(a,b);
}

PathFinder::PathFinder() {}

PathFinder::~PathFinder() {
	Point size = map->getSizeMap();
	for(int i=0;i<size.y;i++) {
		delete bmap[i];
	}
	delete bmap;
}

void PathFinder::reset() {

	mapPoints.clear();
	points.clear();
	map->reset();

	Point size = map->getSizeMap();
	for(int i=0;i<size.y;i++)
		for(int j = 0; j < size.x; j++)
			bmap[i][j] = true;
}

void PathFinder::setDestination(Point currentPos, Point dest) {
	destination = dest;
	start = currentPos;
	reset();
	bmap[currentPos.x][currentPos.y] = false;

	Node *firstNode = new Node();
	firstNode->currentPos = currentPos;
	firstNode->parent = nullptr;
	firstNode->weight = euclideanDistance(currentPos);

	this->currentPosition = currentPos;
	std::priority_queue<Node*,std::vector<Node*>,Comparator> nodes;
	std::vector<Node*> vnodes = nearestCases(firstNode,0);
	fillNodes(nodes, vnodes);
	int i = 0;
	Point nextPosition;
	Node *currentNode;
	mapPoints.insert(std::pair<Point,Point>(firstNode->currentPos, firstNode->currentPos));
	cost[firstNode->currentPos] = 0;
	do{
		currentNode = nodes.top();

		nextPosition = currentNode->currentPos;
		nodes.pop();
		std::vector<Node*> nextNodes = nearestCases(currentNode, 1);
		fillNodes(nodes, nextNodes);

		i++;
		if(nodes.size() ==0) break;
	}while(nextPosition != dest);
	retrievePath(currentNode);

	int s = nodes.size();
	for(int i=0; i < s; i++) {
		Node *n = nodes.top();
		nodes.pop();
		delete n;
	}
}

std::vector<Point>* PathFinder::getPoints() {
	return &points;
}

void PathFinder::retrievePath(Node *lastNode) {
	Point current = destination;
	//	std::cout << "path found" <<std::endl;
	while(current != start) {
		map->setColorTile(current, sf::Color::Red);
		points.push_back(current);
		current = mapPoints[current];
		map->setColorTile(current, sf::Color::Red);
	}

	std::reverse(points.begin(), points.end());

}

void PathFinder::fillNodes(std::priority_queue<Node*, std::vector<Node*>,Comparator> &nodes, std::vector<Node*> &vnodes) {

	for(auto vnode : vnodes)
		nodes.push(vnode);
	vnodes.clear();
}
