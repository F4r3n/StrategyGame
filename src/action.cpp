#include "action.h"

Action::Action(Move act):act(act) {
	box = new Box();
}

Move Action::getAct() {
	return act;
}

Action::~Action() {
	delete box;
}
