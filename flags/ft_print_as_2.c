/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:28:57 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 10:56:30 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	as_p_1_1(t_as *asd)
{
	if (asd->i == asd->size || asd->cpy == asd->size)
	{
		ft_memset(asd->buff, '+', 1);
		ft_memcpy(asd->buff, asd->s, 1, asd->size);
	}
	else if (asd->i >= asd->size)
	{
		ft_memcpy(asd->buff, "+", asd->i - asd->size - 1, 1);
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
	}
	else if (asd->cpy >= asd->size)
	{
		ft_memcpy(asd->buff, "+", 0, 1);
		ft_memcpy(asd->buff, asd->s, 1, asd->size);
	}
}

void	as_p_1(t_as *asd, const char *str)
{
	if (str[-1] == '-' || str[0] == '-' || str[1] == '-')
		ft_memcpy(asd->buff, asd->s, 0, asd->size);
	else if (str[-1] == '+' || str[0] == '+')
		as_p_1_1(asd);
	else if (str[0] == '0')
	{
		ft_memset(asd->buff, '0', asd->i);
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
		ft_neg(asd->buff);
	}
	else if (asd->i >= asd->size)
		ft_memcpy(asd->buff, asd->s, asd->i - asd->size, asd->size);
	else if (asd->cpy >= asd->size)
		ft_memcpy(asd->buff, asd->s, 0, asd->size);
}

void	as_p(t_as *asd, const char *str, t_obj *obj)
{
	if ((asd->i == asd->size) && (str[-1] == '+' || str[0] == '+'))
	{
		asd->buff = ft_newstr(asd->i + 1);
		ft_memset(asd->buff, ' ', asd->i + 1);
	}
	else if (asd->i >= asd->size)
	{
		asd->buff = ft_newstr(asd->i);
		ft_memset(asd->buff, ' ', asd->i);
	}
	if ((asd->cpy == asd->size) && (str[-1] == '+' || str[0] == '+'))
	{
		asd->buff = ft_newstr(asd->cpy + 1);
		ft_memset(asd->buff, ' ', asd->cpy + 1);
	}
	else if (asd->cpy >= asd->size)
	{
		asd->buff = ft_newstr(asd->cpy);
		ft_memset(asd->buff, ' ', asd->cpy);
	}
	as_p_1(asd, str);
	ft_putchars(asd->buff, obj);
	free(asd->buff);
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

	obj->hex = ft_newstr(20);
	ft_memset(obj->hex, 'x', 2);
	ft_memset(obj->hex, '0', 1);
	obj->counthex += 2;
	asd.i = va_arg(obj->ap, int);
	ft_cpy_hexs(va_arg(obj->ap, unsigned long), hex, obj);
	asd.s = obj->hex;
	asd.size = obj->counthex;
	asd.cpy = -1;
	asd.cpy *= asd.i;
	if (asd.i > asd.size || asd.cpy > asd.size)
		as_p(&asd, str, obj);
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
