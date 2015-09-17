#ifndef ACTION_H
#define ACTION_H
#include "GUI.h"
enum Move {STRAIGHT_AT_CLICK};

class Action {
	public:
		Action(Move act);
		Move getAct();
		Box* getBox();
		void configureGUI(Point size, Point pos, sf::Color color);
		bool cursorIn(Point pos);
		GUI* getGUI();
		~Action();
	private:
		GUI *gui;
		Move act;


};

#endif
