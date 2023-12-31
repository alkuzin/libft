/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variations_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:13:42 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 15:33:07 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned long ft_variations_r(unsigned int n, unsigned int m)
{
    unsigned long result;
    unsigned int i;


    if(m == 0)
        return 1;

    if(n == 0)
        return 0;

    if (m >= n && ((m - n) >= 64))
        return _INF;
    

    result = 1;
    i = 0;
    while(i < m)
    {
        result *= n;
        i++; 
    }
    return result;
}
