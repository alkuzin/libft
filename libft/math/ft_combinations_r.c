/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combinations_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkuzin <[null]@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:00:13 by alkuzin           #+#    #+#             */
/*   Updated: 2023/12/31 15:32:00 by alkuzin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned long ft_combinations_r(unsigned int m, unsigned int n)
{
    
    if(n - m == 1)
        return n;

    if(m == 0)
        return 1;

    return ft_combinations(m, (n + m) - 1);
}
