#ifndef ACTION_H
#define ACTION_H
#include "box.h"

enum Move {STRAIGHT_AT_CLICK};

class Action {
	public:
		Action(Move act);
		Move getAct();
		~Action();
	private:
		Box *box;
		Move act;


};

#endif
