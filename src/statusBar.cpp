#include "statusBar.h"
#include "engineConst.h"

StatusBar::StatusBar(float position, sf::Color color): position(position), color(color) {
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(EngineConst::WIDTH, EngineConst::HEIGHT/5));
	shape->setPosition(0, EngineConst::HEIGHT*position);
	shape->setFillColor(color);
}

void StatusBar::draw(sf::RenderWindow &window) {
	window.draw(*shape);
	for(Action *act : actions) {
		GUI *g = act->getGUI();
		g->draw(window);
	}
}

float StatusBar::getPositionBar() {
	return position;
}

void StatusBar::drawPortrait(sf::RenderWindow &window, sf::RectangleShape *shape){
	window.draw(*shape);
}

void StatusBar::update(float dt) {

}

void StatusBar::setPortrait(Portrait *por) {

}

std::vector<Action*> StatusBar::getActions() {
	return actions;
}
void StatusBar::setActions(std::vector<Action*> &actions) {
	int i=0;
	for(Action *act : actions) {
		act->configureGUI(Point(20,20), Point(EngineConst::WIDTH/2+i*20,EngineConst::HEIGHT*position+50), sf::Color::Black);
		i++;
	}
	this->actions = actions;
}

StatusBar::~StatusBar() {
	delete shape;

	for(auto *action : actions)
		delete action;


}
