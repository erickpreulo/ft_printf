/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d3_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:51:31 by egomes            #+#    #+#             */
/*   Updated: 2021/04/21 23:31:19 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d3_1(t_dot *dotd)
{
	if (dotd->b < 0)
	{
		dotd->bf = ft_newstr(dotd->cpyb);
		ft_memset(dotd->bf, ' ', dotd->cpyb);
	}
	else
	{
		dotd->bf = ft_newstr(dotd->b);
		ft_memset(dotd->bf, ' ', dotd->b);
	}
}

void	dot_d3_2_1(t_dot *dotd, t_obj *obj, const char *str)
{
	ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
	ft_neg(dotd->af);
	if (str[-1] == '-' || str[-2] == '-' || ft_isneg(dotd->s))
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
	else
		ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->a, dotd->a);
	ft_putchars(dotd->bf, obj);
}

void	dot_d3_5(t_dot *dotd, t_obj *obj)
{
	if (dotd->buff[-2] == '-')
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
	else
		ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
	ft_putchars(dotd->bf, obj);
}
