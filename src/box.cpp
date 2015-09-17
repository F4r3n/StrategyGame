#include "box.h"

#include <iostream>
Box::Box(float x,float w, float y, float h) : x(x), w(w),y(y),h(h) {
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(w,h));
	shape->setPosition(x,y);
	shape->setFillColor(sf::Color::Black);
}

sf::RectangleShape* Box::getShape() {
	return shape;
}

Box::Box() {
	
	shape = new sf::RectangleShape();
}

void Box::configure(Point size, Point pos, sf::Color color) {
	shape->setSize(sf::Vector2f(size.x,size.y));
	shape->setPosition(pos.x, pos.y);

	shape->setFillColor(color);
	x = pos.x;
	y = pos.y;
	w = size.x;
	h = size.y;

}
Box::~Box() {
	delete shape;
}

float Box::getCenterX() {
	return (x + w)/2;
}

float Box::getCenterY() {
	return (y + h)/2;	
}


bool Box::AABB(Box *b) {
	if((b->x >= x + w)      // trop à droite
			  || (b->x + b->w <= x) // trop à gauche
			  || (b->y >= y + h) // trop en bas
			  || (b->y + b->h <= y))  // trop en haut
		return false; 
	else
		return true; 
}

bool Box::pointer(float cx, float cy) {
	if((cx >= x)
			  && (cx < x + w)
			  && (cy >= y)
			  && (cy < y + h))
		return true;
	else 
		return false;

}

bool Box::pointer(Point pos) {
	return pointer(pos.x, pos.y);
}
