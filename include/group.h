#ifndef GROUP_H
#define GROUP_H

#include <map>
#include <vector>
#include "unit.h"

class Group {
	public:
		Group();
		Group(std::vector<Unit*> *units);
		Group(Unit *unit, Map *map);
		~Group();
		void addUnit(Unit *unit);
		bool isExist(int id);
		void refreshGroup();
		std::vector<Action*> allowedAction();
		void initPathFinder(Map *map);
		void setDestination(Point arrivalCasePos, Point arrivalPos);
		int getIdGroup();
	private:
		static int idGroupTemp;
		int idGroup;
		std::map<int,Unit*> *units;
		std::map<Move,Action*> moves;
		bool isMixed = false;
		PathFinder *pathFinder;
		

};

#endif
