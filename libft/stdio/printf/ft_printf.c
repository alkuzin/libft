/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:45:27 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/11 16:18:08 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int ft_parse(const char* str, va_list args);

static int ft_parse_flags(const char* str, va_list args);

static int ft_print_args(char type, va_list args);
*/

static int ft_print_args(char type, va_list args)
{
    int count;


    count = 0;
    if(type == '%') {
        ft_putchar(type);
        count++;
    }
    else if(type == 'd' || type == 'i')
        count += ft_printf_int(va_arg(args, int));
    else if(type == 'u')
        count += ft_printf_uint(va_arg(args, unsigned int));
    
	else if(type == 'x' || type == 'X')
        count += ft_printf_hex(va_arg(args, unsigned int), ft_isupper(type));
    
    else if(type == 's')
        count += ft_printf_str(va_arg(args, char *));
    else if(type == 'c')
        count += ft_printf_char(va_arg(args, int));
    return count;
}

int ft_parse(const char* str, va_list args)
{
    int count;
    int i;


    i = -1;
    while(str[++i]) {
        if(str[i] == '%' && str[i + 1] != '\0') {
            count += ft_print_args(str[i + 1], args); /* change to ft_parse_flags later */ 
            i++;
        }
        else
            ft_putchar(str[i]);
    }

    return count;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    char *str;
    int count;


    if(!format || *format == '\0')
        return 0;

    str = ft_strdup(format);
    if(!str || *str == '\0')
        return 0;

    count = 0;
    va_start(args, format); 
    count = ft_parse(str, args);
    va_end(args);

    free(str);
    return count;    
}
