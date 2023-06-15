#pragma once
#include "Cell.h"

class CellOfInt : public Cell{
	int _content;

public:
	CellOfInt() = default;
	CellOfInt(const char* content);

	//void writeCell(std::ofstream& ofs) override;
	//void readCell(std::ifstream& ifs) override;
	void print() const override;
	Cell* clone() const override;

	void save(std::ofstream& ofs) const override;
	void setContent(const char* text);
};
