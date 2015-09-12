#include "GUI.h"

GUI::GUI() {

}

GUI::GUI( Box box, sf::Color color): color(color), box(box) {
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(box.w, box.h));
	shape->setPosition(box.x, box.y);
	shape->setFillColor(color);
}

void GUI::draw(sf::RenderWindow &window) {
	window.draw(*shape);
}
