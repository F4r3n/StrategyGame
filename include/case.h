#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "ground.h"
#include "box.h"

class Case {
	public:
		Case(Ground *ground);
		Case();
		~Case();
		void draw(sf::RenderWindow &window);
		void update(float dt);
		bool isWalkable();
	private:
		bool isReachable = true;
		std::unique_ptr<Ground> ground;
		std::unique_ptr<Box> box;
};

#endif
