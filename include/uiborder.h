#ifndef UIBORDER_H
#define UIBORDER_H

#include "screen.h"
#include "engineConst.h"
#include "GUI.h"
#include <iostream>
#include <vector>

class UIBorder : public Screen{
	public:
		UIBorder();
		~UIBorder();
		void draw(sf::RenderWindow &window);
		void update(float dt);
		void update(float dt, sf::View &view);


	private:
		std::vector<GUI*> borders;
		sf::Vector2i mousePos;
		sf::Vector2f centerView;
		float speed = 300;	
		int numberBorder = 4;
		int offset = 20;
		

};

#endif
