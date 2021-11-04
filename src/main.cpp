#include <iostream>
#include "ParserPlantElement.h"


void Task(ListPlants* list, std::ostream& out)
{
	list->sortByName();
	//list->removeByType("Tree");
	list->removeByName("Tree_AAA");
	//list->removeElement(ParserPlantElements::parse("Type:Tree Name:Tree_AAA Age:7003 Itis:116"));

	out << *list;
}

int main(int argc, char* argv[])
{
	try
	{
		switch (argc)
		{
		case 2:
		{
			std::ifstream in(argv[1]);
			auto list = ParserPlantElements::parse(in, std::cout);
			Task(list, std::cout);
			in.close();
			delete list;
		}
		break;
		case 3:
		{
			std::ifstream in(argv[1]);
			std::ofstream out(argv[2]);
			auto list = ParserPlantElements::parse(in, std::cout);
			Task(list, out);
			in.close();
			out.close();
			delete list;
		}
		break;
		case 4:
		{
			std::ifstream in(argv[1]);
			std::ofstream out(argv[2]);
			std::ofstream log(argv[3]);
			auto list = ParserPlantElements::parse(in, log);
			Task(list, out);
			in.close();
			out.close();
			log.close();
			delete list;
		}
		break;
		default:
		{
			std::cout << "No such arguments" << std::endl;
		}
		break;
		}
	}
	catch (std::string& err)
	{
		std::cerr << err;
	}

	return 0;
}
