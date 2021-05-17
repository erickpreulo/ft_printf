/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:26:42 by egomes            #+#    #+#             */
/*   Updated: 2021/05/17 13:03:47 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d6(t_dot *dotd, t_obj *obj)
{
	if (dotd->a >= dotd->l)
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		if (ft_isneg(dotd->s))
		{
			ft_negdi(dotd->af);
			dotd->neg = ft_newstr(dotd->a);
			ft_memcpynegstay(dotd->neg, dotd->af, dotd->a);
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

void	dot_d7_1(t_dot *dotd)
{
	if (ft_isneg(dotd->s))
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		if (dotd->a > 2)
			ft_negdi(dotd->af);
		dotd->neg = ft_newstr(dotd->a);
		ft_memcpynegstay(dotd->neg, dotd->af, dotd->a);
		ft_memcpy(dotd->bf, dotd->neg, dotd->b - dotd->a, dotd->a);
		free(dotd->neg);
	}
	else
	{
		ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
		if (ft_findless(dotd->buff))
			ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
		else
			ft_memcpy(dotd->bf, dotd->af, dotd->b - dotd->a, dotd->a);
	}
}

void	dot_d7(t_dot *dotd, t_obj *obj)
{
	if (dotd->a != 0 && dotd->a >= dotd->l)
		dot_d7_1(dotd);
	else if (ft_atoi(dotd->s) == 0)
		ft_memcpy(dotd->bf, 0, 0, 0);
	else if (dotd->a <= dotd->l && dotd->b >= dotd->l)
	{
		if (ft_findless(dotd->buff))
			ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		else
			ft_memcpy(dotd->bf, dotd->s, dotd->b - dotd->l, dotd->l);
	}
	else if (ft_isneg(dotd->s))
		ft_negdi(dotd->bf);
	if (dotd->l > dotd->b)
		ft_putchars(dotd->s, obj);
	else
		ft_putchars(dotd->bf, obj);
	free(dotd->af);
	free(dotd->bf);
}
