/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:11:25 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 10:26:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printx(const char *str, t_obj *obj)
{
	if (ft_strlen_find_dot(str))
		ft_printdot_hex(str, obj, "0123456789abcdef");
	else if (str[0] == '*' || str[1] == '*' || str[2] == '*')
		ft_printas_x(obj, "0123456789abcdef", str);
	else if (str[-1] == '-')
		ft_printendspacehex("0123456789abcdef", obj);
	else if (str[0] == '0')
		ft_print0hex("0123456789abcdef", obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacehex("0123456789abcdef", obj);
	else if (str[0] == 'x')
		ft_putnbr_hex(va_arg(obj->ap, unsigned long), "0123456789abcdef", obj);
}