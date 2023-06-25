#include "Row.h"

Row::Row() : capacity(8), count(0)
{
	cells = new Cell * [capacity];
};
void Row::moveFrom(Row&& other)
{
	count = other.count;
	capacity = other.capacity;
	cells = other.cells;
	delete[] other.cells;
}
void Row::copyFrom(const Row& other) {
	count = other.count;
	capacity = other.capacity;
	cells = new Cell * [other.capacity];
	for (size_t i = 0; i < count; i++)
	{
		cells[i] = other.cells[i]->clone();
	}
}
void Row::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete cells[i];
	}
	delete[] cells;
}
Row::Row(const Row& other)
{
	copyFrom(other);
}
/*Row::Row(Row&& other) noexcept
{
	moveFrom(std::move(other));
}*/
Row& Row::operator=(const Row& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
/*
Row& Row::operator=(Row&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}*/
Row::~Row()
{
	free();
}

int getSymbolCount(const char* text, char ch)
{
	int counter = 0;
	while (*text)
	{
		if (*text == ch)
			counter++;
		text++;
	}
	return counter;
}

void Row::readRow(std::ifstream& ifs)
{
	char buff[500];
	ifs.getline(buff, 500);
	std::stringstream ss(buff);
	int count_of_cells = getSymbolCount(buff, ',') + 1;

	for (count = 0; count < count_of_cells; count++)
	{
		char buff[50];
		ss.getline(buff, 50, ',');

		if (count == capacity)
			resize();
		removeSpaces(buff);
		cells[count] = CellsFactory(buff);
	}
	count = count_of_cells;
}

void Row::save(std::ofstream& ofs) const
{
	for (size_t i = 0; i < count; i++)
	{
		cells[i]->save(ofs);
		if (i < count - 1)
			ofs << ",";
	}
	
}
void  Row::printRow() const
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << std::left << std::setw(10);
		cells[i]->print();
		std::cout << '|';
	}
}


double Row::getValueFromCell(size_t i) const
{
	return cells[i]->getValueInDouble();
}

void Row::resize()
{
	Cell** new_cells = new Cell * [capacity *= 2];
	for (size_t i = 0; i < count; i++)
	{
		new_cells[i] = cells[i];
	}
	delete[] cells;
	cells = new_cells;
}

size_t Row::getCount() const
{
	return count;
}

static unsigned int count_spaces(char* value)
{
	unsigned int count = 0;
	while (*value)
	{
		if (*value == ' ')
			count++;

		value++;
	}
	return count;
}

void Row::removeSpaces(char* value)
{
	unsigned int newstrlen = 0, valuelen = strlen(value);

	if (count_spaces(value) > 0)
	{
		char* valueWithoutSpaces = new char[valuelen - count_spaces(value) + 1];
		while (*value)
		{
			if (*value != ' ')
			{
				*valueWithoutSpaces = *value;
				valueWithoutSpaces++;
				newstrlen++;
			}
			value++;
		}

		*valueWithoutSpaces = '\0';
		valueWithoutSpaces -= newstrlen;
		value -= valuelen;
		strcpy(value, valueWithoutSpaces);
		delete[] valueWithoutSpaces;
	}
}

void Row::edit(size_t col,const char* new_content) 
{
	delete cells[col];
	cells[col] = CellsFactory(new_content);
}

//void Row::calculateFormulas(Table& table)
//{
//	
//}