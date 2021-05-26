/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:05:30 by egomes            #+#    #+#             */
/*   Updated: 2021/05/26 12:01:56 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printspace(t_obj *obj)
{
	char	*buff;
	char	*s;

	s = ft_itoa(va_arg(obj->ap, int));
	obj->sizes = ft_strlen(s);
	if (obj->size > obj->sizes)
	{
		buff = ft_newstr(obj->size - obj->sizes);
		ft_memset(buff, ' ', (obj->size - obj->sizes));
		ft_putchars(buff, obj);
		ft_putchars(s, obj);
		free(buff);
		free(s);
	}
	else
	{
		ft_putchars(s, obj);
		free(s);
	}
}

void	spahex(t_obj *obj)
{
	ft_memset(obj->buff, ' ', obj->size);
	ft_memcpy(obj->buff, obj->hex, obj->size - obj->counthex,
		obj->counthex);
	ft_neg(obj->buff);
	ft_putchars(obj->buff, obj);
}

void	as_s3_2(t_as *ass, t_obj *obj, const char *str)
{
	if (obj->trash < ass->size && ass->i > ass->size
		&& (str[obj->i + 1] >= '0' && str[obj->i + 1] <= '9'))
	{
		if (obj->trash < 0)
			ft_putchars(ass->s, obj);
		else
		{
			ft_memcpy(ass->buff, ass->s, 0, obj->trash);
			ft_putchars(ass->buff, obj);
		}
	}
	else if (ass->cpy >= ass->size || ass->i >= ass->size)
	{
		if (obj->trash < ass->size && obj->trash >= 0)
			ft_memcpy(ass->buff, ass->s, 0, obj->trash);
		else
			ft_memcpy(ass->buff, ass->s, 0, ass->size);
		ft_putchars(ass->buff, obj);
	}
	else if (ass->cpy < ass->size && obj->trash >= 0)
		as_s3_2_1(ass, obj);
	else
		ft_putchars(ass->s, obj);
}

void	as_s3_5(t_as *ass, t_obj *obj)
{
	if (ass->i >= ass->size && obj->trash < 0)
	{
		ft_memcpy(ass->buff, ass->s, ass->i - ass->size, ass->size);
		ft_putchars(ass->buff, obj);
	}
	else if (obj->trash < 0)
		ft_putchars(ass->s, obj);
	else if (obj->trash > ass->i)
	{
		ft_memcpy(ass->buff, ass->s, 0, obj->trash);
		ft_putchars(ass->buff, obj);
	}
	else
	{
		if (ass->i >= obj->trash && obj->trash < ass->size)
			ft_memcpy(ass->buff, ass->s, ass->i - obj->trash, obj->trash);
		else if (ass->i >= ass->size)
			ft_memcpy(ass->buff, ass->s, ass->i - ass->size, ass->size);
		ft_putchars(ass->buff, obj);
	}
}

void	dot_s_1(t_dot *dots, t_obj *obj)
{
	if (dots->a == 0 && dots->b == 0)
		ft_putchars(dots->bf, obj);
	else
	{
		ft_memcpy(dots->af, dots->s, 0, dots->a);
		ft_putchars(dots->af, obj);
	}
}
