#pragma once
#include <iostream>
#include <fstream>

enum class CellType
{
	Int,
	Double,
	String,
	Formula
};

class Cell
{
public:
	virtual void print() const = 0;
	virtual Cell* clone() const = 0;
	virtual void save(std::ofstream& ofs) const = 0;
	virtual ~Cell() = default;
};
