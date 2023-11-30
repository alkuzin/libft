/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:31:12 by alkuzin           #+#    #+#             */
/*   Updated: 2023/11/30 14:33:58 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned long ft_factorial(unsigned int n)
{
    unsigned long result;

    if(n > 20)
        return 0;

    if(n == 0)
        return 1;
    
    result = 1;
    while(n > 0)
    {
        result *= n;
        n--; 
    }
    return result;
}
