/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:03:31 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/11 15:15:57 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_int(int n)
{
	char *to_print;
	int i;

	
	i = 0;
	to_print = ft_itoa(n);
	while(to_print[i]) {
		write(1, &to_print[i], 1);
		i++;
	}

	free(to_print);
    return i;
}
