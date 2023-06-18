#pragma once
#include "Cell.h"
#include "Utilities.h"

class Formula : public Cell{
	MyString formula;

public:
	Formula(const char* text);
	void setFormula(const char* text);

	double calculate(const MyString& formula) const;
	void print() const override;
	void save(std::ofstream& ofs) const override;
	Cell* clone() const override;
	MyString getData() const override;
	double getValueInDouble() const override;
};
