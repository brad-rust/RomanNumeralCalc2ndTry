#include <string.h>
#include <stdbool.h>
#include "convert.h"

//define all Roman Numeral char values
#define I  1
#define IV 4
#define V  5
#define IX 9
#define X  10
#define XL 40
#define L  50
#define XC 90
#define C  100
#define CD 400
#define D  500
#define CM 900
#define M  1000

#define ERROR -1

int convertRomanNumeralStringToInt(char *numeralString);
static int convertSingleCharToInt(char romanNumeralChar);
static int getNextConvertedValue(char *numeralString, int *i);
static bool getTwoCharacterValues(int *currentVal, int *nextVal, char *numeralString, int i);
static bool goodSubtractionPair(int currentCharValue, int nextCharValue);
static bool badCharValue(int currentVal, int nextVal);
void convertIntToRomanNumeralString(int intToConvert, char *numeralString);
static bool numeralStringHasProperSyntax(char *numeralString, int convertedValue);

const int allNumeralValues[13] = {M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I};
const char *allNumerals[14] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int convertRomanNumeralStringToInt(char *numeralString)
{
	int total = 0, convertedValue = 0;
	int i = strlen(numeralString) - 1;
	for (; i >= 0; i--)
	{
		convertedValue = getNextConvertedValue(numeralString, &i);
		total += convertedValue;
		if ((convertedValue == ERROR) || (total > 3999))
			return ERROR;
	}
	return numeralStringHasProperSyntax(numeralString, total) ? total : ERROR;
 }

int getNextConvertedValue(char *numeralString, int *i)
{
	int currentCharValue = 0, nextCharValue = 0;
	if (!getTwoCharacterValues(&currentCharValue, &nextCharValue, numeralString, *i))
		return currentCharValue;
	if (badCharValue(currentCharValue, nextCharValue))
		return ERROR;
	return getNextCharValOrSubtractionPairVal(currentCharValue, nextCharValue, i);
}

bool getTwoCharacterValues(int *currentVal, int *nextVal, char *numeralString, int i)
{
	*currentVal = convertSingleCharToInt(numeralString[i]);
	if (i == 0)
		return false;
	*nextVal = convertSingleCharToInt(numeralString[i - 1]);
	return true;
}

bool badCharValue(int currentVal, int nextVal)
{
	if (currentVal == ERROR || nextVal == ERROR)
		return true;
	return false;
}

int getNextCharValOrSubtractionPairVal(int currentCharValue, int nextCharValue, int *i)
{
	if (currentCharValue > nextCharValue)
	{
		if (!goodSubtractionPair(currentCharValue, nextCharValue))
			return ERROR;
		*i -= 1;
		return currentCharValue - nextCharValue;
	}
	return currentCharValue;
}

bool goodSubtractionPair(int currentCharValue, int nextCharValue)
{
	if (nextCharValue == I || nextCharValue == X || nextCharValue == C)
		{
			int firstDividedBySecond = currentCharValue / nextCharValue;
			if (firstDividedBySecond == 5 || firstDividedBySecond == 10)
				return true;
		}
	return false;
}

int convertSingleCharToInt(char romanNumeralChar)
{
	switch (romanNumeralChar)
	{
		case 'I' :
			return I;
		case 'V' :
			return V;
		case 'X' :
			return X;
		case 'L' :
			return L;
		case 'C' :
			return C;
		case 'D' :
			return D;
		case 'M' :
			return M;
	}
	return ERROR;
}

bool numeralStringHasProperSyntax(char *numeralString, int convertedValue)
{
	char properlyConvertedString[16] = "";
	convertIntToRomanNumeralString(convertedValue, &properlyConvertedString);
	return strcmp(properlyConvertedString, numeralString) == 0 ? true : false;
}

void convertIntToRomanNumeralString(int intToConvert, char *numeralString)
{
	int index = 0;
	while (intToConvert > 0)
	{
		while (intToConvert >= allNumeralValues[index])
		{
			strcat(numeralString, allNumerals[index]);
			intToConvert -= allNumeralValues[index];
		}
		index++;
	}
}
