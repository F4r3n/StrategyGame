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


std::vector<Node*> PathFinder::nearestCases(Node *nextPosition, float offset) {
	std::vector<Node*> nodes;
	for(int i=-1; i< 2;i++) {
		for(int j=-1; j<2;j++) {
			if(abs(i) == abs(j)) continue;
			Point pos(nextPosition->currentPos.x + i, nextPosition->currentPos.y + j);
			if(map->validPoint(pos) && bmap[pos.x][pos.y]) {
				Node *n = new Node();
				n->currentPos = pos;
				n->weight = euclideanDistance(pos) + offset;
				n->parent = nextPosition;
				nodes.push_back(n);
				bmap[pos.x][pos.y] = false;
			}
		}
	}
	return nodes;
}

float PathFinder::euclideanDistance(Point newDistance) {
	float a  = pow((newDistance.x-destination.x),2);

	float b  = pow((newDistance.y-destination.y),2);
	return sqrt(a+b);
//	return sqrt(pow((newDistance.x-destination.x),2) + pow((newDistance.y - destination.x),2));
}

PathFinder::PathFinder() {

}

PathFinder::~PathFinder() {

	Point size = map->getSizeMap();
	for(int i=0;i<size.y;i++) {
		delete bmap[i];
	}
delete bmap;
}

void PathFinder::reset() {

	points.clear();
	map->reset();

	Point size = map->getSizeMap();
	for(int i=0;i<size.y;i++)
		for(int j = 0; j < size.x; j++)
			bmap[i][j] = true;
}

void PathFinder::setDestination(Point currentPos,Point dest) {
	destination = dest;
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
	do{
		currentNode = nodes.top();
		nextPosition = currentNode->currentPos;
		nodes.pop();
		std::vector<Node*> nextNodes = nearestCases(currentNode, 1);
		fillNodes(nodes, nextNodes);

	//	bmap[nextPosition.x][nextPosition.y] = true;
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
	Node *currentNode = lastNode;
	points.clear();
	points.push_back(currentNode->currentPos);
	map->setColorTile(currentNode->currentPos);
	while(currentNode->currentPos != currentPosition) {
			currentNode = currentNode->parent;
			if(!(currentNode->currentPos != currentPosition)) break;
			points.push_back(currentNode->currentPos);
			map->setColorTile(currentNode->currentPos);
	}
	std::reverse(points.begin(), points.end());

}

void PathFinder::fillNodes(std::priority_queue<Node*, std::vector<Node*>,Comparator> &nodes, std::vector<Node*> &vnodes) {

	for(auto vnode : vnodes)
		nodes.push(vnode);
	vnodes.clear();
}
