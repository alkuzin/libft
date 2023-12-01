/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:03:31 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/01 21:11:55 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_int_len(int n);

static int ft_int_len(int n)
{
    int count;

    while(n > 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

int ft_printf_int(int n)
{
    ft_putstr(ft_itoa(n));
    return ft_int_len(n);
}
