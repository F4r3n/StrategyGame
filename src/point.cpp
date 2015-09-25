#include "point.h"

Point::Point(){}

Point::Point(int x, int y): x(x), y(y) {

}

bool Point::operator!=(const Point &p) {
	return (p.x != x || p.y!=y);
}
bool Point::operator==(const Point &p) {
	return (p.x == x && p.y==y);
}

Point& Point::operator=(const Point &p) {
	x = p.x;
	y = p.y;
	return *this;
}

Point::~Point() {

}
