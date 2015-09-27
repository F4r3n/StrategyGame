#include "case.h"
#include "engineConst.h"
#include <iostream>
Case::Case(Ground *gr){
	ground = std::unique_ptr<Ground>(gr);
	box = std::unique_ptr<Box>(new Box(gr->getPos(), gr->getSize()));
}

void Case::draw(sf::RenderWindow &window) {
	sf::Vector2f s(window.getView().getSize());
	sf::Vector2f p(window.getView().getCenter());
	Box b = Box(Point(p,-400,-300), Point(s));
//	std::cout << b.x << " " << b.y << " " << b.w << " " << b.h << std::endl;
	if(box->AABB(&b))
		ground->draw(window);
}

void Case::update(float dt) {
	ground->update(dt);
}

Case::~Case() {

}
