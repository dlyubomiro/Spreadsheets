#include "Utilities.h"
#include <string.h>
#include <cmath>
#pragma warning (disable:4996)

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

void getDigitsAfterComma(double num, size_t& count)
{
	while (abs(num) >= 0.00001)
	{
		count++;
		num *= 10;
		num -= int(num);
	}
}

char* convertToString(double num)
{
	char doubleInStr[50];
	doubleInStr[0] = '\0';
	size_t counter = 0;

	if (num < 0)
		doubleInStr[counter++] = '-';

	int intPart = (int)num;
	if (intPart == 0)
	{
		doubleInStr[counter++] = '0';
		doubleInStr[counter++] = '.';
	}
	else
	{
		strcat(doubleInStr, convertIntToString(intPart));
		counter += strlen(convertIntToString(intPart));
	}
	doubleInStr[counter++] = '.';
	
	num -= intPart;

	if (abs(num) < 0.00001)
	{
		doubleInStr[--counter] = '\0';
		return doubleInStr;
	}

	doubleInStr[counter++] = '\0';


	size_t count = 0;
	getDigitsAfterComma(num, count);
	num *= pow(10, count);
	strcat(doubleInStr, convertIntToString(num));
	return doubleInStr;
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

