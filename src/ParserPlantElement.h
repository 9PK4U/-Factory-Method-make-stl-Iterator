#include <string>
#include <vector>
#include <fstream>
#include "ListPlants.h"
#include "Parser.h"

using namespace std::string_literals;
class ParserPlantElements
{
public:
	enum class Types { TREE, BUSH, GRASS};
	static ListPlants* parse(std::ifstream& inputStream, std::ostream & errStream = std::cerr);
	static PlantElement parse(const std::string&);

private:
	static string& valAtrbt(Parser::ParseMap& map,const std::string& atrbt);
	static Types valType(const  string& type);
	static unsigned long valAge(const string& ageStr);
	static string valName(const string& nameStr);
	static unsigned int valLength(const string& lenghtStr);
	static unsigned int valITIS(const string& itisStr);
	static Month::Month valMonth(const string& monthStr);



};
