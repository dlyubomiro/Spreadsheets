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

Formula::Formula(const char* text)
{
	setFormula(text);
}

void Formula::setFormula(const char* text)
{
	formula = MyString(convertToString(calculate(text)));
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

MyString removeEquationSign(const MyString& formula)
{
	return formula.substr(1, formula.length());
}

int getOperationIndex(const MyString& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+' || str[i] == '^')
			return i;
	}
	return -1;
}

double Formula::calculate(const MyString& formula) const
{
	MyString toCalc = formula.substr(1, formula.length()-1);
	double res = 0;
	int opInd = getOperationIndex(toCalc);
	char op = toCalc[opInd];
	double lhs = convertStringToDouble(toCalc.substr(0, opInd).c_str());
	double rhs = convertStringToDouble(toCalc.substr(opInd+1, toCalc.length()- opInd - 1).c_str());

	switch (op)
	{
	case '+':
		return lhs + rhs;

	case '*':
		return lhs * rhs;

	case '/':			
		return lhs / rhs;

	case '^':
		return pow(lhs,rhs);

	case '-':
		return lhs - rhs;

	default:
		break;
	}
}

MyString Formula::getData() const
{
	return MyString(formula);
}

double Formula::getValueInDouble() const
{
	return calculate(formula);
}