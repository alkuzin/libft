/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:48:55 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 22:07:37 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *src;
    unsigned char cc;
    int i;


    src = (unsigned char *)s;
    cc = (unsigned char)c;
    
    i = 0;
    while(n-- && src[i])
    {
        src[i] = cc;
        i++;
    }

    return s;
}
