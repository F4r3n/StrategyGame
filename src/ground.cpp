#include "ground.h"
#include <iostream>
Ground::Ground(Point pos, Point size, sf::Font *font): pos(pos), size(size) {
    this->font = font;
    text.setFont(*font);
 //   text.setString("y");
    text.setPosition(pos.x, pos.y);
    text.setCharacterSize(10);
    text.setColor(sf::Color::Black);
}

void Ground::setString(const std::string &s) {
    text.setString(s);
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
    window.draw(text);
}

bool Ground::isWalkable() {
    //	std::cout << walkable << std::endl;	
    return walkable;
}

void Ground::update(float dt) {
}
