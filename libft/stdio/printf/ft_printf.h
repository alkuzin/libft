/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:32:40 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/12 12:16:59 by alkuzin          ###   ########.fr       */
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
extern int ft_parse(const char* str, va_list args);

/* int */
extern int ft_printf_int(int n);

extern int ft_printf_uint(unsigned int n);

extern int ft_printf_hex(unsigned int n, int is_upper);

/* string */
extern int ft_printf_str(char *str);

/* char */
extern int ft_printf_char(int c);

/* pointer */
extern int ft_printf_pointer(unsigned long int p);

#endif /* FT_PRINTF_H */
