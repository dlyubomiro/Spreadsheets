#pragma once

#include "Cell.h"
#include "CellOfInt.h"
#include "CellOfDouble.h"
#include "CellOfText.h"
#include "Formula.h"


static int containtsOnlyNumbers(const char* text) 
{
	if (*text != '-' && *text != '+' &&( * text < '0' || *text > '9'))
		return -1;

	text++;
	while (*text)
	{
		if (*text < '0' || *text > '9')
		{
			if(*text != '.')
				return -1;
			return 1;
		}
		text++;
	}
	return 0;
}

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
	if(containtsOnlyNumbers(str) == 1)
		return new CellOfDouble(str);
	if (isFormula(str))
		return new Formula(str);
	else
		return new CellOfText(str);
}