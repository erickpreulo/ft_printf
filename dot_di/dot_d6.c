/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:26:42 by egomes            #+#    #+#             */
/*   Updated: 2021/04/16 11:19:57 by egomes           ###   ########.fr       */
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
