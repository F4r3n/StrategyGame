#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "GUI.h"
#include "screen.h"
#include "portrait.h"
#include <vector>
#include "action.h"
#include <memory>

class StatusBar : public Screen {
	public:
		StatusBar(float position, sf::Color color);
		~StatusBar();
		void draw(sf::RenderWindow &window);
		void drawPortrait(sf::RenderWindow &window, sf::RectangleShape *shape);
		void update(float dt);
		float getPositionBar();
		std::vector<Action*> getActions();
		void setPortrait(Portrait *por);
		void setActions(std::vector<Action*> &actions);
		void resetActions();
	private:
		float position;
		sf::Color color;
		Portrait *por;
		std::unique_ptr<sf::RectangleShape> shape;
		std::vector<Action*> actions;
		



};

#endif
