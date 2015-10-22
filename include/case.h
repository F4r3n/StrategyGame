#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "ground.h"
#include "box.h"

typedef struct SimpleCase {
	bool value;
	Point pos;
	Box box;
}SimpleCase;

class Case {
	public:
		Case(Ground *ground);
		Case();
		~Case();
		void draw(sf::RenderWindow &window);
		void update(float dt);
		bool isWalkable();
		void setUnitOn(bool value);
        void setVector(Point vector);
        Point getVector();
		bool isUnitOn();
        void setString(const std::string &s);
        void setWeight(int w);
        int getWeight();
	private:
		bool isReachable = true;
		std::unique_ptr<Ground> ground;
		std::unique_ptr<Box> box;
        Point vector;
        int weight=0;
};

#endif
