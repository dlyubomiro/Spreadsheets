#pragma once
#include "Cell.h"
#include "MyString.h"
#include "StringView.h"


class CellOfText : public Cell {
	MyString content;

public:
	CellOfText() = default;
	CellOfText(const char*);
	MyString getData() const;

	Cell* clone() const override;
	void save(std::ofstream& ofs) const override;
	void print() const override;
};

MyString CellOfText::getData() const
{
	return content;
}

static bool isTextValid(const MyString& text)
{
	return text[0] == '"' && text[text.length()-1] == '"';
}

static int containsString(const MyString& text, const MyString& substring)
{
	for (size_t i = 0; i < text.length(); i++)
	{
		if (text.substr(i, substring.length()) == substring)
			return i;
	}
	return -1;
}

static void removeQuotationMarks(MyString& text)
{
	if(!isTextValid(text))
		throw std::logic_error("The text must be enclosed in quotation marks!");
	
	text = text.substr(1,text.length()-2);
}

static void replaceSymbol(MyString& text, const char* torepl, char replwith , size_t ind)
{
	text[ind] = replwith;
}

CellOfText::CellOfText(const char* text)
{
	MyString txt;
	if (strcmp(text, " ") == 0 && strcmp(text, "") == 0)
	{
		txt += text;
	}
	else 
	{
		removeQuotationMarks(txt);
		txt += text;
	}

	int indexQuestionMark = containsString(txt, "\"");
	/*while (indexQuestionMark != -1)
	{
		replaceSymbol(txt, "\"", '"', indexQuestionMark);
		indexQuestionMark = containsString(txt, "\"");
	}*/

	content = txt;
}


/*
void CellOfText::readCell(std::ifstream& ifs) {

	 if (ifs.is_open())
		 throw std::exception("Cannot open the file!");

	 ifs >> content;
}
void CellOfText::writeCell(std::ofstream& ofs){

	 if (ofs.is_open())
		 throw std::exception("Cannot open the file!");

	 ofs << content;
 }*/

void CellOfText::print() const
{
	std::cout << content.c_str();
}

Cell* CellOfText::clone() const
{
	Cell* newCell = new CellOfText(*this);
	return newCell;
}

void CellOfText::save(std::ofstream& ofs) const
{
	ofs << '\"' << content   <<'\"';
}