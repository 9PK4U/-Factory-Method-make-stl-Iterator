#include "PlantElement.h"

PlantElement::ObjectPlant PlantElement::getObject() const
{
	return _objPlnt;
}

std::string PlantElement::getName() const
{
	std::string name;
	visit([&name](auto&& e) {name = e.getName();}, _objPlnt);
	return name;
}
std::string PlantElement::getType() const
{
	auto eObject = getObject();	
	if (std::get_if<Tree>(&eObject)) return "Tree";
	if (std::get_if<Bush>(&eObject)) return "Bush";
	if (std::get_if<Grass>(&eObject)) return "Grass";
}

bool PlantElement::operator==(const PlantElement& other) const
{
	return getName() == other.getName();
}

void PlantElement::operator=(const PlantElement& other)
{
	_objPlnt = other._objPlnt;
}

bool PlantElement::operator>(const PlantElement& other) const
{
	return getName() > other.getName();
}

bool PlantElement::operator<(const PlantElement& other) const
{
	return getName() < other.getName();
}

PlantElement& PlantElement::operator+=(PlantElement other)
{
	//x += other.x;
	return *this;
}

PlantElement& PlantElement::operator-=(PlantElement other)
{
	//x = x-other.x;
	return *this;
}
std::ostream& operator<<(std::ostream& out, const PlantElement& plantElement)
{
	auto eObject =plantElement.getObject();
	if (auto val = std::get_if<Tree>(&eObject))
	{
		out << "Type: Tree; Name: " << plantElement.getName() << "; ITIS: " << val->getITIS() << "; Age: " << val->getAge() << ";\n";
	}
	else if (auto val = std::get_if<Bush>(&eObject))
	{
		out << "Type: Bush; Name: " << plantElement.getName() << "; ITIS: " << val->getITIS() << "; Month: " << Month::MONTH_ARRAY[int(val->getMonthFlowering())] << ";\n";
	}
	else if (auto val = std::get_if<Grass>(&eObject))
	{
		out << "Type: Grass; Name: " << plantElement.getName() << "; ITIS: " << val->getITIS() << "; Length: " << val->getLength() << ";\n";
	}
	return out;
}
