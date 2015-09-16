#ifndef GROUP_H
#define GROUP_H

#include <map>
#include "unit.h"
class Group {
	public:
		Group();
		~Group();
		void addUnit(Unit *unit);
		bool isExist(int id);
		void refreshGroup();
	private:
		static int idGroup;
		std::map<int,Unit*> *units;
		

};

#endif
