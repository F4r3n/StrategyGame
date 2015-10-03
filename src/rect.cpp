#include "rect.h"
#include <math.h>
Rect::Rect(){}

Rect::Rect(int x, int y, int w, int h): x(x), y(y), w(w), h(h) {}


Rect::Rect(Point pos, Point posEnd, Position type) {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	if(type == Position::START_END) {
		if(pos.y < posEnd.y && pos.x > posEnd.x) {
			y = pos.y;
			w = pos.x - posEnd.x;

			x = pos.x - w;
			h = posEnd.y - pos.y;
		}else if(pos.y > posEnd.y && pos.x > posEnd.x) {
			x = posEnd.x;
			y = posEnd.y;

			w = pos.x - posEnd.x;
			h = pos.y - posEnd.y;
		}else if(pos.x < posEnd.x && pos.y < posEnd.y) {
			x = pos.x;
			y = pos.y;

			w = posEnd.x - pos.x;
			h = posEnd.y - pos.y;
		}else if(pos.x < posEnd.x && pos.y > posEnd.y) {
			y = posEnd.y;
			w = posEnd.x - pos.x;

			x = posEnd.x - w;
			h = pos.y - posEnd.y;
		}
	}else if(type == Position::START_SIZE) {
		x = pos.x;
		y = pos.y;

		w = posEnd.x;
		h = posEnd.y;
	}
}

Rect::Rect(sf::Vector2f v, int offsetX, int offsetY) {
	x = v.x + offsetX;
	y = v.y + offsetY;
}

Rect& Rect::operator/(const Rect &p) {
	x/=p.x;
	y/=p.y;
	return *this;
}
Rect& Rect::operator-(const Rect &p) {
	x-=p.x;
	y-=p.y;
	return *this;
}
std::ostream& operator<<(std::ostream &o, Rect p) {
	o << p.x << " " << p.y << " " << p.w << " " << p.h;
	return o;
}
Rect::Rect(sf::Vector2i v) {
	x = v.x;
	y = v.y;
}
bool Rect::operator!=(const Rect &p) {
	return (p.x != x || p.y!=y  || p.w !=w || p.h!=h);
}
bool Rect::operator==(const Rect &p) {
	return (p.x == x && p.y==y && p.w == w && p.h == h);
}

Rect& Rect::operator+(const Rect &p) {
	x += p.x;
	y += p.y;
	return *this;
}

Rect& Rect::operator=(const Rect &p) {
	x = p.x;
	y = p.y;
	w = p.w;
	h = p.h;
	return *this;
}

Rect::~Rect() {

}
