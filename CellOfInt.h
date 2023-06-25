#pragma once
#include "Cell.h"
#include "Utilities.h"

class CellOfInt : public Cell{
	int _content;

public:
	CellOfInt() = default;
	CellOfInt(const char* content);

	void print() override;
	Cell* clone() const override;

	MyString getData() const override;
	double getValueInDouble() const override;

	void save(std::ofstream& ofs) const override;
	void setContent(const char* text);

};
