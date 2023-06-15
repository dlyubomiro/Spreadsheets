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


/*void CellOfInt::writeCell(std::ofstream& ofs)
{
	if (ofs.is_open())
		throw std::exception("Cannot open the file!");

	ofs << _content;
}

void CellOfInt::readCell(std::ifstream& ifs)
{
	if (ifs.is_open())
		throw std::exception("Cannot open the file!");

	ifs >> _content;
}
*/

void CellOfInt::print() const
{
	std::cout << _content;
}


void CellOfInt :: save(std::ofstream& ofs) const
{
	ofs << _content;
}