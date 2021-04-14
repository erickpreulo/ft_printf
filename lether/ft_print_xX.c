/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:12:14 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 10:35:14 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printX(const char *str, t_obj *obj)
{
	if (ft_strlen_find_dot(str))
		ft_printdot_hex(str, obj, "0123456789ABCDEF");
	else if (str[0] == '*' || str[1] == '*' || str[2] == '*')
		ft_printas_x(obj, "0123456789ABCDEF", str);
	else if (str[-1] == '-')
		ft_printendspacehex("0123456789ABCDEF", obj);
	else if (str[0] == '0')
		ft_print0hex("0123456789ABCDEF", obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacehex("0123456789ABCDEF", obj);
	else if (str[0] == 'X')
		ft_putnbr_hex(va_arg(obj->ap, unsigned long), "0123456789ABCDEF", obj);
}
