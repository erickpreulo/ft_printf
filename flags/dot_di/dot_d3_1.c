/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d3_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:51:31 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 14:52:49 by egomes           ###   ########.fr       */
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
