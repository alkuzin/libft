/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_inf.c                                                                 */
/*                                                                            */
/*   By: alkuzin <->                                                          */
/*                                                                            */
/*   Created: 2023/12/30 22:15:49 by alkuzin                                  */
/*   Updated: 2023/12/30 22:19:21 by alkuzin                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

union double_long_u {
 double d;
 unsigned long l;
};

double ft_inf(void)
{
   union double_long_u u;
   
   u.l = 0x7FF0000000000000ULL;
   return u.d;
}
