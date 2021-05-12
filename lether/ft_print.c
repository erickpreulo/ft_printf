/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:04:57 by egomes            #+#    #+#             */
/*   Updated: 2021/05/12 16:32:29 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printc(const char *str, t_obj *obj)
{
	char	c;

	c = '%';
	if (ft_find_as(str))
		ft_printas_c(obj, str);
	else
		c = (char)va_arg(obj->ap, int);
	if ((ft_findless(str)) && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacec(c, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacec(c, obj);
	else
		ft_putchar(c, obj);
}

void	printdi(const char *str, t_obj *obj)
{
	if (ft_strlen_find_dot(str))
		ft_printdot_di(str, obj);
	else if (ft_find_as(str))
		ft_printas_di(obj, str);
	else if (ft_findless(str))
		ft_printendspace(obj);
	else if (str[0] == '0')
		ft_print0(obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspace(obj);
	else if (str[0] == 'd' || str[0] == 'i')
	{
		obj->buff = ft_itoa(va_arg(obj->ap, int));
		ft_putchars(obj->buff, obj);
		free(obj->buff);
	}
}

void	printp(const char *str, t_obj *obj)
{
	if (obj->size < 0)
		obj->size *= -1;
	if ((ft_findless(str)) && (str[0] >= '0' && str[0] <= '9'))
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
			ft_putnbr_hex(va_arg(obj->ap, unsigned long),
				"0123456789abcdef", obj);
	}
}

void	prints(const char *str, t_obj *obj)
{
	if (ft_find_as(str))
		ft_printas_s(obj, str);
	else if (ft_strlen_find_dot(str) && str[0] != '*')
		ft_printdot_s(str, obj);
	else if (ft_findless(str))
		ft_printendspaces(obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspaces(obj);
	else
	{
		obj->buff = va_arg(obj->ap, char *);
		if (obj->buff == NULL)
			obj->buff = "(null)";
		ft_putchars(obj->buff, obj);
	}
}

void	printu(const char *str, t_obj *obj)
{
	char	*s;

	if (ft_strlen_find_dot(str))
		ft_printdot_u(str, obj);
	else if (ft_find_as(str))
		ft_printas_u(obj, str);
	else if (ft_findless(str) && str[0] != '*')
		ft_printendspaceu(obj);
	else if (str[0] == '0')
		ft_print0u(obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspaceu(obj);
	else
	{
		s = ft_itoap(va_arg(obj->ap, unsigned int));
		ft_putchars(s, obj);
		free(s);
	}
}
