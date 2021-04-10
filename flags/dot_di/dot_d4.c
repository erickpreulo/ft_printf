/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:16:59 by egomes            #+#    #+#             */
/*   Updated: 2021/04/09 11:17:14 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d4_1(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->buff[-1] >= '0' && dotd->buff[-1] <= '9')
	{
		dotd->bf = ft_strlen_bfdot(str);
		dotd->b = ft_strlen(dotd->bf);
		if (dotd->a >= dotd->b && dotd->a > dotd->l)
		{
			ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
			ft_putchars(dotd->af, obj);
		}
		else if (dotd->b > dotd->a && dotd->a > dotd->l)
		{
			ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
			ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->a, dotd->a);
			ft_putchars(dotd->bf, obj);
		}
		else
			ft_putchars(dotd->s, obj);
	}
}

void	dot_d4(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->af = ft_newstr(dotd->a);
	ft_memset(dotd->af, '0', dotd->a);
	dot_d4_1(dotd, obj, str);
	if (dotd->a > dotd->l)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		if (ft_isneg(dotd->s))
			ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	ft_putchars(dotd->s, obj);
}
