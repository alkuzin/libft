/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfactorial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:11:52 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 15:32:51 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned long ft_pfactorial(unsigned int n, unsigned int m)
{
    unsigned long result;

    if(n == 0 || m == 0 || m < n)
        return 0;
   
    if(n == m)
       return n; 

    result = 1;
    while(n <= m)
    {
        result *= n;
        n++; 
    }
    return result;
}
