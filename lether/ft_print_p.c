/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:12:49 by egomes            #+#    #+#             */
/*   Updated: 2021/04/12 20:57:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printp(const char *str, t_obj *obj)
{
	if (obj->size < 0)
		obj->size *= -1;
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacehexp("0123456789abcdef", obj);
	else if (str[0] == '*' || str[1] == '*' || str[2] == '*')
		ft_printas_p(obj, "0123456789abcdef", str);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacehexp("0123456789abcdef", obj);
	else
	{
		ft_putchar('0', obj);
		ft_putchar('x', obj);
		ft_putnbr_hex(va_arg(obj->ap, unsigned int), "0123456789abcdef", obj);
	}
}
