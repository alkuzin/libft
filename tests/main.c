/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:09:00 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/03 23:49:18 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libfttest.h"

/* Test libft ctype/ functions */
void test_ctype(int tests, int *failed_tests, int *total_tests);

/* Test libft math/ functions */
void test_math(int tests, int *failed_tests, int *total_tests);

/* Test libft memory/ functions */
void test_memory(int tests, int *failed_tests, int *total_tests);

/* Test libft stdio/ functions */
void test_stdio(int tests, int *total_tests);

/* Test libft stdlib/ functions */
void test_stdlib(int tests, int *failed_tests, int *total_tests);

/* Test libft string/ functions */
void test_string(int tests, int *failed_tests, int *total_tests);


int main(void)
{
	int tests;
	int total_tests;
	int failed_tests;
	

	tests = 15;
	total_tests = 0;
	failed_tests = 0;
	
	puts("\n\n =============== TEST CTYPE =================\n\n");
	test_ctype(tests, &failed_tests, &total_tests);
	
	puts("\n\n =============== TEST MATH ==================\n\n");
	test_math(tests, &failed_tests, &total_tests);

	puts("\n\n =============== TEST MEMORY ================\n\n");
	test_memory(tests, &failed_tests, &total_tests);

	puts("\n\n =============== TEST STDIO =================\n\n");
	test_stdio(tests, &total_tests);

	puts("\n\n =============== TEST STDLIB ================\n\n");
	test_stdlib(tests, &failed_tests, &total_tests);

	puts("\n\n =============== TEST STRING ================\n\n");
	test_string(tests, &failed_tests, &total_tests);


	puts("\n >>>>>>>>>>>>>>>> TESTS RESULT <<<<<<<<<<<<<<<<");
	tests_result(total_tests, failed_tests);
	return 0;
}

void test_ctype(int tests, int *failed_tests, int *total_tests)
{
	int test_values_ctype[]          = { 'a', 'A', 'z', 'Z', '0', '9', '^', '+', '\'', ']', 'X', 'x', 0, 31, 777};	

	int expected_values_ft_isalnum[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0};	
	int expected_values_ft_isalpha[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0};		
	int expected_values_ft_isascii[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};	
	int expected_values_ft_isdigit[] = { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};	
	int expected_values_ft_isupper[] = { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};	
	int expected_values_ft_islower[] = { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};		
	int expected_values_ft_isprint[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};	
	int expected_values_ft_toupper[] = { 'A', 'A', 'Z', 'Z', '0', '9', '^', '+', '\'', ']', 'X', 'X', 0, 31, 777};	
	int expected_values_ft_tolower[] = { 'a', 'a', 'z', 'z', '0', '9', '^', '+', '\'', ']', 'x', 'x', 0, 31, 777};	
	
	*failed_tests += test_ctype_func(ft_isalnum, test_values_ctype, expected_values_ft_isalnum, tests, "ft_isalnum");
	*failed_tests += test_ctype_func(ft_isalpha, test_values_ctype, expected_values_ft_isalpha, tests, "ft_isalpha");
	*failed_tests += test_ctype_func(ft_isascii, test_values_ctype, expected_values_ft_isascii, tests, "ft_isascii");
	*failed_tests += test_ctype_func(ft_isdigit, test_values_ctype, expected_values_ft_isdigit, tests, "ft_isdigit");
	*failed_tests += test_ctype_func(ft_isupper, test_values_ctype, expected_values_ft_isupper, tests, "ft_isupper");
	*failed_tests += test_ctype_func(ft_islower, test_values_ctype, expected_values_ft_islower, tests, "ft_islower");
	*failed_tests += test_ctype_func(ft_isprint, test_values_ctype, expected_values_ft_isprint, tests, "ft_isprint");
	*failed_tests += test_ctype_func(ft_toupper, test_values_ctype, expected_values_ft_toupper, tests, "ft_toupper");
	*failed_tests += test_ctype_func(ft_tolower, test_values_ctype, expected_values_ft_tolower, tests, "ft_tolower");

	*total_tests += tests * 9;
}

void test_math(int tests, int *failed_tests, int *total_tests)
{
	double test_values_math[] = {2, -13, -14.0001, 64, 65.0000001, 0.001, 1, -1, 0.0001, 1024, -2, 333.333, 997.5, -31, 777};
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

	unsigned long test_values_ft_pfactorial[15][3] = 
	{
		{0, 0, 0},
		{0, 1, 0},
		{123, 122, 0},
		{1, 5, 120},
		{1, 7, 5040},
		{2, 41, 15551764317513711616UL},
		{2, 42, 7538058755741581312UL},
		{2, 16, 20922789888000UL},
		{2, 128, _INF},
		{3, 7, 2520},
		{5, 12, 19958400UL},
		{2, 65, 9223372036854775808UL},
		{2, 66, _INF},
		{2, 50, 15188249005818642432UL},
		{2, 13, 6227020800UL}
	};	

	unsigned long test_values_ft_factorial[15][2] = 
	{
		{0,  1},
		{7,  5040},
		{9,  362880},
		{10, 3628800},
		{11, 39916800UL},
		{12, 479001600UL},
		{13, 6227020800UL},
		{14, 87178291200UL},
		{15, 1307674368000UL},
		{16, 20922789888000UL},
		{17, 355687428096000UL},
		{18, 6402373705728000UL},
		{19, 121645100408832000UL},
		{20, 2432902008176640000UL},
		{21, _INF}
	};	

	unsigned long test_values_ft_variations[15][3] = 
	{
		{0, 0, 1},
		{0, 1, 1},
		{5, 45, 146611080},
		{1, 5, 5},
		{7, 7, 5040},
		{2, 41, 1640},
		{6, 19, 19535040},
		{8, 34, 732058145280},
		{2, 128, 16256},
		{13, 15, 653837184000},
		{5, 12, 95040},
		{4, 65, 16248960},
		{3, 47, 97290},
		{12, 19, 24135932620800},
		{9, 19, 33522128640}
	};	

	unsigned long test_values_ft_variations_r[15][3] = 
	{
		{0, 0, 1},
		{0, 1, 0},
		{123, 0, 1},
		{5, 2, 25},
		{122, 3, 1815848},
		{2, 63, 9223372036854775808UL},
		{2, 65, _INF},
		{142, 3, 2863288},
		{2, 64, _INF},
		{2, 37, 137438953472},
		{2, 32, 4294967296},
		{9, 12, 282429536481},
		{9, 7, 4782969},
		{4, 17, 17179869184},
		{13, 2, 169}
	};	

	unsigned long test_values_ft_combinations[15][3] = 
	{
		{0, 0, 1},
		{0, 1, 1},
		{5, 45, 1221759},
		{1, 5, 5},
		{7, 7, 1},
		{2, 41, 820},
		{6, 19, 27132},
		{8, 34, 18156204},
		{2, 128, 8128},
		{13, 15, 105},
		{5, 12, 792},
		{4, 65, 677040},
		{3, 47, 16215},
		{12, 19, 50388},
		{9, 19, 92378}
	};	

	unsigned long test_values_ft_combinations_r[15][3] = 
	{
		{0, 0, 1},
		{0, 1, 1},
		{5, 45, 1906884},
		{1, 5, 5},
		{7, 7, 1716},
		{2, 41, 861},
		{6, 19, 134596},
		{8, 34, 95548245},
		{2, 128, 8256},
		{13, 15, 20058300},
		{5, 12, 4368},
		{4, 65, 814385},
		{3, 47, 18424},
		{12, 19, 86493225},
		{9, 19, 4686825}
	};	

	*failed_tests += test_math_func_1_arg(ft_log, log, test_values_math, tests, "ft_log");
	*failed_tests += test_math_func_1_arg(ft_exp, exp, test_values_math, tests, "ft_exp");
	*failed_tests += test_math_func_1_arg(ft_sqrt, sqrt, test_values_math, tests, "ft_sqrt");
	*failed_tests += test_ft_inf();
	*total_tests += 1;
	*failed_tests += test_math_func_2_arg(ft_pow, pow, test_values_math_2_arg, tests, "ft_pow");
	*failed_tests += test_math_func_comb(ft_pfactorial, test_values_ft_pfactorial, tests, "ft_pfactorial");
	*failed_tests += test_math_func_factorial(ft_factorial, test_values_ft_factorial, tests, "ft_factorial");
	*failed_tests += test_math_func_factorial(ft_permutations, test_values_ft_factorial, tests, "ft_permutations");
	*failed_tests += test_math_func_comb(ft_variations, test_values_ft_variations, tests, "ft_variations");
	*failed_tests += test_math_func_comb(ft_variations_r, test_values_ft_variations_r, tests, "ft_variations_r");
	*failed_tests += test_math_func_comb(ft_combinations, test_values_ft_combinations, tests, "ft_combinations");
	*failed_tests += test_math_func_comb(ft_combinations_r, test_values_ft_combinations_r, tests, "ft_combinations_r");

	*total_tests += tests * 11;
}

void test_memory(int tests, int *failed_tests, int *total_tests)
{
	int test_values_ft_memset[15][2] = 
	{
		{1,    12},
		{'F',   0},
		{'a',  16},
		{0xff,  6},
		{0,    32},
		{'x', 	10},
		{';', 	19},
		{'#', 	27},
		{'^', 	32},
		{0,      2},
		{':',    2},
		{45,     4},
		{0x66,  16},
		{-1,     6},
		{122,   15}
	};

	int test_values_ft_bzero[15] = { 1, 2, 3, 4, 5, 10, 20, 30, 32, 16, 3, 19, 0, 11, 13 };

	int test_values_ft_memchr[15][2] = 
	{
		{'y', 32},
		{'a',  0},
		{'2', 16},
		{'f',  6},
		{4,   32},
		{'q', 20},
		{'T',  5},
		{'4', 27},
		{'2', 32},
		{'_', 12},
		{'i', 50},
		{'y',  4},
		{'g', 16},
		{'*',  6},
		{'*', 25}
	};

	int test_values_ft_memcpy[15] = { 1, 2, 3, 4, 5, 10, 20, 30, 32, 16, 40, 19, 0, 11, 13 };

	int test_values_ft_memccpy[15][2] = 
	{
		{'y', 31},
		{'a',  0},
		{'y', 31},
		{'f',  6},
		{4,   32},
		{'q', 20},
		{'T',  5},
		{'4', 27},
		{'2', 32},
		{'_', 12},
		{'i', 50},
		{'y',  5},
		{'g', 16},
		{'*',  6},
		{'*', 25}
	};

	int test_values_ft_memmove[15] = { 1, 2, 3, 4, 5, 10, 20, 30, 32, 16, 40, 19, 0, 11, 13 };

	*failed_tests += test_ft_memset(test_values_ft_memset, tests);
	*failed_tests += test_ft_bzero(test_values_ft_bzero, tests);
	*failed_tests += test_ft_memchr(test_values_ft_memchr, tests);
	*failed_tests += test_ft_memcpy(test_values_ft_memcpy, tests);
	*failed_tests += test_ft_memccpy(test_values_ft_memccpy, tests);
	*failed_tests += test_ft_memmove(test_values_ft_memmove, tests);

	// To test ft_memcmp() it is better to replace in the previous test standart memcmp() on ft_memcmp() 
	*failed_tests += test_ft_memcmp(test_values_ft_memmove, tests);
	*total_tests += tests * 7;
}

void test_stdio(int tests, int *total_tests)
{
	int test_values_ft_putchar[15] = {'a', 'A', 'z', 'Z', '0', '9', '_', ':', '+', '&', '\'', '\"', '\n', '\t', '\0'};

	char *test_values_print_strings[15][2] = 
	{
		{"a", "a"},
		{"(word\\v)\\n", "(word\v)\n"},
		{"Hello, world!\\n", "Hello, world!\n"},
		{"...$%^ %^&*&*()\\n", "...$%^ %^&*&*()\n"},
		{"word1 word2, word3;\\n", "word1 word2, word3;\n"},
		{" \\x\\n", " \\x\\n"},
		{"\\t{a\\tb\\tc}\\t\\n", "\t{a\tb\tc}\t\n"},
		{"(((\\t)))\n", "(((\t)))\\n"},
		{"\\xff\\x45\\x37\\x20\\x24\\n\\n", "\xff\x45\x37\x20\x24\n"},
		{"Hello, world!\\b\\b\\b\\b\\b\\b\\n", "Hello, world!\b\b\b\b\b\b\n"},
		{"a b c\\r\\n", "a b c\r\n"},
		{"^^^\\n", "^^^\n"},
		{" word1\\b2\\n", " word1\b2\n"},
		{"|\\ttable\\t|\\n", "|\ttable\t|\n"},
		{" word1\\tword2,\\tword3;\\n", " word1\tword2,\tword3;\n"}
	};

	int test_values_ft_putnbr_fd[15] = {1, -2, 3, 4, 5, -6, 7, 8, 9, 0, 11, -12, 13, 1234567890, 15};

	test_stdio_ft_putchar(ft_putchar, test_values_ft_putchar, tests, "ft_putchar");
	test_stdio_ft_putchar_fd(ft_putchar_fd, test_values_ft_putchar, tests, "ft_putchar_fd");
	test_stdio_ft_putstr(ft_putstr, test_values_print_strings, tests, "ft_putstr");
	test_stdio_ft_putstr(ft_puts, test_values_print_strings, tests, "ft_puts");
	test_stdio_ft_putstr_fd(ft_putstr_fd, test_values_print_strings, tests, "ft_putstr_fd");
	test_stdio_ft_putstr_fd(ft_putendl_fd, test_values_print_strings, tests, "ft_putendl_fd");
	test_stdio_ft_putnbr_fd(test_values_ft_putnbr_fd, tests);

	*total_tests += tests * 7;
}

void test_stdlib(int tests, int *failed_tests, int *total_tests)
{
	char *test_values_ft_atoi[15] = 
	{
		"1",
		"0",
		"00",
		"001",
		"-1",
		"1234567890",
		"0123456789",
		"-12",
		"--12",
		"88-1",
		"112",
		"111",
		"1000000001",
		"00010001",
		"101"
	};

	int test_values_ft_range[15][2] = 
	{
		{1, 10},
		{0, 10},
		{1, 5},
		{10, 12},
		{1, 1},
		{1, 0},
		{0, 1},
		{0, 0},
		{1, 8},
		{1, 3},
		{2, 4},
		{3, 12},
		{4, 14},
		{5, 10},
		{5, 0}
	};

	size_t test_values_ft_calloc[15] = 
	{ 
		sizeof(int), 
		sizeof(char), 
		sizeof(char *), 
		sizeof(int *), 
		sizeof(long), 
		sizeof(unsigned int), 
		sizeof(unsigned long), 
		sizeof(double), 
		sizeof(unsigned long long), 
		3, 
		7, 
		14, 
		0, 
		1, 
		34
	};

	int test_sizes_ft_calloc[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -1, 12, 13, 14, 15};

	*failed_tests += test_stdlib_ft_atoi(test_values_ft_atoi, tests);
	*failed_tests += test_stdlib_ft_range(test_values_ft_range, tests);
	*failed_tests += test_stdlib_ft_calloc(test_values_ft_calloc, test_sizes_ft_calloc, tests);
	*total_tests += tests * 3;
}

void test_string(int tests, int *failed_tests, int *total_tests)
{
	char *test_values_ft_strlen[15] = 
	{
		"a",
		"(word)\n",
		"Hello, world!\n",
		"...$%^ %^&*&*()\n",
		"word1 word2, word3;\n",
		" \\x\n", 
		"{a\tb\tc}\n",
		"(((\\t)))\n",
		"\\xff\\x45\\x37\\x20\\x24\\n\\n",
		"Hello, world!\\b\\b\\b\\b\\b\\b\\n",
		"a b c\r\n",
		"^^^\n",
		" word1\\b2\\n",
		"|\ttable\t|\n",
		" word1\tword2,\tword3;\n"
	};

	size_t test_values_ft_strlcpy[15] = { 1, 22, 3, 4, 5, 10, 20, 30, 32, 16, 40, 19, 0, 11, 13 };

	size_t test_values_ft_strlcat[15] = { 1, 22, 3, 4, 5, 10, 20, 30, 32, 16, 40, 19, 0, 11, 13 };
	
	char *test_strings_ft_strlcat[15] = 
	{
		"a",
		"(word)\n",
		"Hello, world!\n",
		"...$%^ %^&*&*()\n",
		"word1 word2, word3;\n",
		" \\x\n", 
		"{a b c}\n",
		"(((\\t)))\n",
		"\\xff\\x45\\x37\\x20\\x24\\n\\n",
		"Hello, world!\n",
		"a b c\r\n",
		"^^^\n",
		" word1\\b2\\n",
		NULL,
		" word1 word2,       word3;\n"
	};

	int test_values_ft_strchr[15] = { 'y', 'a', '2', 'f', 4, 'q', 'T', '4', '2', '_', 'i', 'y', 'g', '*', '*'};

	*failed_tests += test_ft_strlen(test_values_ft_strlen, tests);
	*failed_tests += test_ft_strlcpy(test_values_ft_strlcpy, tests);
	*failed_tests += test_ft_strlcat(test_values_ft_strlcat, test_strings_ft_strlcat, tests);
	*failed_tests += test_ft_strchr(ft_strchr, strchr, test_values_ft_strchr, tests, "strchr");
	*failed_tests += test_ft_strchr(ft_strrchr, strrchr, test_values_ft_strchr, tests, "strrchr");
	*total_tests += tests * 5;
}
