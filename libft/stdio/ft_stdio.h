/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:19:26 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/12 14:56:43 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
#define FT_STDIO_H

#include "../libft.h"
#include "printf/ft_printf.h"

#define PRINT_NULL "(null)"
#define PRINT_NIL  "(nil)"

/* Print character */
extern void ft_putchar(char c);

/* Print string on the current line */
extern void ft_putstr(const char *str);

/* Print string on the new line */
extern void ft_puts(const char *str);

/* Outputs the character ’c’ to the given file descriptor. */
extern void ft_putchar_fd(char c, int fd);

/* Outputs the string ’s’ to the given file descriptor. */
extern void ft_putstr_fd(const char *s, int fd);

/* Outputs the string ’s’ to the given file 
 * descriptor, followed by a newline. */
extern void ft_putendl_fd(const char *s, int fd);

/* Outputs the integer ’n’ to the given file descriptor.*/
extern void ft_putnbr_fd(int n, int fd);

#endif /* FT_STDIO_H */
