#include <map>
#include <string>
#include <list>
#include <vector>
#include <fstream>
//#include <vld.h>
using std::string;
class Parser
{
public:
	using ParseMap = std::map<string,string>;
	using StringList = std::list<string>;
	using PairStr = std::pair<string,string>;

	//����� ������������ � ������ �������
	static Parser::StringList Split(const string& str, const string& delim);

	static ParseMap parse(const string& str);
	static PairStr parsePairStr(const string& str, const string& delim);

private:
};

