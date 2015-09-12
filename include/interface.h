#ifndef INTERFACE_H
#define INTERFACE_H

#include "screen.h"
#include "uiborder.h"
class Interface : public Screen{
	public:
		Interface();
		void draw(sf::RenderWindow &window);
		void update(float dt);
		void update(float dt, sf::View &view);
		~Interface();
	private:
		UIBorder *border;
};

#endif
