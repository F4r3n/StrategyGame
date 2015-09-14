#ifndef PORTRAIT_H
#define PORTRAIT_H

#include "point.h"

#include <SFML/Graphics.hpp>

class Portrait {
	public:
		Portrait();
		~Portrait();
		Portrait(sf::Shape *shape);
		sf::Shape *shape;	
};

#endif
