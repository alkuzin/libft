/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttest.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:35:53 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/01 12:35:12 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTTEST_H
#define LIBFTTEST_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../libft/libft.h"

/* Test libft ctype functions with one argument */
extern int test_ctype_func(int(*test_f)(int), int *test_values, int *expected_values, int size, const char *func_name);


/* Test libft math functions with one argument */
extern int test_math_func_1_arg(double(*test_f)(double), double(*f)(double), double *test_values, int size, const char *func_name);

/* Test libft math functions with no arguments */
extern int test_math_func_no_arg(double(*test_f)(void), double(*f)(void),const char *func_name);

/* Test libft math functions with 2 arguments */
extern int test_math_func_2_arg(double(*test_f)(double, double), double(*f)(double, double), double (*test_values)[2], int size, const char *func_name);

/* Test libft math combinatorical functions */
extern int test_math_func_comb(unsigned long(*test_f)(unsigned int, unsigned int), unsigned long (*test_values)[3], int size, const char *func_name);

/* Test libft math factorial functions */
extern int test_math_func_factorial(unsigned long(*test_f)(unsigned int), unsigned long (*test_values)[2], int size, const char *func_name);

/* Test libft math ft_inf() function */
extern int test_ft_inf(void);


/* Test libft memory ft_memset() function */
extern int test_ft_memset(int (*test_values)[2], int size);

/* Test libft memory ft_bzero() function */
extern int test_ft_bzero(int *test_values, int size);

/* Test libft memory ft_memchr() function */
extern int test_ft_memchr(int (*test_values)[2], int size);

/* Test libft memory ft_memcpy() function */
extern int test_ft_memcpy(int *test_values, int size);

/* Test libft memory ft_memccpy() function */
extern int test_ft_memccpy(int (*test_values)[2], int size);

/* Test libft memory ft_memmove() function */
extern int test_ft_memmove(int *test_values, int size);

/* Test libft memory ft_memcmp() function */
extern int test_ft_memcmp(int *test_values, int size);


/* Test libft stdio ft_putchar() function */
extern void test_stdio_ft_putchar(void (*f)(char), int *test_values, int size, const char *func_name);

/* Test libft stdio ft_putchar_fd() function */
extern void test_stdio_ft_putchar_fd(void (*f)(char, int), int *test_values, int size, const char *func_name);

/* Test libft stdio ft_putsrt() ft_puts() function */
extern void test_stdio_ft_putstr(void (*f)(char *), char *(*test_values)[2], int size, const char *func_name);

/* Test libft stdio ft_putsrt_fd() ft_putendl_fd() function */
extern void test_stdio_ft_putstr_fd(void (*f)(char *, int), char *(*test_values)[2], int size, const char *func_name);

/* Test libft stdio ft_putnbr_fd() function */
extern void test_stdio_ft_putnbr_fd(int *test_values, int size);


/* Displays total tests result */
extern void tests_result(int total_tests, int failed_tests);

#endif /* LIBFTTEST_H */
