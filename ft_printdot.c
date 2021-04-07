/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:02 by egomes            #+#    #+#             */
/*   Updated: 2021/04/07 14:55:15 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot(const char *str, t_obj *obj)
{
	char *bf;
	char *af;
	int l;
	int a;
	int b;
	char *neg;
	char *s;
	const char *buff;
	int cpya;
	int cpyb;

	cpya = -1;
	cpyb = -1;
	buff = str;
	while (*buff != '.')
		buff++;
	if (buff[-1] == '*' && buff[1] == '*')
	{
		b = va_arg(obj->ap, int);
		a = va_arg(obj->ap, int);
		s = ft_itoa(va_arg(obj->ap, int));
	}
	else if (buff[-1] == '*')
	{
		b = va_arg(obj->ap, int);
		s = ft_itoa(va_arg(obj->ap, int));
		if (b < 0)
			cpyb *= b;
	}
	else if (buff[1] == '*')
	{
		a = va_arg(obj->ap, int);
		s = ft_itoa(va_arg(obj->ap, int));
		if (a < 0)
			cpya *= a;
	}
	else
	{
		s = ft_itoa(va_arg(obj->ap, int));
		bf = ft_strlen_bfdot(str);
		af = ft_strlen_afdot(str, s);
		b = ft_strlen(bf);
		a = ft_strlen(af);
	}
	l = ft_strlen(s);
	if (buff[-1] == '*' && buff[1] == '*')
	{
		if (b < 0)
		{
			cpyb *= b;
			bf = ft_newstr(cpyb);
			ft_memset(bf, ' ', cpyb);
		}
		else
		{
			bf = ft_newstr(b);
			ft_memset(bf, ' ', b);
		}
		if (a < 0)
		{
			cpya *= a;
			if (!(ft_isneg(s)))
				af = ft_newstr(cpya);
			else
			{
				af = ft_newstr(cpya + 1);
				cpya += 1;
			}
		}
		else
		{
			if (!(ft_isneg(s)))
				af = ft_newstr(a);
			else
			{
				af = ft_newstr(a + 1);
				a += 1;
			}
		}
		ft_memset(af, '0', a);
		if (b > a && a > l)
		{
			ft_memcpy(af, s, a - l, l);
			if (ft_isneg(s))
				ft_neg(af);
			if (buff[-2] == '-')
				ft_memcpy(bf, af, 0, a);
			else
				ft_memcpy(bf, af, b - a, a);
			ft_putchars(bf, obj);
		}
		else if (cpyb > a && a > l)
		{
			ft_memcpy(af, s, a - l, l);
			if (ft_isneg(s))
				ft_neg(af);
			ft_memcpy(bf, af, 0, a);
			ft_putchars(bf, obj);
		}
		else if (b > l && a < l)
		{
			if (buff[-2] == '-')
				ft_memcpy(bf, s, 0, l);
			else
				ft_memcpy(bf, s, b - l, l);
			ft_putchars(bf, obj);
		}
		else if (cpyb > l && a < l)
		{
			ft_memcpy(bf, s, 0, l);
			ft_putchars(bf, obj);
		}
		else if (a > l)
		{
			ft_memcpy(af, s, a - l, l);
			if (ft_isneg(s))
				ft_neg(af);
			ft_putchars(af, obj);
		}
		else
			ft_putchars(s, obj);
	}
	else if (buff[-1] == '*')
	{
		bf = ft_newstr(b);
		ft_memset(bf, ' ', b);
		if (buff[1] >= '0' && buff[1] <= '9')
		{
			af = ft_strlen_afdot(str, s);
			a = ft_strlen(af);
			if (a >= b && a > l)
			{
				ft_memcpy(af, s, a - l, l);
				ft_putchars(af, obj);
			}
			else if (b > a && a > l)
			{
				ft_memcpy(af, s, a - l, l);
				if (str[-1] == '-' || str[-2] == '-' || ft_isneg(s))
					ft_memcpy(bf, af, 0, a);
				else
					ft_memcpy(bf, af, b - a, a);
				ft_putchars(bf, obj);
			}
			else if (b > a && b > l)
			{
				if (str[-1] == '-' || str[-2] == '-' || ft_isneg(s))
					ft_memcpy(bf, s, 0, l);
				else
					ft_memcpy(bf, s, b - l, l);
				ft_putchars(bf, obj);
			}
			else
				ft_putchars(s, obj);
		}
		else if (b > l)
		{
			if (buff[-2] == '-')
				ft_memcpy(bf, s, 0, l);
			else
				ft_memcpy(bf, s, b - l, l);
			ft_putchars(bf, obj);
		}
		else
			ft_putchars(s, obj);
	}
	else if (buff[1] == '*')
	{
		af = ft_newstr(a);
		ft_memset(af, '0', a);
		if (buff[-1] >= '0' && buff[-1] <= '9')
		{
			bf = ft_strlen_bfdot(str);
			b = ft_strlen(bf);
			if (a >= b && a > l)
			{
				ft_memcpy(af, s, a - l, l);
				ft_putchars(af, obj);
			}
			else if (b > a && a > l)
			{
				ft_memcpy(af, s, a - l, l);
				ft_memcpy(bf, af, b - a, a);
				ft_putchars(bf, obj);
			}
			else
				ft_putchars(s, obj);
		}
		if (a > l)
		{
			ft_memcpy(af, s, a - l, l);
			if (ft_isneg(s))
				ft_neg(af);
			ft_putchars(af, obj);
		}
		ft_putchars(s, obj);
	}
	else if (str[-1] == '-')
	{
		if (a >= b)
		{
			ft_memcpy(af, s, a - l, l);
			if (ft_isneg(s))
			{
				ft_negdi(af);
				neg = ft_newstr(a);
				ft_memcpynegstay(neg, af, a);
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
					neg = ft_newstr(a);
					ft_memcpynegstay(neg, af, a);
					ft_memcpy(bf, neg, 0, a);
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
	else if (a == 0 && b == 0 && ft_atoi(s) > 0)
		ft_putchars(s, obj);
	else if (a >= b)
	{
		ft_memcpy(af, s, a - l, l);
		if (ft_isneg(s))
		{
			ft_negdi(af);
			neg = ft_newstr(a);
			ft_memcpynegstay(neg, af, a);
			ft_putchars(neg, obj);
			free(neg);
		}
		else
			ft_putchars(af, obj);
	}
	else if (a < b)
	{
		if (a != 0 && a >= l)
		{
			if (ft_isneg(s))
			{
				ft_memcpy(af, s, a - l, l);
				ft_negdi(af);
				neg = ft_newstr(a);
				ft_memcpynegstay(neg, af, a);
				ft_memcpy(bf, neg, b - a, a);
				free(neg);
			}
			else
			{
				ft_memcpy(af, s, a - l, l);
				ft_memcpy(bf, af, b - a, a);
			}
		}
		else if (ft_atoi(s) == 0)
			ft_memcpy(bf, 0, 0, 0);
		else if (a < l)
			ft_memcpy(bf, s, b - l, l);
		else if (ft_isneg(s))
			ft_negdi(bf);
		ft_putchars(bf, obj);
	}
	free(s);
	free(bf);
	free(af);
}

void	ft_printdots(const char *str, t_obj *obj)
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
