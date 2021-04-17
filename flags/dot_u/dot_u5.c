/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:19:09 by egomes            #+#    #+#             */
/*   Updated: 2021/04/16 22:11:58 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_x5_1(t_dot *dotd, t_obj *obj)
{
	if (dotd->au != 0 && dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		if (ft_isneg(dotd->s))
		{
			ft_negdi(dotd->af);
			dotd->neg = ft_newstr(dotd->au);
			ft_memcpynegstay(dotd->neg, dotd->af, dotd->au);
			ft_memcpy(dotd->bf, dotd->neg, 0, dotd->au);
			free(dotd->neg);
		}
		else
			ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
		ft_putchars(dotd->bf, obj);
	}
	else if (dotd->bu <= dotd->lu)
		ft_putchars(dotd->s, obj);
	else
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
}

void	dot_x5(t_dot *dotd, t_obj *obj)
{
	if (dotd->au >= dotd->bu)
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
	else if (dotd->au < dotd->bu)
		dot_x5_1(dotd, obj);
}

void	dot_u5_1(t_dot *dotd, t_obj *obj)
{
	if (dotd->au != 0 && dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		if (ft_isneg(dotd->s))
		{
			ft_negdi(dotd->af);
			dotd->neg = ft_newstr(dotd->au);
			ft_memcpynegstay(dotd->neg, dotd->af, dotd->au);
			ft_memcpy(dotd->bf, dotd->neg, 0, dotd->au);
			free(dotd->neg);
		}
		else
			ft_memcpy(dotd->bf, dotd->af, 0, dotd->au);
		ft_putchars(dotd->bf, obj);
	}
	else if (dotd->bu <= dotd->lu)
		ft_putchars(dotd->s, obj);
	else if (ft_atoi(dotd->s) == 0)
		ft_putchars(dotd->bf, obj);
	else
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->lu);
		ft_putchars(dotd->bf, obj);
	}
}

void	dot_u5(t_dot *dotd, t_obj *obj)
{
	if (dotd->au >= dotd->bu)
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
	}
	else if (dotd->au < dotd->bu)
		dot_u5_1(dotd, obj);
	free(dotd->bf);
	free(dotd->af);
}