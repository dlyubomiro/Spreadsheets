#include "Utilities.h"
#include <string.h>

int containtsOnlyNumbers(const char* text)
{
	if (*text != '-' && *text != '+' && (*text < '0' || *text > '9'))
		return -1;

	text++;
	while (*text)
	{
		if (*text < '0' || *text > '9')
		{
			if (*text != '.')
				return -1;
			return 1;
		}
		text++;
	}
	return 0;
}

size_t getDigitsCount(unsigned int a)
{
	size_t count = 0;
	if (a == 0)
		return 1;
	while (a > 0)
	{
		count++;
		a /= 10;
	}
	return count;
}

const char* convertIntToString(int a)
{
	char* num;
	size_t strCounter = 0;

	if (a == 0)
	{
		num = new char[2];
		num[strCounter++] = '0';
		num[strCounter] = '\0';
		return num;
	}

	if (a < 0)
	{
		num = new char[getDigitsCount(a *= (-1)) + 2];
		num[strCounter++] = '-';
		strCounter = getDigitsCount(a) + 1;
	}
	else
	{
		num = new char[getDigitsCount(a) + 1];
		strCounter = getDigitsCount(a);
	}

	num[strCounter--] = '\0';

	for (; a > 0; strCounter--)
	{
		unsigned int lastDigit = a % 10;
		num[strCounter] = lastDigit + '0';
		a /= 10;
	}

	return num;
}

size_t getDigitsCountOfDouble(double num)
{
	int counter = 0;

	if (num < 0)
	{
		counter++;
		num *= (-1);
	}

	for (; num != int(num); counter++)
		num *= 10;

	counter++; // for ','

	if (num == 0)
		return ++counter;

	while (num > 0)
	{
		counter++;
		num /= 10;
	}

	return counter;
}

char* convertToString(double num)
{
	char* doubleInStr = new char[getDigitsCountOfDouble(num) + 1];

	if (num < 0)
		doubleInStr[0] = '-';
	return doubleInStr; //negotovo
}

double convertStringToDouble(const char* number)
{
	double res = 0;
	int mult = 1;
	if (*number == '-')
	{
		mult = -1;
		number++;
	}

	if (*number == '+')
	{
		number++;
	}

	while (*number!='.' && *number)
	{
		(res *= 10) += *number - '0';
		number++;
	}
	
	if(*number == '\0')
		return res *= mult;

	number++;
	double fractionalPart = 0.1;
	while (*number)
	{
		res +=( * number - '0')* fractionalPart;
		fractionalPart *= 0.1;
		number++;
	}
	return res *= mult;
}

