/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_x2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:27:41 by egomes            #+#    #+#             */
/*   Updated: 2021/05/14 16:25:59 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_x2_2(t_dot *dotd)
{
	if (dotd->au < 0)
	{
		dotd->cpyau *= dotd->au;
		if (!(ft_isneg(dotd->s)))
			dotd->af = ft_newstr(dotd->cpyau);
		else
		{
			dotd->af = ft_newstr(dotd->cpyau + 1);
			dotd->cpyau += 1;
		}
		ft_memset(dotd->af, '0', dotd->cpyau);
	}
	else
	{
		if (!(ft_isneg(dotd->s)))
			dotd->af = ft_newstr(dotd->au);
		else
		{
			dotd->af = ft_newstr(dotd->au + 1);
			dotd->au += 1;
		}
		ft_memset(dotd->af, '0', dotd->au);
	}
}

void	dot_x2_3(t_dot *dotd, t_obj *obj)
{
	ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
	if (ft_isneg(dotd->s))
		ft_neg(dotd->af);
	if (dotd->buff[-2] == '-')
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
	else
		ft_memcpy(dotd->bf, dotd->af, dotd->bu - dotd->au, dotd->au);
	ft_putchars(dotd->bf, obj);
}

void	dot_x2_4(t_dot *dotd, t_obj *obj)
{
	ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
	if (ft_isneg(dotd->s))
		ft_neg(dotd->af);
	ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
	ft_putchars(dotd->bf, obj);
}

void	dot_x2_5(t_dot *dotd, t_obj *obj)
{
	if (dotd->af[0] == '\0' && (dotd->s[0] == '0' && dotd->s[1] == '\0'))
		ft_putchars(dotd->bf, obj);
	else if (dotd->buff[-2] == '-')
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
	else
	{
		ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}	
}

void	dot_x2(t_dot *dotd, t_obj *obj, const char *str)
{
	dot_x2_1(dotd, str);
	dot_x2_2(dotd);
	if (dotd->bu > dotd->au && dotd->au >= dotd->lu)
		dot_x2_3(dotd, obj);
	else if (dotd->cpybu > dotd->au && dotd->au > dotd->lu)
		dot_x2_4(dotd, obj);
	else if (dotd->bu > dotd->lu && dotd->au < dotd->lu)
		dot_x2_5(dotd, obj);
	else if (dotd->au == 0 && dotd->s[0] == '0')
		ft_putchars(dotd->bf, obj);
	else if (dotd->cpybu > dotd->lu && dotd->au <= dotd->lu)
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
	else if (dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_putchars(dotd->af, obj);
	}
	else
		ft_putchars(dotd->s, obj);
	free(dotd->bf);
	free(dotd->af);
}
