/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <->                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:49 by alkuzin           #+#    #+#             */
/*   Updated: 2024/01/02 12:31:33 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
#define FT_STDLIB_H

#include "../libft.h"

/* The atoi() converts the initial portion 
 * of the string pointed to by str to int. */
extern int ft_atoi(char *str);

/* The ft_range() returns the array of int 
 * from min including to max excluding. */
extern int *ft_range(int min, int max);

/* The ft_calloc() allocates memory for an 
 * array of nmemb elements of size bytes each and 
 * returns a pointer to the allocated memory.  
 * The memory is set to zero. */
extern void *ft_calloc(size_t nmemb, size_t size);

#endif /* FT_STDLIB_H */
