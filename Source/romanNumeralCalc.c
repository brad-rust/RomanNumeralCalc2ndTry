#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "convert.h"
#include "romanNumeralCalc.h"

#define ERROR -1

static bool goodInput(int firstTerm, int secondTerm, int bufferSize, char *returnString);
static void initializeReturnString(char * returnString);

void romanAdd(char *firstNumeral, char *secondNumeral, char *sum, int bufferSz)
{
	initializeReturnString(sum);
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (!goodInput(firstInt, secondInt, bufferSz, sum))
		return;
	if (firstInt + secondInt < 4000)
		convertIntToRomanNumeralString(firstInt + secondInt, sum);
}

void romanSub(char *firstNumeral, char *secondNumeral, char *difference, int bufferSz)
{
	initializeReturnString(difference);
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (!goodInput(firstInt, secondInt, bufferSz, difference))
		return;
	if (firstInt - secondInt > 0)
		convertIntToRomanNumeralString(firstInt - secondInt, difference);
}

bool goodInput(int firstTerm, int secondTerm, int bufferSize, char *returnString)
{
	if (bufferSize < sizeof(char) * 16)
		return false;
	if (firstTerm == ERROR || secondTerm == ERROR)
		return false;
	return true;
}

static void initializeReturnString(char * returnString)
{
	returnString[0] = '\0';
}
