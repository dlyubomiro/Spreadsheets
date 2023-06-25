#include "CellOfText.h"

MyString CellOfText::getData() const
{
	return content;
}

static bool isTextValid(const MyString& text)
{
	return text[0] == '"' && text[text.length() - 1] == '"';
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
	if (!isTextValid(text))
		throw std::logic_error("The text must be enclosed in quotation marks!");

	text = text.substr(1, text.length() - 2);
}

static void replaceSymbol(MyString& text, const char* torepl, char replwith, size_t ind)
{
	text[ind] = replwith;
}

CellOfText::CellOfText(const char* text)
{
	MyString txt;
	if (strcmp(text, " ") == 0 || strcmp(text, "") == 0)
	{
		txt += MyString(text);
	}
	else
	{
		txt += MyString(text);
		removeQuotationMarks(txt);
	}

	int indexQuestionMark = containsString(txt, "\"");
	while (indexQuestionMark != -1)
	{
		replaceSymbol(txt, "\"", '\"', indexQuestionMark);
		indexQuestionMark = containsString(txt, "\"");
	}

	content = txt;
}

void CellOfText::print()
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
	ofs << '\"' << content << '\"';
}

double CellOfText::getValueInDouble() const
{
	if (containtsOnlyNumbers(content.c_str()) == 0 || containtsOnlyNumbers(content.c_str()) == 1)
		return convertStringToDouble(content.c_str());

	return 0;
}


