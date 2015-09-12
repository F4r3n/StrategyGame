#include "box.h"

#include <iostream>
Box::Box(float x,float w, float y, float h) : x(x), w(w),y(y),h(h) {

}

Box::Box() {

}

Box::~Box() {

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

