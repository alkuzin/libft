/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combinations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:44:25 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/01 17:55:04 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned int ft_combinations(unsigned int m, unsigned int n)
{
    if(n - m == 1)
        return n;

    if(m == 0 || n == m)
        return 1;

    return ((unsigned int)(ft_pfactorial((n - m) + 1, n) / ft_factorial(m)));
}
