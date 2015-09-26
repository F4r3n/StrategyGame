#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include "point.h"
class Ground{
	public:
		Ground(Point pos, Point size);
		Ground();
		Point getPos();
		Point getSize();
	 	virtual ~Ground();
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float dt);

	protected:
		Point pos;
		Point size;

};

#endif
