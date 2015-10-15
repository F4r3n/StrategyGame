#ifndef BOX_H
#define BOX_H

#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "rect.h"
class Box {
	public:
		Box(float x,float w, float y, float h);
		Box(const Rect &rect);
		Box(Point pos, Point size);
		Box();
		float getCenterX() const;
		float getCenterY() const;
		void configure(Point size, Point pos, sf::Color color);
		~Box();
		bool AABB(Box *b);
		bool AABB(const Box &b);
		bool pointer(const float x, const float y);
		bool AABB(const Point pos, const Point size);
		bool AABB(const Rect &rect);
		bool pointer(const Point &pos);
		void updateOffset(Point offset, Point current);
	//	sf::RectangleShape* getShape();
		float x,w,y,h;
	private:
	//	sf::RectangleShape *shape;
		

};


#endif
