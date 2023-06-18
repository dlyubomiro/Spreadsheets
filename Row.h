#pragma once
#include "Cell.h"
#include "CellsFactory.h"
#include <sstream>
#include <iomanip>

class Row {
	Cell** cells;
	size_t count;
	size_t capacity;

	void resize();
	void copyFrom(const Row& other);
	void moveFrom(Row&& other);
	void free();
public:
	Row();
	Row(const Row& other);
	//Row(Row&& other);
	Row& operator=(const Row& other);
	//Row& operator=(Row&& other);
	~Row();
	void readRow(std::ifstream& ifs);
	void save(std::ofstream& ofs) const;
	void edit(size_t col, char* new_content);
	void printRow() const;
	size_t getCount() const;
	void removeSpaces( char* value);
};
