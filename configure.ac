AC_PREREQ([2.59])

AC_INIT([RomanNumeralCalc], [0.2])

AC_CONFIG_SRCDIR([Source/romanNumeralCalc.c])

AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([1.11 -Wall -Wno-extra-portability foreign])

AC_SEARCH_LIBS([floor], [m])
AC_SEARCH_LIBS([timer_create], [rt])
AC_SEARCH_LIBS([pthread_create], [pthread])

AC_PROG_CC
AC_PROG_CC_STDC

AC_PROG_LIBTOOL

AM_PATH_CHECK()

AC_HEADER_STDC

AC_CHECK_HEADERS([stdlib.h])

AC_FUNC_MALLOC

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([Makefile
                 Source/Makefile
                 Tests/Makefile])

AC_OUTPUT
