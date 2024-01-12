/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:32:40 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/12 14:51:26 by alkuzin          ###   ########.fr       */
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

/* parse flags and format options from string */
extern int __ft_parse(const char* str, va_list args);

/* %i %d options (int) */
extern int __ft_printf_int(int n);

/* %u option (unsigned int) */
extern int __ft_printf_uint(unsigned int n);

/* %x %X options (hexadecimal) */
extern int __ft_printf_hex(unsigned int n, int is_upper);

/* %s option (string) */
extern int __ft_printf_str(const char *str);

/* %c option (char) */
extern int __ft_printf_char(int c);

/* %p option (pointer) */
extern int __ft_printf_pointer(unsigned long int p);

#endif /* FT_PRINTF_H */
