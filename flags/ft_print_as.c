/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:13 by egomes            #+#    #+#             */
/*   Updated: 2021/04/10 22:21:55 by egomes           ###   ########.fr       */
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
		{
			ft_putchars(ass->buff, obj);
			ft_putchars(ass->s, obj);
		}
		else
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

void	as_d(t_as *asd, const char *str, t_obj *obj)
{
	asd->buff = ft_newstr(asd->i);
	ft_memset(asd->buff, ' ', asd->i);
	if (str[1] == '-')
		ft_memcpy(asd->buff, asd->s, 0, asd->size);
	else if (str[1] == '+')
	{
		ft_memset(asd->buff, '+', 1);
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size + 1, asd->size);
	}
	else if (ft_isneg(asd->s))
	{
		ft_memset(asd->buff, '0', asd->i);
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
		ft_neg(asd->buff);
	}
	else
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
	ft_putchars(asd->buff, obj);
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
	{
		asd.buff = ft_newstr(asd.cpy);
		ft_memset(asd.buff, ' ', asd.cpy);
		ft_memcpy(asd.buff, asd.s, 0, asd.size);
		ft_putchars(asd.buff, obj);
	}
	else
		ft_putchars(asd.s, obj);
	free(asd.buff);
	free(asd.s);
}

void    ft_printas_u(t_obj *obj, const char *str)
{
	t_as asd;

	asd.i = va_arg(obj->ap, int);
	asd.s = ft_itoa(va_arg(obj->ap, unsigned int));
	asd.cpy = -1;
	asd.size = ft_strlen(asd.s);
	asd.cpy *= asd.i;
	if (asd.i >= asd.size)
		as_d(&asd, str, obj);
	else if (asd.cpy >= asd.size)
	{
		asd.buff = ft_newstr(asd.cpy);
		ft_memset(asd.buff, ' ', asd.cpy);
		ft_memcpy(asd.buff, asd.s, 0, asd.size);
		ft_putchars(asd.buff, obj);
	}
	else
		ft_putchars(asd.s, obj);
	free(asd.buff);
	free(asd.s);
}