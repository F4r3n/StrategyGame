#ifndef POINT_H
#define POINT_H

class Point {
	public:
		Point();
		Point(int x, int y);
		bool operator!=(const Point &a);
		bool operator==(const Point &a);
		~Point();
		int x;
		int y;

};

#endif
