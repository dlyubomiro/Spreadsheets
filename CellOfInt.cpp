#include "CellOfInt.h"
#include <iostream>

void CellOfInt::setContent(const char* content)
{
	unsigned mult = 1;
	if (*content == '-')
	{
		mult = -1;
		content++;
	}
	else if (*content == '+')
		content++;

	int result = 0;
	while (*content)
	{
		(result *= 10) += (*content) - '0';
		content++;
	}
	_content = result *= mult;
}

CellOfInt::CellOfInt(const char* content) {
	setContent(content);
};

Cell* CellOfInt::clone() const
{
	Cell* newCell = new CellOfInt(*this);
	return newCell;
}

void CellOfInt::print()
{
	std::cout << _content;
}

void CellOfInt :: save(std::ofstream& ofs) const
{
	ofs << _content;
}

 MyString CellOfInt::getData() const
{
	return MyString (convertIntToString(_content));
}

 double CellOfInt::getValueInDouble() const
 {
	 return _content;
 }
