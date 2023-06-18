#pragma once
#include "Cell.h"
#include "MyString.h"
#include "StringView.h"
#include "Utilities.h"

class CellOfText : public Cell {
	MyString content;

public:
	CellOfText() = default;
	CellOfText(const char*);
	MyString getData() const override;
	double getValueInDouble() const override;

	Cell* clone() const override;
	void save(std::ofstream& ofs) const override;
	void print() const override;
};