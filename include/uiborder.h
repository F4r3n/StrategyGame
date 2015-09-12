#ifndef UIBORDER_H
#define UIBORDER_H

#include "screen.h"
#include "engineConst.h"
#include "GUI.h"

class UIBorder : public Screen{
	public:
		UIBorder();
		~UIBorder();
		void draw(sf::RenderWindow &window);
		void update(float dt);


	private:
		GUI *borders;
		sf::Vector2i mousePos;
		int numberBorder = 4;
		int offset = 20;
		

};

#endif
