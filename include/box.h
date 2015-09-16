#ifndef BOX_H
#define BOX_H

#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "point.h"
class Box {
	public:
		Box(float x,float w, float y, float h);
		Box();
		float getCenterX();
		float getCenterY();

		~Box();
		bool AABB(Box *b);
		bool pointer(float x, float y);
		bool pointer(Point pos);
		sf::RectangleShape* getShape();
		float x,w,y,h;
	private:
		sf::RectangleShape *shape;
		

};


#endif
