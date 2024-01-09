/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:36:05 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/09 14:00:48 by alkuzin          ###   ########.fr       */
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
	puts("\n ------------ Test ft_memset() ------------\n");
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
	puts("\n ------------ Test ft_bzero() ------------\n");
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
	puts("\n ------------ Test ft_memchr() ------------\n");
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
		memset(buffer2, 0, 32);
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





void test_stdio_ft_putchar(void (*f)(char), int *test_values, int size, const char *func_name)
{
	int test;
	int value;
	char buffer[128];
	

	test = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		value = test_values[test];
		
		snprintf(buffer, 128, "\n Test %d %s(%#02x)\n Actual result: \t\'", test + 1, func_name, value);
		ft_putstr(buffer);
		f(value);
		putchar('\'');
		putchar('\n');
		printf("%s", " Expected result: \t\'");
		putchar(value);
		putchar('\'');
		putchar('\n');
		
		test++;
	}
}

void test_stdio_ft_putchar_fd(void (*f)(char, int), int *test_values, int size, const char *func_name)
{
	int test;
	int value;
	char buffer[128];
	

	test = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		value = test_values[test];
		
		snprintf(buffer, 128, "\n Test %d %s(%#02x, 1)\n Actual result: \t\'", test + 1, func_name, value);
		ft_putstr(buffer);
		f(value, 1);
		putchar('\'');
		putchar('\n');
		printf("%s", " Expected result: \t\'");
		putchar(value);
		putchar('\'');
		putchar('\n');
		
		test++;
	}
}

void test_stdio_ft_putstr(void (*f)(char *), char *(*test_values)[2], int size, const char *func_name)
{
	int test;
	char argument[32];
	char value[32];
	char buffer[128];
	

	test = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		strncpy(argument, test_values[test][0], 32);
		strncpy(value,    test_values[test][1], 32);
		
		snprintf(buffer, 128, "\n Test %d %s('%s')\n Actual result: \t\'", test + 1, func_name, argument);
		ft_putstr(buffer);
		f(value);
		putchar('\'');
		putchar('\n');
		printf("%s", " Expected result: \t");
		printf("'%s'\n", value);
		
		test++;
	}
}

void test_stdio_ft_putstr_fd(void (*f)(char *, int), char *(*test_values)[2], int size, const char *func_name)
{
	int test;
	char argument[32];
	char value[32];
	char buffer[128];
	

	test = 0;
	printf("\n ------------ Test %s() ------------\n", func_name);
	while(test < size)
	{
		strncpy(argument, test_values[test][0], 32);
		strncpy(value,    test_values[test][1], 32);
		
		snprintf(buffer, 128, "\n Test %d %s('%s', 1)\n Actual result: \t\'", test + 1, func_name, argument);
		ft_putstr(buffer);
		f(value, 1);
		putchar('\'');
		putchar('\n');
		printf("%s", " Expected result: \t");
		printf("'%s'\n", value);
		
		test++;
	}
}

void test_stdio_ft_putnbr_fd(int *test_values, int size)
{
	int test;
	int value;
	char buffer[128];
	

	test = 0;
	puts("\n ------------ Test ft_putnbr_fd() ------------\n");
	while(test < size)
	{
		value = test_values[test];
		snprintf(buffer, 128, "\n Test %d ft_putnbr_fd(%d, 1)\n Actual result: \t\'", test + 1, value);

		ft_putstr(buffer);
		ft_putnbr_fd(value, 1);
		putchar('\'');
		putchar('\n');
		
		printf("%s", " Expected result: \t");
		printf("'%d'\n", value);
		
		test++;
	}
}


int test_stdlib_ft_atoi(char *(*test_values), int size)
{
	int test;
	int failed_tests;
	char value[32];
	int expected_result;
	int   actual_result;
	

	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_atoi() ------------\n");
	while(test < size)
	{
		strncpy(value, test_values[test], 32);

		expected_result  = atoi(value);
		actual_result = ft_atoi(value);
		
		printf(" Expected result:  %d\n", expected_result);
		printf(" Actual result:    %d\n",   actual_result);

		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (\"%s\") \033[0m\n", test + 1, value); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		
		test++;
	}

	return failed_tests;
}

void print_int_array(int *arr, int size)
{
	int i;

	if (arr == NULL)
	{
		printf("(null)\n");
		return;
	}

	putchar('{');
	putchar(' ');
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		if (i != size - 1)
		{
			putchar(',');
			putchar(' ');
		}

		i++;
	}
	putchar('}');
	putchar('\n');
}

int test_stdlib_ft_range(int (*test_values)[2], int size)
{
	int test;
	int failed_tests;
	int   *actual_result;
	int min, max;
	

	test = 0;
	failed_tests = 0;
	
	puts("\n ------------ Test ft_range() ------------\n");
	while(test < size)
	{
		min = test_values[test][0];
		max = test_values[test][1];
		actual_result = ft_range(min, max);

		printf(" Test %d ft_range(%d, %d)\n", test, min, max);
		if(actual_result)
		{
			printf("%s", " Actual result: ");
			print_int_array(actual_result, abs(max) - abs(min));
			putchar('\n');
		}
		else
			printf("%s\n\n", " Actual result: (null)");
		
		free(actual_result);
		test++;
	}

	return failed_tests;
}

int test_stdlib_ft_calloc(size_t *test_values, int *test_sizes, int size)
{
	int test;
	int failed_tests;
	unsigned char *expected_result;
	unsigned char   *actual_result;
	size_t s;
	int sz;
	size_t final_size;

	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_calloc() ------------\n");
	while(test < size)
	{
		s = test_values[test];
		sz = test_sizes[test];
		expected_result  = calloc(s, sz);
		actual_result = ft_calloc(s, sz);

		final_size = s * sz;

		if (expected_result && actual_result)
		{
			memset(expected_result, '.', final_size);
			memset(actual_result,   '.', final_size);
		}

		printf(" Test %d ft_calloc(%lu, %d)\n", test, s, sz);

		if(expected_result)
		{
			printf("%s", " Expected result: \t");
			print_buffer(expected_result, final_size);
		}
		else
			puts(" Expected result: (null)");

		if(actual_result)
		{
			printf("%s", " Actual result: \t");
			print_buffer(actual_result,	final_size);
			printf(" Final size: %lu\n", final_size);
		}
		else
			puts(" Actual result:   (null)");
		putchar('\n');

		if(!(expected_result) && !(actual_result))
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		else
		{
			if((memcmp(expected_result, actual_result, final_size) != 0))
			{
				printf("\033[31m Test %d: <FAILED> on value (%lu, %d) \033[0m\n", test + 1, s, sz); 
				failed_tests++;
			}
			else	
				printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		}
		
		free(expected_result);
		free(actual_result);
		test++;
	}

	return failed_tests;
}



int test_ft_strlen(char **test_values, int size)
{
	int test;
	int failed_tests;
	int actual_result;
	int expected_result;
	char value[64];

	
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_strlen() ------------\n");
	while(test < size)
	{
		strncpy(value, test_values[test], 64);
		actual_result = ft_strlen(value);
		expected_result = strlen(value);

		printf("\n Test %d ft_strlen('%s')\n", test + 1, value);
		printf(" Expected result: %d\n", expected_result);
		printf(" Actual result:   %d\n", actual_result);
		
		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value ('%s') \033[0m\n", test + 1, value); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	return failed_tests;	
}

int test_ft_strlcpy(size_t *test_values, int size)
{
	int test;
	int failed_tests;
	char   actual_result[32 + 1];
	size_t s;

	const char buffer[32] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_strlcpy() ------------\n");
	while (test < size)
	{
		memset(actual_result,   0, 32);

		s = (size_t)test_values[test];

		ft_strlcpy(actual_result,   buffer, s);
		actual_result[32]   = '\0';

		printf("\n Test %d \n", test + 1);
		printf(" Actual result   | ft_strlcpy(dest[32], src[32], %lu): \t '%-32s'\n\n", s, actual_result);

		test++;
	}
	
	return failed_tests;
}

int test_ft_strlcat(size_t *test_values, char **test_strings, int size)
{
	int test;
	int failed_tests;
	char   actual_result[96 + 1];
	size_t s;
	char value[96];

	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_strlcat() ------------\n");
	while (test < size)
	{
		s = (size_t)test_values[test];

		printf("\n Test %d \n", test + 1);

		memset(actual_result, 0, 96);
		strncpy(actual_result,   "String + ", 96);

		if (test_strings[test])
		{
			strncpy(value, test_strings[test], 96);
			ft_strlcat(actual_result, value, s);
		}
		
		printf(" Actual result   | ft_strlcat(dest[96], src[96], %lu): \t '%s'\n\n", s, actual_result);
		test++;
	}
	
	return failed_tests;
}

int test_ft_strchr(char *(*test_f)(const char *, int), char *(*f)(const char *, int), int *test_values, int size, char *func_name)
{
	int test;
	int failed_tests;
	char *expected_result;
	char   *actual_result;
	int value;
	char buffer[32 + 1] = "Test^string^*2024_qwerty*fd";


	test = 0;
	failed_tests = 0;
	buffer[32] = '\0';
	printf("\n ------------ Test %s() ------------\n\n", func_name);
	while (test < size)
	{
		value = test_values[test];

		expected_result  = f(buffer, value);
		actual_result = test_f(buffer, value);

		printf("\n Test %d \n", test + 1);

		if (expected_result == NULL)
			printf(" Expected result |       %s(buffer[32], '%c'): \t '(null)'\n", func_name, value);
		else
			printf(" Expected result |       %s(buffer[32], '%c'): \t '%-32s'\n", func_name, value, expected_result);
		
		if (actual_result == NULL)
			printf(" Actual result   |    ft_%s(buffer[32], '%c'): \t '(null)'\n", func_name, value);
		else
			printf(" Actual result   |    ft_%s(buffer[32], '%c'): \t '%-32s'\n", func_name, value, actual_result);

		if(expected_result != actual_result)
		{
			printf("\033[31m Test %d: <FAILED> on value (%d) \033[0m\n", test + 1, value); 
			failed_tests++;
		}
		else	
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);

		test++;
	}
	
	return failed_tests;
}

int test_ft_strnstr(size_t *test_values, char **test_strings, int size)
{
	int test;
	int failed_tests;
	char *actual_result;
	char value[32 + 1];
	char buffer[32 + 1] = "Test^string^*2024_qwerty*fd";
	size_t s;


	test = 0;
	failed_tests = 0;
	buffer[32] = '\0';
	printf("\n ------------ Test ft_strnstr() ------------\n");
	while (test < size)
	{
		printf("\n Test %d \n", test + 1);

		s = test_values[test];
		memset(value, 0, 32);
		if (test_strings[test])
			strncpy(value, test_strings[test], 32);
		else
			actual_result = NULL;
		
		actual_result = ft_strnstr(buffer, value, s);

		if (actual_result == NULL)
			printf(" Actual result   |    ft_strnstr(buffer[32], '%s', '%lu'): \t '(null)'\n", value, s);
		else
			printf(" Actual result   |    ft_strnstr(buffer[32], '%s', '%lu'): \t '%-32s'\n", value, s, actual_result);

		test++;
	}
	
	return failed_tests;
}

int test_ft_strncmp(int *test_values, int size)
{
	int test;
	int failed_tests;

	int expected_result;
	int   actual_result;

	char buffer1[32 + 1];
	char buffer2[32 + 1];
	size_t s;

	const char buffer[32] = "Test^string^*2024_qwerty*fd";
	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_strncmp() ------------");
	while (test < size)
	{
		printf("\n Test %d \n", test + 1);

		s = (size_t)test_values[test];
		memset(buffer1, 0, 32);
		memset(buffer2, 0, 32);
		strncpy(buffer1, buffer, s);
		strncpy(buffer2, buffer, s);
		buffer1[32] = '\0';
		buffer2[32] = '\0';

		printf(" Buffer 1:  \t '%-32s'\n",   buffer1);
		printf(" Buffer 2:  \t '%-32s'\n\n", buffer2);

		expected_result =    strncmp(buffer1, buffer2, s);
		actual_result   = ft_strncmp(buffer1, buffer2, s);

		printf(" Expected result |    strncmp(buffer1[32], buffer2[32], %lu): \t (%d)\n", s, expected_result);
		printf(" Actual result   | ft_strncmp(buffer1[32], buffer2[32], %lu): \t (%d)\n", s, actual_result);

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

void print_str_array(char **arr);

void print_str_array(char **arr)
{
	int i;


	if (arr == NULL)
	{
		printf("(null)\n");
		return;
	}

	putchar('{');
	putchar(' ');
	i = 0;
	while (arr[i])
	{
		printf("\"%s\" ", arr[i]);
		if (arr[i + 1])
		{
			putchar(',');
			putchar(' ');
		}

		i++;
	}
	putchar('}');
	putchar('\n');
}

int test_ft_split(char **test_charsets, char **test_strings, int size)
{
	int test;
	int failed_tests;
	char **actual_result;
	char charset[32 + 1];
	char string[32 + 1];
	int i;


	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_split() ------------\n");
	while(test < size)
	{

		printf("\n\n Test %d", test + 1);

		if (!(test_charsets[test] && test_strings[test]))
		{
			puts("\n Actual result: (null)\n");
			test++;
			continue;
		}
		
		memset(charset, 0, 32);
		memset(string , 0, 32);
		strncpy(charset, test_charsets[test], 32);
		strncpy(string ,  test_strings[test], 32);
		charset[32] = '\0';

		printf(" ft_split(\"%s\", \"%s\")\n", string, charset);
		actual_result = ft_split(string, charset);

		puts("\n Actual result: ");
		print_str_array(actual_result);

		i = 0;
		while(actual_result[i])
		{
			free(actual_result[i]);
			i++;
		}
		
		free(actual_result);
		putchar('\n');
		test++;
	}

	return failed_tests;
}


int test_ft_strdup(char **test_strings, int size)
{
	int test;
	int failed_tests;
	char *expected_result;
	char   *actual_result;
	char string[32 + 1];


	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_strdup() ------------\n");
	while(test < size)
	{
		printf("\n\n Test %d", test + 1);

		if (!test_strings[test])
		{
			puts(" ft_strdup(NULL)\n");
			puts("\n Expected result: (null)");
			puts(" Actual result:   (null)\n");
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
			test++;
			continue;
		}
		
		memset(string , 0, 32);
		strncpy(string ,  test_strings[test], 32);
		string[32] = '\0';

		expected_result  = strdup(string);
		actual_result = ft_strdup(string);

		printf(" ft_strdup(\"%s\")\n\n", string);

		if(expected_result)
			printf(" Expected result: \"%s\" \t\n", expected_result);
		else
			puts("\n Expected result: (null)");

		if(actual_result)
			printf(" Actual result:   \"%s\" \t\n", actual_result);
		else
			puts("\n Actual result:   (null)");
		putchar('\n');

		if(!(expected_result) && !(actual_result))
			printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		else
		{
			if((strncmp(expected_result, actual_result, strlen(string)) != 0))
			{
				printf("\033[31m Test %d: <FAILED> on value (\"%s\") \033[0m\n", test + 1, string); 
				failed_tests++;
			}
			else	
				printf("\033[92m Test: %d (OK) \033[0m\n", test + 1);
		}
		
		free(expected_result);
		free(actual_result);
		test++;
	}

	return failed_tests;
}

int test_ft_strjoin(char **test_charsets, int size)
{
	int test;
	int failed_tests;
	char *actual_result;
	char charset[32 + 1];
	char *strings[] = {"Example", "of", "usage", "of", "Strjoin", "function"};


	test = 0;
	failed_tests = 0;
	puts("\n ------------ Test ft_strjoin() ------------\n");
	while(test < size)
	{
		printf("\n\n Test %d", test + 1);

		if (!test_charsets[test])
		{
			puts("\n\n Actual result: (null)\n");
			test++;
			continue;
		}
		
		memset(charset, 0, 32);
		strncpy(charset, test_charsets[test], 32);
		charset[32] = '\0';

		printf(" ft_strjoin(6, strings, \"%s\")\n", charset);
		puts(" Strings: {\"Example\", \"of\", \"usage\", \"of\", \"Strjoin\", \"function\"}");
		
		actual_result = ft_strjoin(6, strings, charset);

		if (!actual_result)
		{
			puts("\n\n Actual result: (null)\n");
			test++;
			continue;
		}

		printf("\n Actual result: \"%s\"\n", actual_result);

		free(actual_result);
		putchar('\n');
		test++;
	}

	return failed_tests;
}

int test_ft_substr(size_t (*test_values)[2], int size)
{
	int test;
	int failed_tests;
	char *actual_result;
	size_t value;
	char buffer[32 + 1] = "Test^string^*2024_qwerty*fd";
	size_t len;


	test = 0;
	failed_tests = 0;
	buffer[32] = '\0';
	printf("\n ------------ Test ft_substr() ------------\n");
	while (test < size)
	{
		printf("\n Test %d \n", test + 1);

		value = test_values[test][0];
		len   = test_values[test][1];

		actual_result = ft_substr(buffer, value, len);

		if (actual_result == NULL)
			puts("\n Actual result\t '(null)'\n");
		else
		{
			printf(" ft_substr(\"%s\", '%lu', '%lu'):\n", buffer, value, len);
			printf("\n Actual result: \"%s\"\n\n", actual_result);
		}
		
		free(actual_result);
		test++;
	}
	
	return failed_tests;
}

int test_ft_strtrim(char *(*test_values)[2], int size)
{
	int test;
	int failed_tests;
	char string[32 + 1];
	char    set[32 + 1];
	char *actual_result;


	test = 0;
	failed_tests = 0;
	printf("\n ------------ Test ft_strtrim() ------------\n");
	while (test < size)
	{
		printf("\n Test %d ", test + 1);

		if (!test_values[test][0] || !test_values[test][1])
			actual_result = ft_strtrim(test_values[test][0], test_values[test][1]);
		else
		{
			strncpy(string, test_values[test][0], 32);
			strncpy(set   , test_values[test][1], 32);
			string[32] = '\0';
			set[32] = '\0';

			actual_result = ft_strtrim(string, set);
		}
		
		if (actual_result == NULL)
			puts("\n Actual result\t '(null)'\n");
		else
		{
			printf(" ft_substr(\"%s\", \"%s\"):\n", string, set);
			printf("\n Actual result: \"%s\"\n\n", actual_result);
		}
		
		free(actual_result);
		test++;
	}
	
	return failed_tests;
}

int test_ft_itoa(int *test_values, int size)
{
	int test;
	int failed_tests;
	char *actual_result;
	int value;
	

	test = 0;
	failed_tests = 0;
	printf("\n ------------ Test ft_itoa() ------------\n");
	while (test < size)
	{
		printf("\n Test %d ", test + 1);

		value = test_values[test];
		actual_result = ft_itoa(value);
		
		if (!actual_result)
			puts("\n Actual result\t '(null)'\n");
		else
		{
			printf(" ft_itoa(%d):\n", value);
			printf("\n Actual result: \"%s\"\n\n", actual_result);
		}
		
		free(actual_result);
		test++;
	}
	
	return failed_tests;
}