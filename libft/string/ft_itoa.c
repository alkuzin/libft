/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:32:45 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/03 11:45:45 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t ft_itoa_len(long n)
{
	size_t len;

	len = 0;
	if (n == 0)
		return 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return len;
}

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

char *ft_itoa(long n)
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
