/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:02 by egomes            #+#    #+#             */
/*   Updated: 2021/04/10 23:43:03 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot_di(const char *str, t_obj *obj)
{
	t_dot dotd;

	dotd.buff = str;
	while (*dotd.buff != '.')
		dotd.buff++;
	dot_d1(&dotd, obj, str);
	if (dotd.buff[-1] == '*' && dotd.buff[1] == '*')
		dot_d2(&dotd, obj);
	else if (dotd.buff[-1] == '*')
		dot_d3(&dotd, obj, str);
	else if (dotd.buff[1] == '*')
		dot_d4(&dotd, obj, str);
	else if (str[-1] == '-')
		dot_d5(&dotd, obj);
	else if (dotd.a == 0 && dotd.b == 0 && ft_atoi(dotd.s) > 0)
		ft_putchars(dotd.s, obj);
	else if (dotd.a >= dotd.b && (dotd.a != 0 && dotd.b != 0))
		dot_d6(&dotd, obj);
	else if (dotd.a < dotd.b)
		dot_d7(&dotd, obj);
	free(dotd.s);
	free(dotd.bf);
	free(dotd.af);
}

void	ft_printdot_u(const char *str, t_obj *obj)
{
	t_dot dotd;

	dotd.buff = str;
	while (*dotd.buff != '.')
		dotd.buff++;
	dot_u1(&dotd, obj, str);
	if (dotd.buff[-1] == '*' && dotd.buff[1] == '*')
		dot_u2(&dotd, obj);
	else if (dotd.buff[-1] == '*')
		dot_u3(&dotd, obj, str);
	else if (dotd.buff[1] == '*')
		dot_u4(&dotd, obj, str);
	else if (str[-1] == '-')
		dot_u5(&dotd, obj);
	else if (dotd.au == 0 && dotd.bu == 0 && ft_atoi(dotd.s) > 0)
		ft_putchars(dotd.s, obj);
	else if (dotd.au >= dotd.bu && (dotd.au != 0 && dotd.bu != 0))
		dot_u6(&dotd, obj);
	else if (dotd.au < dotd.bu)
		dot_u7(&dotd, obj);
	free(dotd.s);
	free(dotd.bf);
	free(dotd.af);
}

void	ft_printdot_s(const char *str, t_obj *obj)
{
	char *bf;
	char *af;
	int l;
	int a;
	int b;
	int la;
	char *s;

	s = va_arg(obj->ap, char *);
	l = ft_strlen(s);
	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdot(str, s);
	b = ft_strlen(bf);
	a = ft_strlen(af);
	la = l;
	if (b == 0 && a >= l)
	{
		ft_putchars(s, obj);
	}
	if (a <= l)
		l = a;
	if (str[-1] == '%' && str[0] == '.' && str[1] != 's')
	{
		if (la <= a)
			l = a;
		else if (l > 0)
		{
			(ft_memcpy(af, s, a - l, l));
			ft_putchars(af, obj);
		}
	}
	else if (str[-1] == '-')
	{
		if (a > b)
		{
			ft_memcpy(bf, s, 0, l);
			ft_putchars(bf, obj);
		}
		else if (a < b)
		{
			if (a != 0)
				ft_memcpy(bf, s, 0, l);
			ft_putchars(bf, obj);
		}
	}
	else if (a >= b)
	{
		ft_memcpy(af, s, a - l, l);
		ft_putchars(af, obj);
	}
	else if (a < b)
	{

		if (a != 0)
			ft_memcpy(bf, s, b - l, l);
		ft_putchars(bf, obj);
	}
	free(bf);
	free(af);
}

void	ft_printdot_hex(char *s, const char *str, char *hex, t_obj *obj)
{
	char	*bf;
	char	*af;
	char	*hexs;
	int		a;
	int		b;
	int		hl;
	
	obj->hex = ft_newstr(8);
	ft_cpy_hexs(ft_atoi(s), hex, obj);
	hexs = obj->hex;
	hl = obj->hexleng;
	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdot(str, s);
	b = ft_strlen(bf);
	a = ft_strlen(af);
	if (s[0] == '-')
	{
		if (str[-1] == '-')
		{
			if (a >= b)
			{
			ft_memcpy(af, hexs, a - hl, hl);
			ft_putchars(af, obj);
			}
			else if (a < b)
			{
			ft_memcpy(af, hexs, a - hl, hl);
			if (a == 0)
			ft_memcpy(bf, hexs, 0, hl);
			else
			ft_memcpy(bf, af, 0, a);
			ft_putchars(bf, obj);
			}
		}
		else if (a >= b)
		{
			ft_memcpy(af, hexs, a - hl, hl);
			ft_putchars(af, obj);
		}
		else if (a < b)
		{
			ft_memcpy(af, hexs, a - hl, hl);
			if (a == 0)
				ft_memcpy(bf, hexs, b - hl, hl);
			else
				ft_memcpy(bf, af, b - a, a);
			ft_putchars(bf, obj);
		}
	}
	else if (str[-1] == '-')
	{
		if (a >= b)
		{
		ft_memcpy(af, hexs, a - hl, hl);
		ft_putchars(af, obj);
		}
		else if (a < b)
		{
		ft_memcpy(af, hexs, a - hl, hl);
		if (a == 0)
			ft_memcpy(bf, hexs, 0, hl);
		else
			ft_memcpy(bf, af, 0, a);
		ft_putchars(bf, obj);
		}
	}
	else if (a >= b)
	{
		ft_memcpy(af, hexs, a - hl, hl);
		ft_putchars(af, obj);
	}
	else if (a < b)
	{
			ft_memcpy(af, hexs, a - hl, hl);
		if (a == 0)
			ft_memcpy(bf, hexs, b - hl, hl);
		else
			ft_memcpy(bf, af, b - a, a);
		ft_putchars(bf, obj);
	}
	free(hexs);
	free(bf);
	free(af);
}
