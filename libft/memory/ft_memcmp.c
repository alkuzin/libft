/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:07:24 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/01 12:12:47 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while(n--)
	{
		if(*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}

	return 0;
}
