/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:49:09 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/12 14:50:55 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_xtoa_len(unsigned int n)
{
	if (n == 0)
	   return 1;
	return (int)(ft_log(n)/ft_log(16)) + 1;
}

static char *ft_xtoa(unsigned int n, int is_upper)
{
	static const char digits_lower[] = "0123456789abcdef";
	static const char digits_upper[] = "0123456789ABCDEF";
	static const char *digits = NULL;
	char *hex;
	int i;

	
	if(is_upper) 
		digits = digits_upper;
	else
		digits = digits_lower;
	
	i = ft_xtoa_len(n);
	hex = ft_calloc((i + 1), sizeof(char));
	i = 7;
	while(i >= 0) {
		hex[i] = digits[(n & 0x0F)];
		n >>= 4;
		--i;
	}
	return hex;
}

int __ft_printf_hex(unsigned int n, int is_upper)
{
	char *to_print;
	int i;

	
	i = 0;
	to_print = ft_xtoa(n, is_upper);
	
	if(n == 0) {
		ft_putchar(to_print[0]);
	}

	while(to_print[i] && to_print[i] == '0')
		i++;

	while(to_print[i]) {
		write(1, &to_print[i], 1);
		i++;
	}

	free(to_print);
    return i;
}
