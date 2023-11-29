/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:59:06 by alkuzin           #+#    #+#             */
/*   Updated: 2023/11/29 18:31:55 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double ft_log(double x)
{
    if(x <= 0)
        return 0;

    if(x == 1)
        return 0;
    
    if(x == E)
        return 1;
    
    double result;
    double term;
    double square;
    int i;


    result = 0;
    term = (x - 1) / (x + 1);
    square = term * term;
    i = 1;
    while(i <= 1000)
    {
        result += term / i;
        term *= square;
        i++;
        i++;
    }

    return 2 * result;
}
