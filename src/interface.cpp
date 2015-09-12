#include "interface.h"

Interface::Interface() {
	border = new UIBorder();
}

void Interface::draw(sf::RenderWindow &window) {
	border->draw(window);
}

void Interface::update(float dt) {

}
