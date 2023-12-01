/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:34:48 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/01 18:39:54 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned int ft_variations(unsigned int m, unsigned int n)
{
    if(n - m == 1)
        return n;

    if(m == 0 || n == m)
        return 1;

    return (ft_pfactorial((n - m) + 1, n));
}
