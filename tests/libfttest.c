/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:36:05 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/01 12:35:05 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfttest.h"

int test_ctype_func(int(*test_f)(int), int *test_values, int *expected_values, int size, const char *func_name)
{
	int test;
	int failed_tests;
	int actual_result;
	int expected_result;

	
	test = 0;
	failed_tests = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		actual_result = test_f(test_values[test]);
		expected_result = expected_values[test];
		printf("\n Test %d %s('%c')\n", test + 1, func_name, test_values[test]);
		printf(" Expected result: %d\n", expected_result);
		printf(" Actual result:   %d\n", actual_result);
		
		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (%d) \033[0m\n", test + 1, test_values[test]); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	return failed_tests;	
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
		printf("\033[92m FAILED: %d/%d \033[0m\n", failed_tests, total_tests);
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


static void print_buffer(void *buffer, int size)
{
	unsigned char *buf;
	unsigned char cc;
	unsigned char to_print;
    int i;


    buf = (unsigned char *)buffer;
	putchar('\'');
	i = 0;
	while (i < size)
	{
		cc = (unsigned char)buf[i];
		
		if (cc == '\0')
		{
			putchar('0');
			i++;
			continue;
		}

		to_print = ft_isalnum(cc)? cc : '.';

		putchar(to_print);
		i++;
	}
	putchar('\'');
	putchar('\n');
}

int test_ft_memset(int (*test_values)[2], int size)
{
	int test;
	int failed_tests;
	unsigned char expected_result[32 + 1];
	unsigned char   actual_result[32 + 1];
	int value;
	size_t s;


	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_memset() ------------");
	while (test < size)
	{
		memset(expected_result, '.', sizeof(expected_result));
		memset(actual_result,   '.', sizeof(  actual_result));

		value     = test_values[test][0];
		s = (size_t)test_values[test][1];

		   memset(expected_result, value, s);
		ft_memset(actual_result,   value, s);
		expected_result[32] = '\0';
		actual_result[32]   = '\0';

		printf("\n Test %d \n", test + 1);
		printf(" Expected result |    memset(buffer[32], %d, %lu): \t '%-32s'\n", value, s, expected_result);
		printf(" Actual result   | ft_memset(buffer[32], %d, %lu): \t '%-32s'\n", value, s, actual_result);

		if((memcmp(expected_result, actual_result, 32) != 0))
		{
			printf("\033[31m Test %d: <FAILED> on value (%d, %lu) \033[0m\n", test + 1, value, s); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}


int test_ft_bzero(int *test_values, int size)
{
	int test;
	int failed_tests;
	unsigned char expected_result[32 + 1];
	unsigned char   actual_result[32 + 1];
	size_t s;


	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_bzero() ------------");
	while (test < size)
	{
		memset(expected_result, 0xff, sizeof(expected_result));
		memset(actual_result,   0xff, sizeof(  actual_result));

		s = (size_t)test_values[test];
		memset(expected_result, '\0', s);
		ft_bzero(actual_result, s);
		expected_result[32] = '\0';
		actual_result[32]   = '\0';

		printf("\n Test %d \n", test + 1);
		printf(" Expected result |    bzero(buffer[32], %lu): \t ", s);
		print_buffer(expected_result, 32);
		printf(" Actual result   | ft_bzero(buffer[32], %lu): \t ", s);
		print_buffer(actual_result, 32);

		if((memcmp(expected_result, actual_result, 32) != 0))
		{
			printf("\033[31m Test %d: <FAILED> on value (%lu) \033[0m\n", test + 1, s); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test %d: (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}


int test_ft_memchr(int (*test_values)[2], int size)
{
	int test;
	int failed_tests;
	
	unsigned char *expected_result;
	unsigned char   *actual_result;
	int value;
	size_t s;


	unsigned char buffer[32 + 1] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	buffer[32] = '\0';
	puts("\n ------------ Test ft_memchr() ------------");
	while (test < size)
	{
		value     = test_values[test][0];
		s = (size_t)test_values[test][1];

		expected_result  = memchr(buffer, value, s);
		actual_result = ft_memchr(buffer, value, s);

		printf("\n Test %d \n", test + 1);

		if (expected_result == NULL)
			printf(" Expected result |    memchr(buffer[32], %d, %lu): \t '(null)'\n", value, s);
		else
			printf(" Expected result |    memchr(buffer[32], %d, %lu): \t '%-32s'\n", value, s, expected_result);
		
		if (actual_result == NULL)
			printf(" Actual result   | ft_memchr(buffer[32], %d, %lu): \t '(null)'\n", value, s);
		else
			printf(" Actual result   | ft_memchr(buffer[32], %d, %lu): \t '%-32s'\n", value, s, actual_result);

		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (%d, %lu) \033[0m\n", test + 1, value, s); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}


int test_ft_memcpy(int *test_values, int size)
{
	int test;
	int failed_tests;
	unsigned char expected_result[32 + 1];
	unsigned char   actual_result[32 + 1];
	size_t s;

	const unsigned char buffer[32] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_memcpy() ------------");
	while (test < size)
	{
		memset(expected_result, 0, 32);
		memset(actual_result,   0, 32);

		s = (size_t)test_values[test];

		   memcpy(expected_result, buffer, s);
		ft_memcpy(actual_result,   buffer, s);
		expected_result[32] = '\0';
		actual_result[32]   = '\0';

		printf("\n Test %d \n", test + 1);
		printf(" Expected result |    memcpy(dest[32], src[32], %lu): \t '%-32s'\n", s, expected_result);
		printf(" Actual result   | ft_memcpy(dest[32], src[32], %lu): \t '%-32s'\n", s, actual_result);

		if((memcmp(expected_result, actual_result, 32) != 0))
		{
			printf("\033[31m Test %d: <FAILED> on value (%lu) \033[0m\n", test + 1, s); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}

int test_ft_memccpy(int (*test_values)[2], int size)
{
	int test;
	int failed_tests;
	unsigned char actual_result[32 + 1];
	unsigned char *actual_result_p;
	int value;
	size_t s;


	unsigned char buffer[32 + 1] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_memccpy() ------------");
	while (test < size)
	{
		memset(actual_result,   0, 32);

		value     = test_values[test][0];
		s = (size_t)test_values[test][1];

		actual_result_p = ft_memccpy(actual_result, buffer, value, s);
		printf("\n Test %d \n", test + 1);

		if (actual_result_p == NULL)
			printf(" Actual result | ft_memccpy(buffer[32], '%c', %lu): \t '(null)'\n", value, s);
		else
			printf(" Actual result | ft_memccpy(buffer[32], '%c', %lu): \t '%-32s'\n", value, s, actual_result);

		test++;
	}
	
	return failed_tests;
}

int test_ft_memmove(int *test_values, int size)
{
	int test;
	int failed_tests;
	unsigned char expected_result[32 + 1];
	unsigned char   actual_result[32 + 1];
	size_t s;

	const unsigned char buffer[32] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_memmove() ------------");
	while (test < size)
	{
		memset(expected_result, 0, 32);
		memset(actual_result,   0, 32);

		s = (size_t)test_values[test];

		   memmove(expected_result, buffer, s);
		ft_memmove(actual_result,   buffer, s);
		expected_result[32] = '\0';
		actual_result[32]   = '\0';

		printf("\n Test %d \n", test + 1);
		printf(" Expected result |    memmove(dest[32], src[32], %lu): \t '%-32s'\n", s, expected_result);
		printf(" Actual result   | ft_memmove(dest[32], src[32], %lu): \t '%-32s'\n", s, actual_result);

		if((memcmp(expected_result, actual_result, 32) != 0))
		{
			printf("\033[31m Test %d: <FAILED> on value (%lu) \033[0m\n", test + 1, s); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}

int test_ft_memcmp(int *test_values, int size)
{
	int test;
	int failed_tests;

	int expected_result;
	int   actual_result;

	unsigned char buffer1[32 + 1];
	unsigned char buffer2[32 + 1];
	size_t s;

	const unsigned char buffer[32] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_memcmp() ------------");
	while (test < size)
	{
		memset(buffer1, 0, 32);
		memset(buffer1, 0, 32);
		buffer1[32] = '\0';
		buffer2[32] = '\0';

		s = (size_t)test_values[test];

		   memmove(buffer1, buffer, s);
		ft_memmove(buffer2, buffer, s);

		expected_result =    memcmp(buffer1, buffer2, s);
		actual_result   = ft_memcmp(buffer1, buffer2, s);

		printf("\n Test %d \n", test + 1);
		printf(" Buffer 1:  \t '%-32s'\n",   buffer1);
		printf(" Buffer 2:  \t '%-32s'\n\n", buffer2);

		printf(" Expected result |    memcmp(buffer1[32], buffer2[32], %lu): \t (%d)\n", s, expected_result);
		printf(" Actual result   | ft_memcmp(buffer1[32], buffer2[32], %lu): \t (%d)\n", s, actual_result);

		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (%lu) \033[0m\n", test + 1, s); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}
