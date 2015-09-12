#ifndef SCREEN_H
#define SCREEN_H


#include <SFML/Graphics.hpp>

class Screen {
	public:
		virtual void update(float dt)=0;
		virtual void draw(sf::RenderWindow &window)=0;
		virtual ~Screen();
		Screen();

};


#endif
