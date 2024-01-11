/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:55:16 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/11 14:55:35 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_str(char *str)
{
    if(!str) {
        ft_putstr(PRINT_NULL);
		return 0;
	}
    
	ft_putstr(str);
	return ft_strlen(str);
}
