/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:14 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/12 12:22:56 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_ptoa_len(unsigned long int pp) 
{
	unsigned long int p;
    int len;
	int i;
   
	
	p = pp;
	len = 0;
	i = (sizeof(p) << 3) - 4;
	while(i >= 0) {
		if((p >> i) & 0x1)
			len++;
		i -= 4;
   }

   if (len > 0)
       len++;

   return len;
}

/* digit to hex */
static char dtoh(int v) 
{
   if (v >= 0 && v < 10)
       return '0' + v;
   else
       return 'a' + v - 10;
}

static char *ft_ptoa(unsigned long int p)
{
	unsigned long int pp;
	int count;
	char *hex;
	int i, j;

	
	pp = (unsigned long int)p;
	i = (sizeof(pp) << 3) - 4;
	j = 0;

	hex = ft_calloc((ft_ptoa_len(pp) + 1), sizeof(char));
	while(i >= 0) {
		hex[j] = dtoh((pp >> i) & 0xf);
		i -= 4;
		j++;
		count++;
	}

	return hex;
}

int ft_printf_pointer(unsigned long int p)
{
	char *to_print;
	int count;

		
	if(p == 0) {
		ft_putstr(PRINT_NULL);
		return 0;
	}
	
	to_print = ft_ptoa(p);

	ft_putchar('0');
	ft_putchar('x');

	while(to_print[count] && to_print[count] == '0') {
		count++;
	}
	
	while(to_print[count]) {
		ft_putchar(to_print[count]);
		count++;
	}

	free(to_print);
	return count;
}
