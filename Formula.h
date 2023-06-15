#pragma once
#include "Cell.h"

class Formula : public Cell{
	MyString formula;

	double* numbers;
	size_t countNums;
	size_t capNums;
	char* operands;
	size_t countOp;
	size_t capOp;
	
	void resizeNumbers();
	void resizeOp();
public:
	Formula(const char* text);
	void setFormula(const char* text);

	double calculate(const MyString& formula);
	void print() const override;
	void save(std::ofstream& ofs) const override;
	Cell* clone() const override;
};

Formula::Formula(const char* text)
{
	setFormula(text);
}

void Formula::setFormula(const char* text)
{
	formula = MyString(text);
	double currentNum = 0;
	for (int i = 0; i < formula.length(); i++)
	{
		if (formula[i] >= '0' && formula[i] <= '9')
			(currentNum *= 10) += formula[i];
		else
		{
			numbers[countNums++] = currentNum;
			currentNum = 0;
			operands[countOp++] = formula[i];
		}
	}
}

void Formula::print() const
{
	 std::cout << formula;
}

Cell* Formula::clone() const
{
	Cell* newCell = new Formula(*this);
	return newCell;
}

void Formula::save(std::ofstream& ofs) const 
{
	ofs << formula;
}

static bool conatinsOnlyNumbers(const MyString& formula)
{
	for (int i = 0; i < formula.length();i++)
	{
		if (formula[i] >= 'A' && formula[i] <= 'Z')
			return false;
	}
	return true;
}

double Formula::calculate(const MyString& formula)
{

	double res = 0;
	for (int i = 0; i < formula.length(); i++)
	{
		if(formula[i]>= '0' && formula[i] <= '0')

	}
}