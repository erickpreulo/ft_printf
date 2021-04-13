/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:13 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 12:25:34 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    as_c(t_as *asc)
{
	if (asc->i < 0)
	{
		asc->cpy *= asc->i;
		asc->buff = ft_newstr(asc->cpy - 1);
		ft_memset(asc->buff, ' ', asc->cpy - 1);
	}
	else if (asc->i > 0)
	{
		asc->buff = ft_newstr(asc->i - 1);
		ft_memset(asc->buff, ' ', asc->i - 1);
	}
	else
	{
		asc->buff = ft_newstr(asc->i);
		ft_memset(asc->buff, ' ', asc->i);
	}
}

void    ft_printas_c(t_obj *obj, const char *str)
{
	t_as	asc;

	asc.cpy = -1;
	asc.i = va_arg(obj->ap, int);
	asc.c = (char)(va_arg(obj->ap, int));
	as_c(&asc);
	if (asc.i == 0)
		ft_putchar(asc.c, obj);
	else if (str[-1] == '-' || asc.cpy > 0)
	{
		ft_putchar(asc.c, obj);
		ft_putchars(asc.buff, obj);
	}
	else if (asc.i > 0)
	{
		ft_putchars(asc.buff, obj);
		ft_putchar(asc.c, obj);
	}
	free(asc.buff);
}

void	as_s1(t_as *ass)
{
	ass->cpy *= ass->i;
	if (ass->cpy > ass->size)
	{
		ass->buff = ft_newstr(ass->cpy - ass->size);
		ft_memset(ass->buff, ' ', ass->cpy - ass->size);
	}
	else
	{
		ass->buff = ft_newstr(ass->size);
		ft_memset(ass->buff, ' ', ass->size);
	}
}

void	as_s2(t_as *ass, const char *str)
{
	if (str[2] == 's' || str[2] == '0')
	{
		ass->buff = ft_newstr(ass->i);
		ft_memset(ass->buff, ' ', ass->i);
	}
	else if (ass->i > ass->size)
	{
		ass->buff = ft_newstr(ass->i - ass->size);
		ft_memset(ass->buff, ' ', ass->i - ass->size);
	}
	else
	{
		ass->buff = ft_newstr(ass->size);
		ft_memset(ass->buff, ' ', ass->size);
	}
}

void	as_s3(t_as *ass, const char *str, t_obj *obj)
{
	if (ass->i == 0)
		ft_putchars(ass->s, obj);
	else if (str[2] == 's' || str[2] == '0')
		ft_putchars(ass->buff, obj);
	else if (str[-1] == '-' || ass->cpy > 0)
	{
		if (ass->cpy > ass->size)
		{
			ft_putchars(ass->s, obj);
			ft_putchars(ass->buff, obj);
		}
		else
			ft_putchars(ass->s, obj);
	}
	else if (ass->i > 0)
	{
		if (ass->i > ass->size)
			ft_putchars(ass->buff, obj);
		ft_putchars(ass->s, obj);
	}
}

void	ft_printas_s(t_obj *obj, const char *str)
{
	t_as ass;

	ass.i = va_arg(obj->ap, int);
	ass.s = va_arg(obj->ap, char *);
	ass.cpy = -1;
	ass.size = ft_strlen(ass.s);
	if (ass.i < 0)
		as_s1(&ass);
	else if (ass.i >= 0)
		as_s2(&ass, str);
	else
	{
		ass.buff = ft_newstr(ass.i);
		ft_memset(ass.buff, ' ', ass.i);
	}
	as_s3(&ass, str, obj);
	free(ass.buff);
}
void	as_d_1(t_as *asd, const char *str)
{
	if (str[-1] == '-' || str[0] == '-' || str[1] == '-')
		ft_memcpy(asd->buff, asd->s, 0, asd->size);
	else if (str[-1] == '+' || str[0] == '+')
	{
		if (asd->i == asd->size)
		{
			ft_memset(asd->buff, '+', 1);
			ft_memcpy(asd->buff, asd->s, 1, asd->size);
		}
		else
		{
			ft_memcpy(asd->buff, "+", asd->i - asd->size - 1, 1);
			ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
		}
	}
	else if (str[0] == '0')
	{
		ft_memset(asd->buff, '0', asd->i);
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
		ft_neg(asd->buff);
	}
	else
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
}

void	as_d(t_as *asd, const char *str, t_obj *obj)
{
	if ((asd->i == asd->size) && (str[-1] == '+' || str[0] == '+'))
	{
		asd->buff = ft_newstr(asd->i + 1);
		ft_memset(asd->buff, ' ', asd->i + 1);
	}
	else
	{
		asd->buff = ft_newstr(asd->i);
		ft_memset(asd->buff, ' ', asd->i);
	}
	as_d_1(asd, str);
	ft_putchars(asd->buff, obj);
	free(asd->buff);
}

void	as_d2_1(t_as *asd, const char *str)
{
	if ((asd->cpy == asd->size) && (str[-1] == '+' || str[0] == '+'))
	{
		asd->buff = ft_newstr(asd->cpy + 1);
		ft_memset(asd->buff, ' ', asd->cpy + 1);
	}
	else
	{
		asd->buff = ft_newstr(asd->cpy);
		ft_memset(asd->buff, ' ', asd->cpy);
	}
}

void	as_d2(t_as *asd, const char *str, t_obj *obj)
{
	as_d2_1(asd, str);
	if (str[-1] == '+' || str[0] == '+')
	{
		ft_memset(asd->buff, '+', 1);
		ft_memcpy(asd->buff, asd->s, 1, asd->size);
		ft_putchars(asd->buff, obj);
	}
	else
	{
		ft_memset(asd->buff, ' ', asd->cpy);
		ft_memcpy(asd->buff, asd->s, 0, asd->size);
		ft_putchars(asd->buff, obj);
	}
	free(asd->buff);
}

void    ft_printas_di(t_obj *obj, const char *str)
{
	t_as asd;

	asd.i = va_arg(obj->ap, int);
	asd.s = ft_itoa(va_arg(obj->ap, int));
	asd.cpy = -1;
	asd.size = ft_strlen(asd.s);
	asd.cpy *= asd.i;
	if (asd.i >= asd.size)
		as_d(&asd, str, obj);
	else if (asd.cpy >= asd.size)
		as_d2(&asd, str, obj);
	else
		ft_putchars(asd.s, obj);
	free(asd.s);
}

void    ft_printas_u(t_obj *obj, const char *str)
{
	t_as asd;

	asd.i = va_arg(obj->ap, int);
	asd.s = ft_itoap(va_arg(obj->ap, unsigned int));
	asd.size = ft_strlen(asd.s);
	asd.cpy *= asd.i;
	if (asd.i >= asd.size)
		as_d(&asd, str, obj);
	else
		ft_putchars(asd.s, obj);
	free(asd.s);
}

void    ft_printas_x(t_obj *obj, char *hex, const char *str)
{
	t_as asd;

	obj->hex = ft_newstr(8);
	asd.i = va_arg(obj->ap, int);
	ft_cpy_hexs(va_arg(obj->ap, unsigned int), hex, obj);
	asd.s = obj->hex;
	asd.size = obj->hexleng;
	asd.cpy *= asd.i;
	if (asd.i >= asd.size)
		as_d(&asd, str, obj);
	else
		ft_putchars(asd.s, obj);
	free(obj->hex);
}

void    ft_printas_p(t_obj *obj, char *hex, const char *str)
{
	t_as asd;

	obj->hex = ft_newstr(10);
	ft_memset(obj->hex, 'x', 2);
	ft_memset(obj->hex, '0', 1);
	obj->counthex += 2;
	asd.i = va_arg(obj->ap, int);
	ft_cpy_hexs(va_arg(obj->ap, unsigned int), hex, obj);
	asd.s = obj->hex;
	asd.size = obj->counthex;
	asd.cpy *= asd.i;
	if (asd.i >= asd.size)
		as_d(&asd, str, obj);
	else
	{
		while (obj->i < obj->counthex)
		{
			ft_putchar(obj->hex[obj->i], obj);
			obj->i++;
		}
	}
	free(obj->hex);
}
