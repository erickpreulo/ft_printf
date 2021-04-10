/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:26:42 by egomes            #+#    #+#             */
/*   Updated: 2021/04/10 23:39:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_u6(t_dot *dotd, t_obj *obj)
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
