/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:16:59 by egomes            #+#    #+#             */
/*   Updated: 2021/04/21 23:31:43 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d4_1_1(t_dot *dotd, t_obj *obj)
{
	if (dotd->a < 0)
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
	else if (dotd->l > dotd->a)
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
	else
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		ft_negdi(dotd->af);
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
	}
	ft_putchars(dotd->bf, obj);
}

void	d4_1_2(t_dot *dotd, t_obj *obj)
{
	if (dotd->a < 0)
		ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
	else if (dotd->l > dotd->a)
		ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
	else
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		ft_neg(dotd->af);
		ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->a, dotd->a);
	}
	ft_putchars(dotd->bf, obj);
}

void	d4_1(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->bf = ft_strlen_bfdot(str);
	dotd->b = ft_strlen(dotd->bf);
	if (ft_findless(dotd->buff))
		d4_1_1(dotd, obj);
	else if (dotd->a >= dotd->b && dotd->a > dotd->l)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	else if ((dotd->b > dotd->a && dotd->a > dotd->l) || (dotd->b > dotd->cpya))
		d4_1_2(dotd, obj);
	else
		ft_putchars(dotd->s, obj);
	free(dotd->bf);
}

void	d4_2(t_dot *dotd, t_obj *obj)
{
	if (dotd->a > 0)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		if (ft_isneg(dotd->s))
			ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_d4(t_dot *dotd, t_obj *obj, const char *str)
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
		d4_1(dotd, obj, str);
	else if ((dotd->a > dotd->l || dotd->cpya > dotd->l)
		&& (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
		d4_2(dotd, obj);
	else if ((dotd->a >= 0 || dotd->cpya >= 0)
		&& (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
		ft_putchars(dotd->s, obj);
	free(dotd->af);
}
