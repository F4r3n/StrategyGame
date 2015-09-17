#include "action.h"
#include <iostream>
Action::Action(Move act):act(act) {
}

Move Action::getAct() {
	return act;
}

Box* Action::getBox() {
	return gui->getBox();
}

GUI* Action::getGUI() {
	return gui;
}

bool Action::cursorIn(Point pos) {
	return gui->cursorIn(pos.x, pos.y);
}

void Action::configureGUI(Point size, Point pos, sf::Color color) {
	gui = new GUI(new Box(pos.x, size.x, pos.y, size.y), color, sf::Color::White);
}

Action::~Action() {
	delete gui;
}
