#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "ground.h"
#include "point.h"

class Case {
	public:
		Case(Ground *ground);
		Case();
		~Case();
		void draw(sf::RenderWindow &window);
		void update(float dt);
	private:
		bool isReachable = true;
		Point pos;
		Point size;
		std::unique_ptr<Ground> ground;
};

#endif
