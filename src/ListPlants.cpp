#pragma once
#include "ListPlants.h"

void ListPlants::pushBack(PlantElement el)
{
	addElement(el);
}

void ListPlants::popBack()
{
	if (size() > 0)
	{
		auto it = --end();
		auto el = it.value->operator*();
		remove(el);
	}
}

void ListPlants::remove(PlantElement &el)
{
	removeElement(el);
}

void ListPlants::removeByName(std::string name)
{
	for (auto it : *this)
	{
		if ((*it).getName() == name)
		{
			auto val = *it;
			remove(val);
			break;
		}
	}
}
void ListPlants::removeByType(std::string type)
{
	int is = true;
	while (is)
	{
		is = false;
		for (auto it : *this)
		{
			if ((*it).getType() == type)
			{
				auto val = *it;
				remove(val);
				is = true;
				break;
			}
		}
	}
}

bool ListPlants::empty() const
{
	return size()==0;
}

void ListPlants::sortByName()
{
	#ifdef linux
	
	bool is = !empty();
      	while (is)
		{
			is = false;


		for(auto  it = begin(),nxIt = ++begin(); nxIt != end() ; ++nxIt, ++it)
			{

				if(it.operator*().operator*().getName() > (nxIt).operator*().operator*().getName())
				{
					// std::cout << "||";
					is = true;
					auto tmp = it.operator*().operator*();
					it.operator*().getData(nxIt.operator*().operator*());
					nxIt.operator*().getData(tmp);

				}
			}
		} 
		  
	
  	#else
		std::sort(begin(), end(), [](Node<PlantElement> a, Node<PlantElement> b) {return (*a) < (*b); });
  	#endif
	 


}

std::ostream& operator<<(std::ostream& out, ListPlants& list)
{
	out << "\n" << "-----------ListPlants------------";
	out << "\n" << "size: " << list.size() << "\n";
	for (auto &it : list)
	{
		out << *it;
	}
	out << "\n" << "---------------------------------";
	return out;
}
