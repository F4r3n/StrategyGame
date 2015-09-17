#ifndef INTERFACE_H
#define INTERFACE_H

#include "screen.h"
#include "uiborder.h"
#include "statusBar.h"

class Interface : public Screen{
	public:
		Interface();
		void draw(sf::RenderWindow &window);
		void update(float dt);
		void update(float dt, sf::View &view);
		void sendInterfaceActions(std::vector<Action*> &actions);
		std::vector<Action*> getActions();
		float getPositionBar();
		~Interface();
	private:
		UIBorder *border;
		StatusBar *statusBar;
		
};

#endif
