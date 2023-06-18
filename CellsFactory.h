#pragma once

#include "Cell.h"
#include "CellOfInt.h"
#include "CellOfDouble.h"
#include "CellOfText.h"
#include "Formula.h"
#include "Utilities.h"

static bool isFormula(const char* text);

Cell* CellsFactory(const char* str);