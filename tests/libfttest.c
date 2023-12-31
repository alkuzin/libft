/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:36:05 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 15:48:56 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfttest.h"

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
	expected_result = test_f();
	actual_result = f();
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
		puts("\033[31m Test 1: <FAILED> \033[0m"); 
		failed_tests++;
	}
	else	
		puts("\033[92m Test: 1 (OK) \033[0m\n");
	
	return failed_tests;
}

void tests_result(int total_tests, int failed_tests)
{
	if(failed_tests != 0)
		printf("\033[31m FAILED: %d/%d \033[0m\n", failed_tests, total_tests);
	else
		printf("\033[92m FAILED: %d \033[0m\n", failed_tests);
}

int test_math_func_comb(unsigned long(*test_f)(unsigned int, unsigned int), unsigned long (*test_values)[3], int size, const char *func_name)
{
	int test;
	int failed_tests;
	unsigned long actual_result;
	unsigned long expected_result;
	unsigned long x_value;
	unsigned long y_value;


	test = 0;
	failed_tests = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		x_value = test_values[test][0];
		y_value = test_values[test][1];
		expected_result = test_values[test][2];
		actual_result = test_f(x_value, y_value);
		
		printf("\n Test %d %s(%lu, %lu)\n", test + 1, func_name, x_value, y_value);
		printf(" Expected result: %lu\n", expected_result);
		printf(" Actual result:   %lu\n", actual_result);
		
		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (%lu, %lu) \033[0m\n", test + 1, x_value, y_value); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		
		test++;
	}
	return failed_tests;
}

int test_math_func_factorial(unsigned long(*test_f)(unsigned int), unsigned long (*test_values)[2], int size, const char *func_name)
{
	int test;
	int failed_tests;
	unsigned long actual_result;
	unsigned long expected_result;


	test = 0;
	failed_tests = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		expected_result = test_values[test][1];
		actual_result = test_f(test_values[test][0]);
		
		printf("\n Test %d %s(%lu)\n", test + 1, func_name, test_values[test][0]);
		printf(" Expected result: %lu\n", expected_result);
		printf(" Actual result:   %lu\n", actual_result);
		
		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (%lu) \033[0m\n", test + 1, test_values[test][0]); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		
		test++;
	}
	return failed_tests;
}
