/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:43:49 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/01 12:05:41 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *ptr_src;
	unsigned char *ptr_dst;


	ptr_dst = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_src > ptr_dst)
	{
		while (n > 0)
		{
			*ptr_dst++ = *ptr_src++;
			n--;
		}
	}
	else
	{
		ptr_src = ptr_src + n - 1;
		ptr_dst = ptr_dst + n - 1;
		while (n > 0)
		{
			*ptr_dst-- = *ptr_src--;
			n--;
		}
	}
	return dest;
}
