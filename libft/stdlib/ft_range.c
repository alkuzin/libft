/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:08:34 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/01 20:13:46 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int *ft_range(int min, int max)
{
    if(min >= max)
        return NULL;

    int i, n;
    int* array;
    int size;

    i = 0;
    n = min;
    size = max - min;
    array = (int *)malloc(sizeof(int) * (size));
    while(i < size)
    {
        array[i] = n;
        n++;
        i++;
    }    
    return array;
}
