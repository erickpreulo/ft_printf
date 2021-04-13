/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:29:33 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 12:31:27 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
