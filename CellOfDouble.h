#pragma once
#include "Cell.h"
#include "Utilities.h"
#include <iostream>

class CellOfDouble : public Cell {
	double content;

public:
	CellOfDouble() = default;
	CellOfDouble(const char* text);

	void setContent(const char* text);
	double getValueInDouble() const override;

	MyString getData() const override;
	void print() const override;
	void save(std::ofstream& ofs) const override;
	Cell* clone() const override;
};
