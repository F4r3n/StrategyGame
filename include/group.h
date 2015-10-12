#ifndef GROUP_H
#define GROUP_H

#include <map>
#include <vector>
#include "unit.h"

class Group {
	public:
		Group();
		Group(std::vector<Unit*> &units, Map *map);
		Group(Unit *unit, Map *map);
		~Group();
		void addUnit(Unit *unit);
		bool isExist(int id);
		bool refreshGroup();
		std::vector<Action*> allowedAction();
		void initPathFinder(Map *map);
		void setDestination(Map *map, Point arrivalPos);
		int getIdGroup();
		bool getDelete();
		void resetColor();
	private:
		static int idGroupTemp;
		int idGroup;
		std::map<int,Unit*> *units;
		std::map<Move,Action*> moves;
		bool isMixed = false;
		bool toDelete = false;
		PathFinder *pathFinder;
		

};

#endif
