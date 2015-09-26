#include "case.h"


Case::Case(Ground *gr){
	ground = std::unique_ptr<Ground>(gr);
}

void Case::draw(sf::RenderWindow &window) {
	ground->draw(window);
}

void Case::update(float dt) {
	ground->update(dt);
}

Case::~Case() {

}
