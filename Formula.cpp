#include "Formula.h"
Formula::Formula(const char* text)
{
	setFormula(text);
}

static bool containsOnlyNumsAndOps(const char* text)
{
	while (text)
	{
		if (!(*text >= '0' && *text <= '9' || *text == '+' || *text == '-' || *text == '/'
			|| *text == '^' || *text == '*'))
			return false;

		text++;
	}
	return true;
}

void Formula::setFormula(const char* text)
{/*
	if (containsOnlyNumsAndOps(text))
		formula = MyString(convertToString(calculate(text)));
	else
		formula = MyString(text);*/
		formula = MyString(text);
}

static int getRowIndex(const MyString& formula)
{
	int rowInd = 0;
	for (size_t i = 0; i < formula.length(); i++)
	{
		if (formula[i] == 'R')
		{
			rowInd = i + 1;
			if (formula[i + 2] != 'C')
			{
				(rowInd *= 10) += formula[i + 2];
				return rowInd;
			}
		}
	}
	return -1;
}

static int getColIndex(const MyString& formula)
{
	int colInd = 0;
	for (size_t i = 0; i < formula.length(); i++)
	{
		if (formula[i] == 'C')
		{
			colInd = i;
		}
	}
	int colValue = 0;
	for (size_t i = colInd+1; i < formula.length(); i++)
	{
		(colValue *= 10) += formula[i];
	}
	return colValue;
}


static void replace(MyString& formula, size_t begin, size_t end, double value)
{
	
}

void Formula::print()
{
	if (containsOnlyNumsAndOps(formula.c_str()))
		formula = MyString(convertToString(calculate(formula.c_str())));

	//else if (isCell(formula.substr(1, getOperationIndex(formula) - 1)))
	//{
	//	size_t rowIndex = getRowIndex(formula);
	//	size_t colIndex = getRowIndex(formula);

	//	
	//	//
	//	//{ 
	//	//	double value = table.rows[rowIndex].getValueFromCell(colIndex);
	//	//	/*replace(formula, 1, getOperationIndex(formula) - 1, value);*/
	//	//}
	//}
	//
	
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
	MyString toCalc = formula.substr(1, formula.length() - 1);
	double res = 0;
	int opInd = getOperationIndex(toCalc);
	char op = toCalc[opInd];

	//if (isCell(toCalc.substr(0, opInd)));


	double lhs = convertStringToDouble(toCalc.substr(0, opInd).c_str());
	double rhs = convertStringToDouble(toCalc.substr(opInd + 1, toCalc.length() - opInd - 1).c_str());

	switch (op)
	{
	case '+':
		return lhs + rhs;

	case '*':
		return lhs * rhs;

	case '/':
		if(abs(rhs) < 0.0001)
			
		return lhs / rhs;

	case '^':
		return pow(lhs, rhs);

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

static bool isCell(const MyString& text)
{
	if ((text[0] == 'R' && text[text.length() - 2] == 'C') || (text[0] == 'R' && text[text.length() - 3] == 'C'))
		return true;
	else
		return false;
}

