#include "interface.h"

Interface::Interface() {
	border = new UIBorder();
}

void Interface::draw(sf::RenderWindow &window) {
	border->draw(window);
}

void Interface::update(float dt) {
	border->update(dt);
}


void Interface::update(float dt, sf::View &view) {
	border->update(dt, view);
	
}

Interface::~Interface() {
	delete border;
}
