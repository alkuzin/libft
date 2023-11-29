/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:56:12 by alkuzin           #+#    #+#             */
/*   Updated: 2023/11/29 19:12:07 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double ft_exp(double x)
{
    if(x == 0)
        return 1;
    
    if(x == 1)
        return E;
    
    int accuracy;
    double exp_sum;
    int i;

    accuracy = 44;
    exp_sum = 1;
    i = accuracy - 1;
    while (i > 0)
    {
        exp_sum = 1 + x * exp_sum / i;    
        i--;
    }

    return exp_sum; 
}
