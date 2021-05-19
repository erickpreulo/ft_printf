/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:27:41 by egomes            #+#    #+#             */
/*   Updated: 2021/05/19 11:59:00 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d2_2(t_dot *dotd)
{
	if (dotd->a < 0)
	{
		dotd->cpya *= dotd->a;
		if ((ft_isneg(dotd->s)))
			dotd->cpya += 1;
		dotd->af = ft_newstr(dotd->cpya);
		ft_memset(dotd->af, '0', dotd->cpya);
	}
	else
	{
		if (!(ft_isneg(dotd->s)))
			dotd->af = ft_newstr(dotd->a);
		else
		{
			dotd->a += 1;
			dotd->af = ft_newstr(dotd->a);
		}
		ft_memset(dotd->af, '0', dotd->a);
	}
}

void	dot_d2_3(t_dot *dotd, t_obj *obj)
{
	if (dotd->a < 0)
		ft_memcpy(dotd->af, dotd->s, dotd->cpya - dotd->l, dotd->l);
	else
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
	if (ft_isneg(dotd->s) && (dotd->cpya > dotd->l || dotd->a > dotd->l))
		ft_neg(dotd->af);
	if (ft_findless(dotd->buff))
	{
		if (dotd->a < 0)
			ft_memcpy(dotd->bf, dotd->af, 0, dotd->cpya);
		else
			ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
	}
	else
	{
		if (dotd->a < 0)
			ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->cpya, dotd->cpya);
		else
			ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->a, dotd->a);
	}
	ft_putchars(dotd->bf, obj);
}

void	dot_d2_4(t_dot *dotd, t_obj *obj)
{
	ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
	if (ft_isneg(dotd->s))
		ft_neg(dotd->af);
	ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
	ft_putchars(dotd->bf, obj);
}

void	dot_d2_5(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->af[0] == '\0' && (dotd->s[0] == '0' && dotd->s[1] == '\0'))
		ft_putchars(dotd->bf, obj);
	else if (ft_findless(dotd->buff))
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		ft_putchars(dotd->bf, obj);
	}
	else
	{
		ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
		if (dotd->a < 0 && dotd->b > dotd->l && str[0] == '0')
			ft_neg(dotd->bf);
		ft_putchars(dotd->bf, obj);
	}
}

void	dot_d2(t_dot *dotd, t_obj *obj, const char *str)
{
	dot_d2_1(dotd, str);
	dot_d2_2(dotd);
	if (dotd->b > dotd->a && dotd->a >= dotd->l)
		dot_d2_3(dotd, obj);
	else if (dotd->cpyb > dotd->a && dotd->a >= dotd->l)
		dot_d2_4(dotd, obj);
	else if (dotd->b > dotd->l && dotd->a < dotd->l)
		dot_d2_5(dotd, obj, str);
	else if (dotd->cpyb >= dotd->l && dotd->a < dotd->l)
	{
		if (!(ft_atoi(dotd->s) == 0 && dotd->a == 0))
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		ft_putchars(dotd->bf, obj);
	}
	else if (dotd->a > dotd->l)
		dot_d2_6(dotd, obj);
	else if (ft_atoi(dotd->s) == 0 && dotd->a == 0)
		ft_putchars(dotd->bf, obj);
	else
		ft_putchars(dotd->s, obj);
	free(dotd->af);
	free(dotd->bf);
}
