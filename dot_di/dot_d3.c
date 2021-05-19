/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:51:39 by egomes            #+#    #+#             */
/*   Updated: 2021/05/19 13:21:31 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d3_2(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->af[0] == '\0' && (dotd->s[0] == '0' && dotd->s[1] == '\0'))
		ft_putchars(dotd->bf, obj);
	else if (dotd->a >= dotd->b && dotd->a > dotd->l)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	else if (dotd->b > dotd->a && dotd->a > dotd->l)
		dot_d3_2_1(dotd, obj, str);
	else if (dotd->b > dotd->a && dotd->b > dotd->l)
	{
		if (str[-1] == '-' || str[-2] == '-')
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		else
			ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_d3_3_1(t_dot *dotd, t_obj *obj, const char *str)
{
	ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
	ft_neg(dotd->af);
	if (str[-1] == '-' || str[-2] == '-' || ft_isneg(dotd->s) || dotd->cpyb > 0)
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
	else
		ft_memcpy(dotd->bf, dotd->af, dotd->cpyb - dotd->a, dotd->a);
	ft_putchars(dotd->bf, obj);
}

void	dot_d3_3(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->a >= dotd->cpyb && dotd->a > dotd->l)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	else if (dotd->cpyb > dotd->a && dotd->a > dotd->l)
		dot_d3_3_1(dotd, obj, str);
	else if (dotd->cpyb > dotd->a && dotd->cpyb > dotd->l)
	{
		if (ft_atoi(dotd->s) != 0)
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_d3_4(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->buff[1] >= '0' && dotd->buff[1] <= '9')
	{
		dotd->af = ft_strlen_afdot(str, dotd->s, obj);
		dotd->a = ft_strlen(dotd->af);
		dot_d3_3(dotd, obj, str);
		free(dotd->af);
	}
	else if (dotd->cpyb > dotd->l)
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_d3(t_dot *dotd, t_obj *obj, const char *str)
{
	dot_d3_1(dotd);
	if (dotd->b > 0)
	{
		if (dotd->buff[1] >= '0' && dotd->buff[1] <= '9')
		{
			dotd->af = ft_strlen_afdot(str, dotd->s, obj);
			dotd->a = ft_strlen(dotd->af);
			dot_d3_2(dotd, obj, str);
			free(dotd->af);
		}
		else if (dotd->b > dotd->l)
			dot_d3_5(dotd, obj);
		else
			ft_putchars(dotd->s, obj);
	}
	else
		dot_d3_4(dotd, obj, str);
	free(dotd->bf);
}
