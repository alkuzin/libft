/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:33:57 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/11 15:42:10 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t ft_utoa_len(unsigned int n)
{
	size_t len;


	len = 0;

	if (n == 0)
		return 1;

	while (n >= 1)
	{
		len++;
		n /= 10;
	}

	return len;
}

static char	*ft_num_to_str(unsigned int n, char *str, size_t len)
{
	size_t length;


	length = len;
	str = ft_calloc(len + 1, sizeof(char));

	if (!str)
		return NULL;

	len--;
	while (len)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}

	str[0] = (n % 10) + '0';
	str[length] = '\0';
		
	return str;
}

static char *ft_utoa(unsigned int n)
{
	size_t len;
	char *str;


	len = ft_utoa_len(n);
	str = NULL;
	str = ft_num_to_str(n, str, len);

	if (!str)
		return NULL;

	return str;
}

int ft_printf_uint(unsigned int n)
{
	char *to_print;
	int i;

	
	i = 0;
	to_print = ft_utoa(n);
	while(to_print[i]) {
		write(1, &to_print[i], 1);
		i++;
	}
	free(to_print);
	return i;
}
