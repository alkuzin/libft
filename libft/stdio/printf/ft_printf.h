/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:32:40 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/01 21:06:31 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../ft_stdio.h"

typedef struct s_flags
{
    /* flags */
}t_flags;


/* The ft_printf() formats and prints data */
extern int ft_printf(const char *format, ...);

/* */
static int ft_parse(const char* str, va_list arguments);

/* int */
int ft_printf_int(int n);

#endif /* FT_PRINTF_H */
