#pragma once
#include "Cell.h"
#include <iostream>

class CellOfDouble : public Cell {
	double content;

public:
	CellOfDouble() = default;
	CellOfDouble(const char* text);
	//void readCell(std::ifstream& ifs) override;
	//void writeCell(std::ofstream& ofs) override;

	void setContent(const char* text);
	double getValue() const;
	void print() const override;
	void save(std::ofstream& ofs) const override;
	Cell* clone() const override;
};

static size_t getSymbolIndex(const char* str, char ch)
{
	for (size_t i = 0; str ;i++)
	{
		if (*str == ch)
			return i;
		str++;
	}
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

CellOfDouble::CellOfDouble(const char* text) {
	setContent(text);
};

double CellOfDouble::getValue() const
{
	return content; 
}

void CellOfDouble::print() const {
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