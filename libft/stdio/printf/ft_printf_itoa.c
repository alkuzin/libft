/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:09:58 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/03 11:48:10 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_num_to_str(long n, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	len--;
	while (len)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (str[0] != '-')
		str[0] = (n % 10) + '0';
	return (str);
}

char *ft_printf_itoa(long n)
{
	size_t len;
	char *str;

	len = ft_itoa_len(n);
	str = 0;
	str = ft_num_to_str(n, str, len);
	if (!str)
		return NULL;
	return str;
}
