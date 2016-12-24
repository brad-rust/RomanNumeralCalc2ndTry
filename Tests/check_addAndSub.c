/*
 * check_addAndSub.c
 *
 *  Created on: Nov 3, 2016
 *      Author: brad
 */
#include <check.h>
#include "check_addAndSub.h"
#include "Source/romanNumeralCalc.h"

START_TEST(test_addRomanNumeralStrings_IV_CMIX)
{
	char *concatNumeralString[16];
	romanAdd("IV", "CMIX", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "CMXIII");
}
END_TEST

START_TEST(test_subRomanNumeralStrings_CXC_X)
{
	char *concatNumeralString[16];
	romanSub("CXC", "X", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "CLXXX");
}
END_TEST

START_TEST(test_addRomanNumeralString_recognizesBadInput_XCC_GONE_TO_MARS)
{
	char concatNumeralString[16];
	romanAdd("XCC", "GONE_TO_MARS", concatNumeralString, sizeof(concatNumeralString));
	ck_assert(concatNumeralString[0] == '\0');
}
END_TEST

START_TEST(test_addRomanNumeralString_recognizesSumGreaterThan_3999)
{
	char concatNumeralString[16];
	romanAdd("MM", "MM", concatNumeralString, sizeof(concatNumeralString));
	ck_assert(concatNumeralString[0] == '\0');
}
END_TEST

START_TEST(test_subRomanNumeralString_recognizesDifferenceLessThan_1)
{
	char concatNumeralString[16];
	romanSub("C", "M", concatNumeralString, sizeof(concatNumeralString));
	ck_assert(concatNumeralString[0] == '\0');
}
END_TEST

START_TEST(test_addRomanNumeralString_dealsWithLargeAddition_MCMXVI_CMXL)
{
	char concatNumeralString[16];
	romanAdd("MCMXVI", "CMXL", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "MMDCCCLVI");
}
END_TEST

START_TEST(test_subRomanNumeralStringRecognizesBadInput_MMCM_CMD)
{
	char concatNumeralString[16];
	romanSub("MMCM", "CMD", concatNumeralString, sizeof(concatNumeralString));
	ck_assert(concatNumeralString[0] == '\0');
}
END_TEST

START_TEST(test_addRomanNumeralStrings_edge_cases)
{
	char concatNumeralString[16];

	romanAdd("MMMCMXCVIII", "I", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "MMMCMXCIX");

	romanAdd("I", "I", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "II");

}
END_TEST

START_TEST(test_subRomanNumeralStrings_edge_cases)
{
	char concatNumeralString[16];

	romanSub("II", "I", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "I");

	romanAdd("MMMCMXCIX", "MMMCMXCVIII", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "I");
}
END_TEST

TCase * addAndSub_tcase(void)
{
	TCase *tc_addAndSub = tcase_create("Core");

	tcase_add_test(tc_addAndSub, test_addRomanNumeralStrings_IV_CMIX);

	tcase_add_test(tc_addAndSub, test_subRomanNumeralStrings_CXC_X);

	tcase_add_test(tc_addAndSub, test_addRomanNumeralString_recognizesBadInput_XCC_GONE_TO_MARS);

	tcase_add_test(tc_addAndSub, test_addRomanNumeralString_recognizesSumGreaterThan_3999);

	tcase_add_test(tc_addAndSub, test_subRomanNumeralString_recognizesDifferenceLessThan_1);

	tcase_add_test(tc_addAndSub, test_addRomanNumeralString_dealsWithLargeAddition_MCMXVI_CMXL);

	tcase_add_test(tc_addAndSub, test_subRomanNumeralStringRecognizesBadInput_MMCM_CMD);

	tcase_add_test(tc_addAndSub, test_addRomanNumeralStrings_edge_cases);

	tcase_add_test(tc_addAndSub, test_subRomanNumeralStrings_edge_cases);

	return tc_addAndSub;
}
