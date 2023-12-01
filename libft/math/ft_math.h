/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:42:07 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/01 18:31:01 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
#define FT_MATH_H

#include "../libft.h"

/* Math constants */
#define PI 3.141592653589793
#define E  2.718281828459045

/* The ft_log() calculates natural logarithm */
extern double ft_log(double x);

/* The ft_pow() equal to 'x^y' in math */
extern double ft_pow(double x, double y);

/* The ft_exp() equal to 'e^x' in math */
extern double ft_exp(double x);

/* The ft_sqrt() calculates the square root */
extern double ft_sqrt(double x);

/* The ft_factorial() equal to 'n!' in math (up to 20! including) */
extern unsigned long ft_factorial(unsigned int n);

/* The ft_pfactorial() equal calculating factorial from n to m including */
extern unsigned int ft_pfactorial(unsigned int n, unsigned int m);

/* Combinatorical functions */

/* The ft_permutations() permutations without repetition */
extern unsigned long ft_permutations(unsigned int n);

/* The ft_permutations_r() permutations with repetition */
/* extern unsigned int ft_permutations_r(unsigned int n, unsigned int m, unsigned int *k); */

/* The ft_variations() variations without repetition */
extern unsigned int ft_variations(unsigned int m, unsigned int n);

/* The ft_variations_r() variations with repetition */
extern unsigned int ft_variations_r(unsigned int m, unsigned int n);

/* The ft_combinations() combinations without repetition */
extern unsigned int ft_combinations(unsigned int m, unsigned int n);

/* The ft_combinations_r() combinations with repetition */
extern unsigned int ft_combinations_r(unsigned int m, unsigned int n);

#endif /* FT_MATH_H */
