/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:12:49 by egomes            #+#    #+#             */
/*   Updated: 2021/04/29 18:52:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printp(const char *str, t_obj *obj)
{
	if (obj->size < 0)
		obj->size *= -1;
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacehexp("0123456789abcdef", obj);
	else if (ft_find_as(str))
		ft_printas_p(obj, "0123456789abcdef", str);
	else if (str[0] >= '1' && str[0] <= '9' && !(ft_strlen_find_dot(str)))
		ft_printspacehexp("0123456789abcdef", obj);
	else
	{
		ft_putchar('0', obj);
		ft_putchar('x', obj);
		if (!(ft_strlen_find_dot(str)))
			ft_putnbr_hex(va_arg(obj->ap, unsigned long), "0123456789abcdef", obj);
	}
}
