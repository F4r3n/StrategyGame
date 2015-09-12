#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>


class Case {
	public:
		Case(sf::Shape *s,float x,float y);
		sf::Shape *s;
		float x,y;
};

#endif
