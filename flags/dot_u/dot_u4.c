/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:16:59 by egomes            #+#    #+#             */
/*   Updated: 2021/04/17 22:57:24 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_u4(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->au < 0 && (dotd->buff[-1] <= '0' && dotd->buff[-1] >= '9'))
		ft_putchars(dotd->s, obj);
	else
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
		if (dotd->buff[-1] >= '0' && dotd->buff[-1] <= '9')
		{
			dotd->bf = ft_strlen_bfdot(str);
			dotd->bu = ft_strlen(dotd->bf);
			if (ft_findless(dotd->buff))
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
			else if (dotd->au >= dotd->bu && dotd->au > dotd->lu)
			{
				ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
				ft_putchars(dotd->af, obj);
			}
			else if ((dotd->bu > dotd->au && dotd->au > dotd->lu) || (dotd->bu > dotd->cpyau))
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
			else
				ft_putchars(dotd->s, obj);
			free(dotd->bf);
		}
		else if ((dotd->au > dotd->lu || dotd->cpyau > dotd->lu) && (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
		{
			if (dotd->au < 0)
				ft_memcpy(dotd->af, dotd->s, dotd->cpyau - dotd->lu, dotd->lu);
			else
				ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
			if (ft_isneg(dotd->s))
				ft_neg(dotd->af);
			ft_putchars(dotd->af, obj);
		}
		else if ((dotd->au >= 0 || dotd->cpya >= 0) && (dotd->buff[-1] <= '0' || dotd->buff[-1] >= '9'))
			ft_putchars(dotd->s, obj);
		free(dotd->af);
	}
}