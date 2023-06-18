#pragma once
#include "Row.h"

class Table{
	Row* rows;
	size_t count;
	size_t capacity;
	size_t countOfCols = 0;

	void resize();
public:
	Table();
	void open(std::ifstream& ifs);
	void save(std::ofstream& ofs) const;
	void saveAs() const;
	void edit();
	void print() const;
	//void openToRead(const char* filename) const;
	//void openToWrite(const char* filename) const;
	void close(std::ifstream& ifs)const;
	void close(std::ofstream& ofs)const;
};