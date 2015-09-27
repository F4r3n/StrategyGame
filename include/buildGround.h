#ifndef BUILD_GROUND_H
#define BUILD_GROUND_H

#include "ground.h"
#include <memory>

class BuildGround : public Ground{
	public:
		BuildGround(Point pos, Point size);
		~BuildGround();
		void draw(sf::RenderWindow &window);
		void update(float dt);

	private:
		std::unique_ptr<sf::RectangleShape> shape;


};

#endif