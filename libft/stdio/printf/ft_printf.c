/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:45:27 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/01 21:14:34 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_parse(const char* str, va_list args);

static int ft_parse_flags(const char* str, va_list args);

static int ft_print_args(char type, va_list args);

static int ft_print_args(char type, va_list args)
{
    int count;

    count = 0;
    if(type == '%')
    {
        ft_putchar(type);
        count++;
    }
    else if(type == 'd' || type == 'i')
        count += ft_printf_int(va_args(args, int));
}

static int ft_parse(const char* str, va_list arguments)
{
    int count;
    int i;

    i = -1;
    while(str[++i]) 
    {
    
        if(str[i] == '%' && str[i + 1] != '\0')
            count += ft_print_args(str[i], args); /* change to ft_parse_flags later */ 
    }

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
    va_start(arguments, format);
    
    count = ft_parse(str, args);

    va_end(arguments);
    free(str);
    return count;    
}
