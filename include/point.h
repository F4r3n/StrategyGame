#ifndef POINT_H
#define POINT_H

class Point {
	public:
		Point();
		Point(int x, int y);
		bool operator!=(const Point &a);
		bool operator==(const Point &a);
Point& operator=(const Point &p);
		~Point();
		int x;
		int y;

};


#endif
