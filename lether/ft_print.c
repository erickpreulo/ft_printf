/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:04:57 by egomes            #+#    #+#             */
/*   Updated: 2021/05/26 11:57:41 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printc(const char *str, t_obj *obj)
{
	t_as	asc;
	int		i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (ft_find_as(str))
		ft_printas_c(&asc, obj, str);
	else
		asc.c = (char)va_arg(obj->ap, int);
	if ((ft_findless(&str[i])) && (str[i] >= '0' && str[i] <= '9'))
		ft_printendspacec(asc.c, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacec(asc.c, obj);
	else if (!(ft_find_as(str)))
		ft_putchar(asc.c, obj);
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
	unsigned long	r;

	if (obj->size < 0)
		obj->size *= -1;
	if ((ft_findless(str)) && ((str[0] >= '0' && str[0] <= '9')
			|| (jump1(str) >= '0' && jump1(str) <= '9')))
		ft_printendspacehexp("0123456789abcdef", obj, str);
	else if (ft_find_as(str))
		ft_printas_p(obj, "0123456789abcdef", str);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacehexp("0123456789abcdef", obj, str);
	else
	{
		ft_putchar('0', obj);
		ft_putchar('x', obj);
		r = va_arg(obj->ap, unsigned long);
		if (r != 0 || !(ft_strlen_find_dot(str)))
			ft_putnbr_hex(r, "0123456789abcdef", obj);
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
