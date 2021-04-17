/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:16:59 by egomes            #+#    #+#             */
/*   Updated: 2021/04/17 20:20:51 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d4(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->a < 0)
		ft_putchars(dotd->s, obj);
	else
	{
		if (dotd->a < 0)
		{
			dotd->af = ft_newstr(dotd->cpya);
			ft_memset(dotd->af, '0', dotd->cpya);
		}
		else
		{
			dotd->af = ft_newstr(dotd->a);
			ft_memset(dotd->af, '0', dotd->a);
		}
		if (dotd->buff[-1] >= '0' && dotd->buff[-1] <= '9')
		{
			dotd->bf = ft_strlen_bfdot(str);
			dotd->b = ft_strlen(dotd->bf);
			if (ft_findless(dotd->buff))
			{
				if (dotd->a < 0)
					ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
				else if (dotd->l > dotd->a)
					ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
				else
				{
					ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
					ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
				}
				ft_putchars(dotd->bf, obj);
			}
			else if (dotd->a >= dotd->b && dotd->a > dotd->l)
			{
				ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
				ft_putchars(dotd->af, obj);
			}
			else if ((dotd->b > dotd->a && dotd->a > dotd->l) || (dotd->b > dotd->cpya))
			{
				if (dotd->a < 0)
					ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
				else if (dotd->l > dotd->a)
					ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
				else
				{
					ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
					ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->a, dotd->a);
				}
				ft_putchars(dotd->bf, obj);
			}
			else
				ft_putchars(dotd->s, obj);
			free(dotd->bf);
		}
		else if ((dotd->a > dotd->l || dotd->cpya > dotd->l) && (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
		{
			if (dotd->a < 0)
				ft_memcpy(dotd->af, dotd->s, dotd->cpya - dotd->l, dotd->l);
			else
				ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
			if (ft_isneg(dotd->s))
				ft_neg(dotd->af);
			ft_putchars(dotd->af, obj);
		}
		else if ((dotd->a >= 0 || dotd->cpya >= 0) && (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
			ft_putchars(dotd->s, obj);
		free(dotd->af);
	}
}
