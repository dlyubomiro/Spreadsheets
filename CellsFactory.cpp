
#include "CellsFactory.h"

static bool isFormula(const char* text)
{
	if (*text != '=')
		return false;
	return true;
}

Cell* CellsFactory(const char* str)
{
	if (containtsOnlyNumbers(str) == 0)
		return new CellOfInt(str);
	if (containtsOnlyNumbers(str) == 1)
		return new CellOfDouble(str);
	if (isFormula(str))
		return new Formula(str);
	else
		return new CellOfText(str);
}