
#include "Table.h"

Table::Table() : count(0), capacity(8)
{
	rows = new Row[capacity];
}
void Table::resize()
{
	Row* new_rows = new Row[capacity * 2];
	for (size_t i = 0; i < count; i++)
	{
		new_rows[i] = rows[i];
	}
	rows = new_rows;
	capacity *= 2;
}

void Table::open(const char* filename)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
		throw std::exception("Cannot open this file!");

	while (!ifs.eof())
	{
		Row currentRow;
		currentRow.readRow(ifs);
		if (count == capacity)
			resize();
		if (currentRow.getCount() > countOfCols)
			countOfCols = currentRow.getCount();
		rows[count++] = currentRow;
	}
}

void Table::save(const char* filename) const
{
	std::ofstream ofs(filename);
	for (size_t i = 0; i < count; i++)
	{
		rows[i].save(ofs);
		if(i<count-1)
			ofs << std::endl;
	}
}

void Table::print() const
{
	for (size_t i = 0; i < count; i++)
	{
		rows[i].printRow();
		for (int j = rows[i].getCount(); j < countOfCols; j++)
		{
			std::cout << std::left << std::setw(10);
			std::cout << " ";
			std::cout << '|';
		}
		std::cout << std::endl;
	}
}

void Table::saveAs() const
{
	std::cout << "Please, enter new filename: ";
	char filename[20];
	std::cin >> filename;

	std::ofstream ofs(filename);
	if (!ofs.is_open())
		throw std::exception("Error!");

	save(filename);
}

void Table::edit()
{
	char newContent[50];
	std::cout << "Please, enter a row and column of the cell you want to edit(first - row, then - column) : ";
	size_t row, col;
	std::cin >> row >> col;
	std::cout << "Please, enter the new content: ";
	std::cin >> newContent;

	rows[row].edit(col, newContent);
}

void close(std::ifstream& ifs)
{
	ifs.close();
}

void close(std::ofstream& ofs)
{
	ofs.close();
}

/*
std::ifstream& openToRead(const char* filename)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
		throw std::exception("Error!");
	return ifs;
}

std::ofstream& openToWrite(const char* filename)
{
	std::ofstream ofs(filename);
	if (!ofs.is_open())
		throw std::exception("Error!");
	return ofs;
}*/