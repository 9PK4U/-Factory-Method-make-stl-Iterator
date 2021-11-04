#include <variant>
#include "Plants.h"
class PlantElement
{
public:
	using ObjectPlant = std::variant<Tree, Bush, Grass>;
	ObjectPlant getObject() const;
	std::string getType() const;
	std::string getName() const;
	//�������� ������ ���������� ��� ��� ������
private:
	ObjectPlant _objPlnt;

public:

	bool			operator==	(const PlantElement& other) const;
	void			operator=	(const PlantElement& other);
	bool			operator>	(const PlantElement& other) const;
	bool			operator<	(const PlantElement& other) const;
	PlantElement&	operator+=	(PlantElement other);
	PlantElement&	operator-=	(PlantElement other);
	PlantElement(Tree object)   : _objPlnt(object) {};
	PlantElement(Bush object)   : _objPlnt(object) {};
	PlantElement(Grass object)  : _objPlnt(object) {};
	PlantElement() = delete;
	friend std::ostream& operator<< (std::ostream& out, const PlantElement& element);

};

