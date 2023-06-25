// project_oop_pract.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include "Table.h"
#include "Utilities.h"

int main()
{
	std::cout << "Welcome to Spreadsheets\n";
	std::cout << "Do you want to open spreadsheet from file? (y - yes/n - no): ";
	char ch;
		std::cin >> ch;

	if (ch == 'y')
	{
		Table t;
		std::cout << "Enter filename: ";
		char filename[50];
		std::cin >> filename;
		t.open(filename);
		t.print();
		std::cout << "Do you want to edit cell? (y - yes/n - no): ";
		char ch;
		std::cin >> ch;
		if (ch == 'y')
		{
			t.edit();
		}
		std::cout << "Do you want to save the spreadsheet in this file or in another one? (t - this/o - other): ";
		char ch2;
		std::cin >> ch2;
		if (ch == 't')
			t.save(filename);
		else
			t.saveAs();
	}
	else
		return 1;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
