/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:02 by egomes            #+#    #+#             */
/*   Updated: 2021/04/03 12:30:07 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot(char *s, const char *str, t_obj *obj)
{
	char *bf;
	char *af;
	int l;
	int a;
	int b;
	char *neg;

	l = ft_strlen(s);
	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdots(str, s);
	b = ft_strlen(bf);
	a = ft_strlen(af);
	if (str[-1] == '-')
	{
		if (a >= b)
		{
			ft_memcpy(af, s, a - l, l);
			if (ft_isneg(s))
			{
				ft_negdi(af);
				neg = ft_newstr(a + 1);
				ft_memcpyneg(neg, af, a);
				ft_putchars(neg, obj);
				free(neg);
			}
			else
				ft_putchars(af, obj);
		}
		else if (a < b)
		{
			if (a != 0 && a > l)
			{
				ft_memcpy(af, s, a - l, l);
				if (ft_isneg(s))
				{
					ft_negdi(af);
					neg = ft_newstr(a + 1);
					ft_memcpyneg(neg, af, a);
					ft_memcpy(bf, neg, 0, a + 1);
					free(neg);
				}
				else
					ft_memcpy(bf, af, 0, a);
			}	
			else
				ft_memcpy(bf, s, 0, l);
			ft_putchars(bf, obj);
		}
	}
	else if (a >= b)
	{
		ft_memcpy(af, s, a - l, l);
		if (ft_isneg(s))
		{
			ft_negdi(af);
			neg = ft_newstr(a + 1);
			ft_memcpyneg(neg, af, a);
			ft_putchars(neg, obj);
			free(neg);
		}
		else
			ft_putchars(af, obj);
	}
	else if (a < b)
	{
		if (a != 0)
		{
			ft_memcpy(af, s, a - l, l);
			ft_memcpy(bf, af, b - a, a);
		}
		else
			ft_memcpy(bf, s, b - l, l);
		if (ft_isneg(s))
			ft_negdi(bf);
		ft_putchars(bf, obj);
	}
	free(bf);
	free(af);
}

void	ft_printdots(char *s, const char *str, t_obj *obj)
{
	char *bf;
	char *af;
	int l;
	int a;
	int b;

	l = ft_strlen(s);
	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdots(str, s);
	b = ft_strlen(bf);
	a = ft_strlen(af);
	if (a < l)
		l = a;
	if (str[-1] == '%' && str[0] == '.' && str[1] != 's')
	{
		if (a > 0 && l > 0)
		{
			(ft_memcpy(af, s, a - l, l));
			ft_putchars(af, obj);
		}
		else
			obj->printed = 0;
	}
	else if (str[-1] == '-')
	{
		if (a >= b)
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
	af = ft_strlen_afdots(str, s);
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
