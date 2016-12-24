/*
 * check_romanNumeralCalc.c
 *
 *  Created on: Oct 24, 2016
 *      Author: brad
 */
#include <stdlib.h>
#include "check_convert.h"
#include "check_addAndSub.h"
#include <check.h>

Suite *romanNumeral_suite(void)
{
	Suite *s;
	TCase *tc_convert;
	TCase *tc_addAndSub;

	s = suite_create("RomanNumeral");

	tc_convert = convert_tcase();
	tc_addAndSub = addAndSub_tcase();

	suite_add_tcase(s, tc_convert);
	suite_add_tcase(s, tc_addAndSub);

	return s;
}


int main(void)
{
	int numberOfTestsFailed;
	Suite *s;
	SRunner *sr;

	s = romanNumeral_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	numberOfTestsFailed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (numberOfTestsFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
