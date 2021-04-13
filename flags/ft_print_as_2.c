/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:28:57 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 12:30:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
