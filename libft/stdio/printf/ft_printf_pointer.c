/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:14 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/12 12:29:24 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* digit to hex */
static char dtoh(int v) 
{
   if (v >= 0 && v < 10)
       return '0' + v;
   else
       return 'a' + v - 10;
}

int ft_printf_pointer(unsigned long int p)
{
	int count;
	int i;

		
	if(p == 0) {
		ft_putstr(PRINT_NULL);
		return 0;
	}
	
	ft_putchar('0');
	ft_putchar('x');
	
	count = 0;
	i = (sizeof(p) << 3) - 4;	

	/* skip first zeros */
	while(i >= 0 && ((dtoh((p >> i) & 0xf) == '0'))) {
		i -= 4;
	}
	
	while(i >= 0) {
		ft_putchar(dtoh((p >> i) & 0xf));
		i -= 4;
		count++;
	}

	return count;
}
