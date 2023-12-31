/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfttest.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:35:53 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 22:06:10 by alkuzin          ###   ########.fr       */
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


/* Displays total tests result */
extern void tests_result(int total_tests, int failed_tests);

#endif /* LIBFTTEST_H */
