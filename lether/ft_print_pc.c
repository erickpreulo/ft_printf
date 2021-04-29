/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:04:57 by egomes            #+#    #+#             */
/*   Updated: 2021/04/29 15:45:50 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printpc(const char *str, t_obj *obj)
{
	char	c;

	c = '%';
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacec(c, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacec(c, obj);
	else if (str[0] == '0')
		ft_print0pc(obj);
	else
		ft_putchar(c, obj);
}
