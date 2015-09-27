#include "point.h"

Point::Point(){}

Point::Point(int x, int y): x(x), y(y) {

}

Point::Point(sf::Vector2f v, int offsetX, int offsetY) {
	x = v.x + offsetX;
	y = v.y + offsetY;
}

Point::Point(sf::Vector2i v) {
	x = v.x;
	y = v.y;
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
