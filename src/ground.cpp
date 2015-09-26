#include "ground.h"

Ground::Ground(Point pos, Point size): pos(pos), size(size) {

}

Point Ground::getPos() {
	return pos;
}

Point Ground::getSize() {
	return size;
}

Ground::Ground() {}

Ground::~Ground() {
}

void Ground::draw(sf::RenderWindow &window) {

}

void Ground::update(float dt) {
}
