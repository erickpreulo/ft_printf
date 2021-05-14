/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:19:09 by egomes            #+#    #+#             */
/*   Updated: 2021/05/13 22:23:39 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d5_1_1(t_dot *dotd, t_obj *obj)
{
	ft_memcpy(dotd->af, dotd->s, dotd->a - dotd->l, dotd->l);
	if (ft_isneg(dotd->s))
	{
		ft_negdi(dotd->af);
		dotd->neg = ft_newstr(dotd->a);
		ft_memcpynegstay(dotd->neg, dotd->af, dotd->a);
		ft_memcpy(dotd->bf, dotd->neg, 0, dotd->a);
		free(dotd->neg);
	}
	else
		ft_memcpy(dotd->bf, dotd->af, 0, dotd->a);
	ft_putchars(dotd->bf, obj);
}

void	dot_d5_1(t_dot *dotd, t_obj *obj)
{
	if (dotd->a != 0 && dotd->a > dotd->l)
		dot_d5_1_1(dotd, obj);
	else if (dotd->b < dotd->l)
		ft_putchars(dotd->s, obj);
	else if (ft_atoi(dotd->s) == 0)
		ft_putchars(dotd->bf, obj);
	else
	{
		ft_memcpy(dotd->bf, dotd->s, 0, dotd->l);
		ft_putchars(dotd->bf, obj);
	}	
}

void	dot_d5(t_dot *dotd, t_obj *obj)
{
	if (dotd->a >= dotd->b)
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
		else if (ft_atoiu(dotd->s) != 0)
			ft_putchars(dotd->s, obj);
	}
	else if (dotd->a < dotd->b)
		dot_d5_1(dotd, obj);
	free(dotd->af);
	free(dotd->bf);
}
