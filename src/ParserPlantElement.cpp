#include "ParserPlantElement.h"

PlantElement ParserPlantElements::parse(const std::string& str)
{
	auto values = Parser::parse(str);
	string typeStr = valAtrbt(values, "Type");
	string nameStr = valAtrbt(values, "Name");
	string itisStr = valAtrbt(values, "Itis");

	switch (valType(typeStr))
	{
	case Types::TREE:
	{
		string ageStr = valAtrbt(values, "Age");
		PlantElement plant(Tree(valName(nameStr), valAge(ageStr), valITIS(itisStr)));
		return plant;
	}
	break;
	case Types::BUSH:
	{
		string monthStr = valAtrbt(values, "Month");
		PlantElement plant(Bush(valName(nameStr), valMonth(monthStr), valITIS(itisStr)));
		return plant;
	}
	break;
	case Types::GRASS:
	{
		string lengthStr = valAtrbt(values, "Length");
		PlantElement plant(Grass(valName(nameStr), valLength(lengthStr), valITIS(itisStr)));
		return plant;
	}
	}
}

ListPlants* ParserPlantElements::parse(std::ifstream& in, std::ostream& out)
{
	ListPlants* list = new ListPlants;
	int lineIndx = 0;
	if (!in.is_open())
	{
		throw std::string("File can not open");
	}
	while (!in.eof())
	{
		string str;
		std::getline(in, str);
		lineIndx++;
		try
		{
			list->pushBack(parse(str));
		}
		catch (const std::string& err)
		{
			out << "line:" << lineIndx << "; Error:" << err << "\n";
		}
		//std::cout << str << endl;
	}

	return list;
}

string& ParserPlantElements::valAtrbt(Parser::ParseMap& map, const std::string& atrbt)
{
	if (map.find(atrbt) == map.end())
	{
		throw std::string((string("Atrribute \"") + atrbt + "\" is not found!").c_str());
	}
	return map[atrbt];
}
ParserPlantElements::Types ParserPlantElements::valType(const  string& type)
{
	if (type == "Tree") { return Types::TREE; }
	else if (type == "Bush") { return Types::BUSH; }
	else if (type == "Grass") { return Types::GRASS; }
	else
	{
		throw std::string((type + " is wrong type!").c_str());
	}
}
unsigned long  ParserPlantElements::valAge(const  string& ageStr)
{
	for (auto& it : ageStr)
	{
		if (!isdigit(it))
		{
			throw std::string((ageStr + " is not a age").c_str());
		}

	}
	return atol(ageStr.c_str());
}
string ParserPlantElements::valName(const string& nameStr)
{
	if (!isupper(nameStr[0]))
	{
		throw std::string((nameStr + " is wrong name").c_str());
	}
	for (auto& it : nameStr)
	{
		if (!isalpha(it) && it != '_')
		{
			throw std::string((nameStr + " is wrong name").c_str());
		}

	}
	return nameStr;

}
unsigned int ParserPlantElements::valLength(const string& lenghtStr)
{
	for (auto& it : lenghtStr)
	{
		if (!isdigit(it))
		{
			throw std::string((lenghtStr + " is not a length").c_str());
		}

	}
	return atol(lenghtStr.c_str());
}
unsigned int ParserPlantElements::valITIS(const string& itisStr)
{
	for (auto& it : itisStr)
	{
		if (!isdigit(it))
		{
			throw std::string((itisStr + " is not a ITIS").c_str());
		}

	}
	return atol(itisStr.c_str());
}
Month::Month ParserPlantElements::valMonth(const string& monthStr)
{
	for (int i = 0; i < 12; i++)
	{
		if(monthStr == std::string(Month::MONTH_ARRAY[i]))
			return Month::Month(i);
	}
	
	throw std::string((monthStr + " is not a month").c_str());
}
