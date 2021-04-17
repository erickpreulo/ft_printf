/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_x3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:51:39 by egomes            #+#    #+#             */
/*   Updated: 2021/04/17 23:33:34 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_x3_2(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->au >= dotd->bu && dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	else if (dotd->bu > dotd->au && dotd->au > dotd->lu)
		dot_x3_2_1(dotd, obj, str);
	else if (dotd->bu > dotd->au && dotd->bu > dotd->lu)
	{
		if (str[-1] == '-' || str[-2] == '-')
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		else
			ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_x3_3_1(t_dot *dotd, t_obj *obj, const char *str)
{
	ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
	ft_neg(dotd->af);
	if (str[-1] == '-' || str[-2] == '-' || ft_isneg(dotd->s))
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
	else
		ft_memcpy(dotd->bf, dotd->af, dotd->cpybu - dotd->au, dotd->au);
	ft_putchars(dotd->bf, obj);
}

void	dot_x3_3(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->au >= dotd->cpybu && dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	else if (dotd->cpybu > dotd->au && dotd->au > dotd->lu)
		dot_x3_3_1(dotd, obj, str);
	else if (dotd->cpybu > dotd->au && dotd->cpybu > dotd->lu)
	{
		if (dotd->arg != 0)
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_x3_4(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->buff[1] >= '0' && dotd->buff[1] <= '9')
	{
		dotd->af = ft_strlen_afdot(str, dotd->s);
		dotd->au = ft_strlen(dotd->af);
		dot_x3_3(dotd, obj, str);
	}
	else if (dotd->cpybu > dotd->lu)
	{
		if (dotd->buff[-2] == '-')
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		else
			ft_memcpy(dotd->bf, dotd->s, dotd->cpybu - dotd->lu, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
	else
		ft_putchars(dotd->s, obj);
}

void	dot_x3(t_dot *dotd, t_obj *obj, const char *str)
{
	dot_x3_1(dotd);
	if (dotd->bu > 0)
	{
		if (dotd->buff[1] >= '0' && dotd->buff[1] <= '9')
		{
			dotd->af = ft_strlen_afdot(str, dotd->s);
			dotd->au = ft_strlen(dotd->af);
			dot_x3_2(dotd, obj, str);
		}
		else if (dotd->bu > dotd->lu)
		{
			if (dotd->buff[-2] == '-')
				ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
			else
				ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
			ft_putchars(dotd->bf, obj);
		}
		else
			ft_putchars(dotd->s, obj);
	}
	else
		dot_x3_4(dotd, obj, str);
	free(dotd->bf);
	free(dotd->af);
}
