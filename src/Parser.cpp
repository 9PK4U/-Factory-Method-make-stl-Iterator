#include "Parser.h"

using namespace std::string_literals;

Parser::StringList Parser::Split(const string& fullStr, const string& delim)
{
    StringList lstStr;
    size_t prev = 0, pos = 0;
    do
    {
        pos = fullStr.find(delim, prev);
        if (pos == string::npos) pos = fullStr.length();
        string str = fullStr.substr(prev, pos - prev);
        if (!str.empty()) lstStr.push_back(str);
        prev = pos + delim.length();
    } while (pos < fullStr.length() && prev < fullStr.length());
    if (lstStr.size() == 0) throw std::string("Line is empty!");
    return lstStr;
}
Parser::ParseMap Parser::parse(const string& str)
{
    ParseMap map;
    if (str.empty())
    {
        throw std::string("Line is empty!");
    }

    auto list = Split(str, " ");
    for (auto it : list)
    {
        auto pair = parsePairStr(it, ":");
        map[pair.first] = pair.second;
    }
	return map;
}

Parser::PairStr Parser::parsePairStr(const string& str, const string& delim)
{
    auto list = Split(str, delim);
    if (list.size() != 2)
    {

        throw std::string(("Value:\""s + str + "\" Can't split a string into two words!").c_str());
    }
    return PairStr(list.front(),list.back());
}
