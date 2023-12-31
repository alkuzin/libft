/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:34:48 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 15:33:01 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned long ft_variations(unsigned int m, unsigned int n)
{
    if (n == m)
        return ft_factorial(n);

    if(n - m == 1)
        return n;

    if(m == 0 || n == m)
        return 1;

    return (ft_pfactorial((n - m) + 1, n));
}
