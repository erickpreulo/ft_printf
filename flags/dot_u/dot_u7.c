/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:27:16 by egomes            #+#    #+#             */
/*   Updated: 2021/04/09 11:27:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_memcpy(dotd->bf, dotd->s, dotd->bu - dotd->lu, dotd->lu);
	else if (ft_isneg(dotd->s))
		ft_negdi(dotd->bf);
	if (dotd->lu > dotd->bu)
		ft_putchars(dotd->s, obj);
	else
		ft_putchars(dotd->bf, obj);
}
