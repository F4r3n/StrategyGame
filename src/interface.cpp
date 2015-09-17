#include "interface.h"

Interface::Interface() {
	border = new UIBorder();
	statusBar = new StatusBar(0.8,sf::Color(100,100,100));
}

void Interface::draw(sf::RenderWindow &window) {
	border->draw(window);
	statusBar->draw(window);
}

float Interface::getPositionBar() {
	return statusBar->getPositionBar();
}
void Interface::update(float dt) {
	border->update(dt);
}

std::vector<Action*> Interface::getActions() {
	return statusBar->getActions();
}

void Interface::update(float dt, sf::View &view) {
	border->update(dt, view);
	
}
void Interface::sendInterfaceActions(std::vector<Action*> &actions) {
	statusBar->setActions(actions);
}

Interface::~Interface() {
	delete border;
	delete statusBar;
}
