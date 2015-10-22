#ifndef BUILD_GROUND_H
#define BUILD_GROUND_H

#include "ground.h"
#include <memory>

class BuildGround final : public Ground{
	public:
		BuildGround(Point pos, Point size, sf::Font *font);
		~BuildGround();
		void draw(sf::RenderWindow &window);
		void update(float dt);

	private:
		std::unique_ptr<sf::RectangleShape> shape;


};

#endif
