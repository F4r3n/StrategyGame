#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>
class Point {
	public:
		Point();
		Point(int x, int y);
		Point(sf::Vector2f v, int offsetX = 0, int offsetY = 0);
		Point(sf::Vector2i v);
		bool operator!=(const Point &a);
		bool operator==(const Point &a);
Point& operator=(const Point &p);
		~Point();
		int x;
		int y;

};


#endif
