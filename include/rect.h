#ifndef RECT_H
#define RECT_H

#include "point.h"

enum Position { START_END, START_SIZE};

class Rect {
	public:
		Rect();
		Rect(Point pos, Point posEnd, Position type);
		Rect(int x, int y, int w, int h);
		Rect(sf::Vector2f v, int offsetX = 0, int offsetY = 0);
		Rect(sf::Vector2i v);
		bool pointer(const Point &p);
		bool operator!=(const Rect &a);
		bool operator==(const Rect &a);
		Rect& operator-(const Rect &a);
		Rect& operator+(const Rect &a);
		Rect& operator=(const Rect &a);
		Rect& operator/(const Rect &a);
		friend std::ostream& operator<<(std::ostream &o, Rect a);
		~Rect();
		int x;
		int y;
		int w;
		int h;

};


#endif
