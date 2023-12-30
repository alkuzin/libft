/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   test.c                                                                   */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/30 19:09:19 by alkuzin                                  */
/*   Updated: 2023/12/31 00:06:27 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"

void test_ctype_func(int(*test_f)(int), int *test_values, int size, const char *func_name);

int test_math_func_1_arg(double(*test_f)(double), double(*f)(double), double *test_values, int size, const char *func_name);

int test_math_func_no_arg(double(*test_f)(void), double(*f)(void),const char *func_name);

int test_math_func_2_arg(double(*test_f)(double, double), double(*f)(double, double), double (*test_values)[2], int size, const char *func_name);

int main(void)
{
	int size;
	puts("\n\n ================ TEST CTYPE ================\n\n");

	size = 15;
	int test_values_ctype[] = {'a', 'A', 'z', 'Z', '0', '9', '^', '+', '\'', ']', 'X', 'x', 0, 31, 777};	
	
	test_ctype_func(ft_isalnum, test_values_ctype, size, "ft_isalnum");
	test_ctype_func(ft_isalpha, test_values_ctype, size, "ft_isalpha");
	test_ctype_func(ft_isascii, test_values_ctype, size, "ft_isascii");
	test_ctype_func(ft_isdigit, test_values_ctype, size, "ft_isdigit");
	test_ctype_func(ft_isupper, test_values_ctype, size, "ft_isupper");
	test_ctype_func(ft_islower, test_values_ctype, size, "ft_islower");
	test_ctype_func(ft_isprint, test_values_ctype, size, "ft_isprint");
	test_ctype_func(ft_toupper, test_values_ctype, size, "ft_toupper");
	test_ctype_func(ft_tolower, test_values_ctype, size, "ft_tolower");


	puts("\n\n ================ TEST MATH =================\n\n");
	
	
	double test_values_math[] = {2, -13, -14.0001, 64, 65.0000001, 0.001, 1, -1, 0.0001, 1024, -2, 333.333, 997.5, -31, 777};	
	int failed_tests;
	double actual_result;
	double expected_result;

	
	failed_tests = 0;
	failed_tests += test_math_func_1_arg(ft_log, log, test_values_math, size, "ft_log");
	failed_tests += test_math_func_1_arg(ft_exp, exp, test_values_math, size, "ft_exp");
	failed_tests += test_math_func_1_arg(ft_sqrt, sqrt, test_values_math, size, "ft_sqrt");
	failed_tests += test_ft_inf();
	
	double test_values_math_2_arg[15][2] = 
	{
		{0, 0},
		{0, 1},
		{123, 0},
		{0, -1},
		{-1, -1},
		{2, 2},
		{2, 1},
		{2, 16},
		{2, 128},
		{3, 7},
		{0.0001, 0.0001},
		{12, 0.5},
		{12, 2},
		{7, 0.01},
		{2, -13}
	};	
	failed_tests += test_math_func_2_arg(ft_pow, pow, test_values_math_2_arg, size, "ft_pow");

	
	puts("\n >>>>>>>>>>>>>>>> TESTS RESULT <<<<<<<<<<<<<<<<");
	if(failed_tests != 0)
		printf("\033[31m FAILED: %d/%d \033[0m\n", failed_tests, size * failed_tests);
	else
		printf("\033[92m FAILED: %d \033[0m\n", failed_tests, size * failed_tests);
	return 0;
}

void test_ctype_func(int(*test_f)(int), int *test_values, int size, const char *func_name)
{
	int test;
	int result;

	
	printf("\n ------------ Test %s() ------------\n", func_name);
	test = 0;
	while(test < size)
	{
		result = test_f(test_values[test]);
		printf(" Test %02d: %s('%c'):\t% 3d\t%c \n", test + 1, func_name,
				test_values[test], result, result);
		test++;
	}
}


int test_math_func_1_arg(double(*test_f)(double), double(*f)(double), double *test_values, int size, const char *func_name)
{
	int test;
	double actual_result;
	double expected_result;
	int failed_tests;


	printf("\n ------------ Test %s() ------------\n", func_name);
	test = 0;
	failed_tests = 0;
	while(test < size)
	{
		actual_result = test_f(test_values[test]);
		expected_result = f(test_values[test]);
		printf("\n Test %d %s(%lf)\n", test + 1, func_name, test_values[test]);
		printf(" Expected result: %lf\n", expected_result);
		printf(" Actual result:   %lf\n", actual_result);
		
		if(fabs(expected_result - actual_result) > 0.000001)
		{
			printf("\033[31m Test %d: <FAILED> on value (%lf) \033[0m\n", test + 1, test_values[test]); 
		failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		
		test++;
	}
	return failed_tests;
}

int test_math_func_no_arg(double(*test_f)(void), double(*f)(void),const char *func_name)
{
	double actual_result;
	double expected_result;
	int failed_tests;
	

	failed_tests = 0;
	expected_result = __builtin_inf();
	actual_result = ft_inf();
	printf("\n ------------ Test %s ------------\n\n", func_name);
	printf(" Test 1 %s\n", func_name);
	printf(" Expected result: %lf\n", expected_result);
	printf(" Actual result:   %lf\n", actual_result);

	if(fabs(expected_result - actual_result) > 0.000001)
	{
		puts("\033[31m Test 1: <FAILED> on value \033[0m"); 
		failed_tests++;
	}
	else	
		puts("\033[92m Test: 1 (OK) \033[0m\n");
	
	return failed_tests;
}

int test_math_func_2_arg(double(*test_f)(double, double), double(*f)(double, double), double (*test_values)[2], int size, const char *func_name)
{
	int test;
	double actual_result;
	double expected_result;
	int failed_tests;
	double x_value;
	double y_value;


	printf("\n ------------ Test %s() ------------\n", func_name);
	test = 0;
	failed_tests = 0;
	while(test < size)
	{
		x_value = test_values[test][0];
		y_value = test_values[test][1];
		actual_result = test_f(x_value, y_value);
		expected_result = f(x_value, y_value);
		printf("\n Test %d %s(%lf, %lf)\n", test + 1, func_name, x_value, y_value);
		printf(" Expected result: %lf\n", expected_result);
		printf(" Actual result:   %lf\n", actual_result);
		
		if(fabs(expected_result - actual_result) > 0.000001)
		{
			printf("\033[31m Test %d: <FAILED> on value (%lf, %lf) \033[0m\n", test + 1, x_value, y_value); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		
		test++;
	}
	return failed_tests;
}

int test_ft_inf(void)
{
	double actual_result;
	double expected_result;
	int failed_tests;
	

	failed_tests = 0;
	expected_result = __builtin_inf();
	actual_result = ft_inf();
	printf("\n ------------ Test ft_inf() ------------\n");
	puts(" Test 1 ft_inf()");
	printf(" Expected result: %lf\n", expected_result);
	printf(" Actual result:   %lf\n", actual_result);

	if(fabs(expected_result - actual_result) > 0.000001)
	{
		puts("\033[31m Test 1: <FAILED> on value \033[0m"); 
		failed_tests++;
	}
	else	
		puts("\033[92m Test: 1 (OK) \033[0m\n");
	
	return failed_tests;
}
