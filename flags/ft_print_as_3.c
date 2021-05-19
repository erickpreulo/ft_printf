/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:28:57 by egomes            #+#    #+#             */
/*   Updated: 2021/05/19 16:31:55 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printas_u(t_obj *obj, const char *str)
{
	t_as	asd;

	asd.i = va_arg(obj->ap, int);
	asd.s = ft_itoap(va_arg(obj->ap, unsigned int));
	asd.size = ft_strlen(asd.s);
	asd.cpy = -1;
	asd.cpy *= asd.i;
	if (asd.i >= asd.size)
		as_d(&asd, str, obj);
	else if (asd.cpy >= asd.size)
		as_d2(&asd, str, obj);
	else
		ft_putchars(asd.s, obj);
	free(asd.s);
}

void	as_c(t_as *asc)
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

void	ft_printas_pc(t_as *asc, t_obj *obj, const char *str)
{
	asc->cpy = -1;
	asc->i = va_arg(obj->ap, int);
	asc->c = '%';
	as_c(asc);
	if (asc->i == 0)
		ft_putchar(asc->c, obj);
	else if (str[-1] == '-' || asc->cpy > 0)
	{
		ft_putchar(asc->c, obj);
		ft_putchars(asc->buff, obj);
	}
	else if (asc->i > 0)
	{
		ft_putchars(asc->buff, obj);
		ft_putchar(asc->c, obj);
	}
	free(asc->buff);
}

void	ft_printas_c(t_as *asc, t_obj *obj, const char *str)
{
	asc->cpy = -1;
	asc->i = va_arg(obj->ap, int);
	asc->c = (char)(va_arg(obj->ap, int));
	as_c(asc);
	if (asc->i == 0)
		ft_putchar(asc->c, obj);
	else if (str[-1] == '-' || asc->cpy > 0)
	{
		ft_putchar(asc->c, obj);
		ft_putchars(asc->buff, obj);
	}
	else if (asc->i > 0)
	{
		ft_putchars(asc->buff, obj);
		ft_putchar(asc->c, obj);
	}
	free(asc->buff);
}

void	as_s1(t_as *ass, t_obj *obj)
{
	ass->cpy *= ass->i;
	ass->buff = ft_newstr(ass->cpy);
	if (obj->trash > ass->cpy && obj->trash <= ass->size && obj->trash > 0)
		ft_memset(ass->buff, ' ', obj->trash);
	else
		ft_memset(ass->buff, ' ', ass->cpy);

}

void	as_s3_3(t_as *ass, t_obj *obj)
{
	if (ass->i > ass->size || obj->trash < 0)
	{
		ft_memcpy(ass->buff, ass->s, ass->i - ass->size, ass->size);
		ft_putchars(ass->buff, obj);
	}
	else
		ft_putchars(ass->s, obj);
}
