/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:43:58 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 22:07:22 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char *cdest;
    const unsigned char *csrc;
    unsigned char *target;
    size_t i;


    cdest = (unsigned char *)dest;
    csrc = (const unsigned char *)src;

    if ((target = ft_memchr(src, c, n)) == NULL)
        return NULL;

    i = 0;
    while(csrc[i])
    {
        cdest[i] = csrc[i];

        if(&csrc[i] == target)
            return dest;
        i++;
    }

    return NULL;
}
