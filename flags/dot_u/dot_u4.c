/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:16:59 by egomes            #+#    #+#             */
/*   Updated: 2021/04/10 23:38:48 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_u4_1(t_dot *dotd, t_obj *obj, const char *str)
{
	if (dotd->buff[-1] >= '0' && dotd->buff[-1] <= '9')
	{
		dotd->bf = ft_strlen_bfdot(str);
		dotd->bu = ft_strlen(dotd->bf);
		if (dotd->au >= dotd->bu && dotd->au > dotd->lu)
		{
			ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
			ft_putchars(dotd->af, obj);
		}
		else if (dotd->bu > dotd->au && dotd->au > dotd->lu)
		{
			ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
			ft_memcpy(dotd->bf, dotd->af, dotd->bu - dotd->au, dotd->au);
			ft_putchars(dotd->bf, obj);
		}
		else
			ft_putchars(dotd->s, obj);
	}
}

void	dot_u4(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->af = ft_newstr(dotd->au);
	ft_memset(dotd->af, '0', dotd->au);
	dot_u4_1(dotd, obj, str);
	if (dotd->au > dotd->lu)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->au - dotd->lu, dotd->lu);
		if (ft_isneg(dotd->s))
			ft_neg(dotd->af);
		ft_putchars(dotd->af, obj);
	}
	ft_putchars(dotd->s, obj);
}
