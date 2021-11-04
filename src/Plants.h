#include <string>
#include <iostream>

namespace Month
{
	enum class Month {
#   define X(a) a,
#   include "Months.def"
#   undef X
		MonthCount
	};
	char const* const MONTH_ARRAY[] = {
	#   define X(a) #a,
	#   include "Months.def"
	#   undef X
		   0
	};
}


class _PrPlant
{
protected:
	std::string name;
	unsigned int _itis;
public:
	unsigned int getITIS() const
	{
		return _itis;
	}
	std::string getName() const
	{
		return name;
	}
	void setName(unsigned int value)
	{
		_itis = value;
	}
	void setName(std::string value)
	{
		if (value.empty())
			throw std::string("Wrong name format.");
		name = value;
	}
	_PrPlant(std::string value, unsigned int ITIS) : _itis(ITIS)
	{
		setName(value);
	}
};

class Bush : public _PrPlant
{
private:
	Month::Month floweringMonth;
public:
	Month::Month getMonthFlowering() const
	{
		return floweringMonth;
	}
	void setMonthFlowering(Month::Month value)
	{
		floweringMonth = value;
	}
	Bush(std::string name, Month::Month floweringMonth, unsigned int ITIS) : _PrPlant(name,ITIS), floweringMonth(floweringMonth)
	{
	}
};

class Tree : public _PrPlant
{
private:
	unsigned long age;
public:
	unsigned long getAge() const
	{
		return age;
	}
	void setAge(unsigned long value)
	{
		age = value;
	}
	Tree(std::string name, unsigned long age, unsigned int ITIS) : _PrPlant(name, ITIS), age(age)
	{
	}
};
class Grass : public _PrPlant
{
private:
	unsigned int length;
public:
	unsigned int getLength() const
	{
		return length;
	}
	void setlength(unsigned int value)
	{
		length = value;
	}
	Grass(std::string name, unsigned int length, unsigned int ITIS) : _PrPlant(name, ITIS), length(length)
	{
	}
};
