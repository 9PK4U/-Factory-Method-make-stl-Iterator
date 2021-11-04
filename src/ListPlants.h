#pragma once
#include <algorithm>
#include "PlantElement.h"
#include "RingList.h"
class ListPlants : public RingList<PlantElement>
{
public:
	void pushBack(PlantElement el);
	void popBack();
	void remove(PlantElement &el);
	void removeByName(std::string name);
	void removeByType(std::string name);
	bool empty() const;
	void sortByName();
	friend std::ostream& operator<< (std::ostream& out, ListPlants& list);
};

