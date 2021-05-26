/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:16:59 by egomes            #+#    #+#             */
/*   Updated: 2021/05/26 11:43:22 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_u4_1_1(t_dot *dotd, t_obj *obj)
{
	if (dotd->au < 0)
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
	else if (dotd->lu > dotd->au)
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
	else
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
	}
	ft_putchars(dotd->bf, obj);
}

void	dot_u4_1_2(t_dot *dotd, t_obj *obj)
{
	if (dotd->au < 0)
		ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
	else if (dotd->lu > dotd->au)
		ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
	else
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->au, dotd->au);
	}
	ft_putchars(dotd->bf, obj);
}

void	dot_u4_1(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->bf = ft_strlen_bfdot(str);
	dotd->bu = ft_strlen(dotd->bf);
	if (ft_findless(dotd->buff))
		dot_u4_1_1(dotd, obj);
	else if (dotd->au >= dotd->bu && dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_putchars(dotd->af, obj);
	}
	else if ((dotd->bu > dotd->au && dotd->au > dotd->lu)
		|| (dotd->bu > dotd->cpyau))
		dot_u4_1_2(dotd, obj);
	else if (dotd->bu > dotd->lu && str[0] == '0' && dotd->au < dotd->bu)
	{
		ft_memset(dotd->bf, '0', dotd->bu);
		ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
	free(dotd->bf);
}

void	dot_u4_2(t_dot *dotd, t_obj *obj)
{
	if (dotd->au < 0)
		ft_memcpy(dotd->af, dotd->s, dotd->cpyau - dotd->lu, dotd->lu);
	else
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
	if (ft_isneg(dotd->s))
		ft_neg(dotd->af);
	ft_putchars(dotd->af, obj);
}

void	dot_u4(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->au <= 0 && (dotd->buff[-1] <= '0' && dotd->buff[-1] >= '9'))
		ft_putchars(dotd->s, obj);
	else
	{
		dot_u4_0(dotd);
		if (dotd->buff[-1] >= '0' && dotd->buff[-1] <= '9')
			dot_u4_1(dotd, obj, str);
		else if ((dotd->au > dotd->lu || dotd->cpyau > dotd->lu)
			&& (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
			dot_u4_2(dotd, obj);
		else if (dotd->s[0] == '0' && dotd->au == 0)
			dotd->au = 0;
		else if ((dotd->au > 0 || dotd->cpya > 0)
			&& (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
			ft_putchars(dotd->s, obj);
		else if (dotd->au <= dotd->lu)
			ft_putchars(dotd->s, obj);
		free(dotd->af);
	}
}
