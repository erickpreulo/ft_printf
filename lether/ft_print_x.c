/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:11:25 by egomes            #+#    #+#             */
/*   Updated: 2021/05/19 16:43:47 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printx(const char *str, t_obj *obj)
{
	if (ft_strlen_find_dot(str))
		ft_printdot_hex(str, obj, "0123456789abcdef");
	else if (ft_find_as(str))
		ft_printas_x(obj, "0123456789abcdef", str);
	else if (ft_findless(str))
		ft_printendspacehex("0123456789abcdef", obj);
	else if (str[0] == '0')
		ft_print0hex("0123456789abcdef", obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacehex("0123456789abcdef", obj);
	else if (str[0] == 'x')
		ft_putnbr_hex(va_arg(obj->ap, unsigned int), "0123456789abcdef", obj);
}

void	printX(const char *str, t_obj *obj)
{
	if (ft_strlen_find_dot(str))
		ft_printdot_hex(str, obj, "0123456789ABCDEF");
	else if (ft_find_as(str))
		ft_printas_x(obj, "0123456789ABCDEF", str);
	else if (ft_findless(str))
		ft_printendspacehex("0123456789ABCDEF", obj);
	else if (str[0] == '0')
		ft_print0hex("0123456789ABCDEF", obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacehex("0123456789ABCDEF", obj);
	else if (str[0] == 'X')
		ft_putnbr_hex(va_arg(obj->ap, unsigned int), "0123456789ABCDEF", obj);
}

void	printpc(const char *str, t_obj *obj)
{
	char	c;
	t_as	asc;

	c = '%';
	if (ft_find_as(str))
		ft_printas_pc(&asc, obj, str);
	else if (ft_findless(str) && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacec(c, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacec(c, obj);
	else if (str[0] == '0')
		ft_print0pc(obj);
	else
		ft_putchar(c, obj);
}
