/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:26:42 by egomes            #+#    #+#             */
/*   Updated: 2021/05/26 11:43:15 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_x6(t_dot *dotd, t_obj *obj)
{
	if (dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		if (ft_isneg(dotd->s))
		{
			ft_negdi(dotd->af);
			dotd->neg = ft_newstr(dotd->au);
			ft_memcpynegstay(dotd->neg, dotd->af, dotd->au);
			ft_putchars(dotd->neg, obj);
			free(dotd->neg);
		}
		else
			ft_putchars(dotd->af, obj);
	}
	else
		ft_putchars(dotd->s, obj);
	free(dotd->af);
	free(dotd->bf);
}

void	dot_u6(t_dot *dotd, t_obj *obj)
{
	if (dotd->au >= dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		if (ft_isneg(dotd->s))
		{
			ft_negdi(dotd->af);
			dotd->neg = ft_newstr(dotd->au);
			ft_memcpynegstay(dotd->neg, dotd->af, dotd->au);
			ft_putchars(dotd->neg, obj);
			free(dotd->neg);
		}
		else
			ft_putchars(dotd->af, obj);
	}
	else if (ft_atoi(dotd->s) != 0)
		ft_putchars(dotd->s, obj);
	free(dotd->af);
	free(dotd->bf);
}

void	dot_u7_1(t_dot *dotd)
{
	if (ft_isneg(dotd->s))
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		if (dotd->au > 2)
			ft_negdi(dotd->af);
		dotd->neg = ft_newstr(dotd->au);
		ft_memcpynegstay(dotd->neg, dotd->af, dotd->au);
		ft_memcpy(dotd->bf, dotd->neg, dotd->bu - dotd->au, dotd->au);
		free(dotd->neg);
	}
	else if (ft_findless(dotd->buff))
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
	}
	else
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		ft_memcpy(dotd->bf, dotd->af, dotd->bu - dotd->au, dotd->au);
	}
}

void	dot_u7(t_dot *dotd, t_obj *obj)
{
	if (dotd->au != 0 && dotd->au >= dotd->lu)
		dot_u7_1(dotd);
	else if (ft_atoi(dotd->s) == 0)
		ft_memcpy(dotd->bf, 0, 0, 0);
	else if ((dotd->au < dotd->lu) && (dotd->bu >= dotd->lu))
	{
		if (ft_findless(dotd->buff))
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		else
			ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
	}
	else if (ft_isneg(dotd->s))
		ft_negdi(dotd->bf);
	if (dotd->lu > dotd->bu)
		ft_putchars(dotd->s, obj);
	else
		ft_putchars(dotd->bf, obj);
	free(dotd->bf);
	free(dotd->af);
}

void	dot_u4_0(t_dot *dotd)
{
	if (dotd->au < 0)
	{
		dotd->af = ft_newstr(dotd->cpyau);
		ft_memset(dotd->af, '0', dotd->cpyau);
	}
	else
	{
		dotd->af = ft_newstr(dotd->au);
		ft_memset(dotd->af, '0', dotd->au);
	}
}
