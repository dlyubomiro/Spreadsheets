#pragma once
#include "Row.h"

class Table{
public:
	Row* rows;
	size_t count;
	size_t capacity;
	size_t countOfCols = 0;

	void resize();
public:
	Table();
	void open(const char* filename);
	void save(const char* filename) const;
	void saveAs() const;
	void edit();
	void print() const;
	void calculateFormulas();
	//void openToRead(const char* filename) const;
	//void openToWrite(const char* filename) const;
	void close(std::ifstream& ifs) const;
	void close(std::ofstream& ofs) const;
};