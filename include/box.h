#ifndef BOX_H
#define BOX_H

#include <vector>
#include <algorithm>

class Box {
	public:
		Box(float x,float w, float y, float h);
		Box();
		float getCenterX();
		float getCenterY();

		~Box();
		bool AABB(Box *b);
		bool pointer(float x, float y);
		float x,w,y,h;
	private:
		

};


#endif
