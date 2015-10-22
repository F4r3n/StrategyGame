
#ifndef OBSTACLE_GROUND_H
#define OBSTACLE_GROUND_H

#include "ground.h"
#include <memory>

class ObstacleGround : public Ground{
	public:
		ObstacleGround(Point pos, Point size, sf::Font *font);
		~ObstacleGround();
		void draw(sf::RenderWindow &window);
		void update(float dt);

	private:
		std::unique_ptr<sf::RectangleShape> shape;


};

#endif
