#include "CellOfDouble.h"

static size_t getSymbolIndex(const char* str, char ch)
{
	for (size_t i = 0; str;i++)
	{
		if (*str == ch)
			return i;
		str++;
	}
	throw std::logic_error("Invalid index");
}

void CellOfDouble::setContent(const char* text)
{
	size_t ind = getSymbolIndex(text, '.');

	unsigned mult = 1;
	if (*text == '-')
	{
		mult = -1;
		text++;
	}
	else if (*text == '+')
		text++;
	double result = atof(text);
	content = mult * result;
}

CellOfDouble::CellOfDouble(const char* text)
{
	setContent(text);
};

double CellOfDouble::getValueInDouble() const
{
	return content;
}

void CellOfDouble::print() const
{
	std::cout << content;
}

Cell* CellOfDouble::clone() const
{
	Cell* newCell = new CellOfDouble(*this);
	return newCell;
}

void CellOfDouble::save(std::ofstream& ofs) const
{
	ofs << content;
}

MyString CellOfDouble::getData() const
{
	return MyString("");
}