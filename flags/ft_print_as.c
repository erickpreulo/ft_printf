/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:13 by egomes            #+#    #+#             */
/*   Updated: 2021/04/21 23:30:42 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	as_s2(t_as *ass, const char *str, t_obj *obj)
{
	if (str[2] == 's' || str[2] == '0')
	{
		ass->buff = ft_newstr(ass->i);
		ft_memset(ass->buff, ' ', ass->i);
	}
	else if (ass->i > (ass->size + 1))
	{
		if (obj->trash < ass->size)
		{
			ass->buff = ft_newstr(ass->i);
			ft_memset(ass->buff, ' ', ass->i);
		}
		else
		{
			ass->buff = ft_newstr(ass->i - ass->size);
			ft_memset(ass->buff, ' ', ass->i - ass->size);
		}
	}
	else
	{
		ass->buff = ft_newstr(ass->i);
		ft_memset(ass->buff, ' ', ass->i);
	}
}

void	as_s3_1(t_as *ass, t_obj *obj)
{
	if (ass->cpy > 0)
		ft_putchars(ass->s, obj);
	else if (ass->i >= ass->size)
		ft_putchars(ass->s, obj);
	else
	{
		ft_memcpy(ass->buff, ass->s, 0, ass->i);
		ft_putchars(ass->buff, obj);
	}
}

void	as_s3_2(t_as *ass, t_obj *obj)
{
	if (ass->cpy >= ass->size || ass->i >= ass->size)
	{
		if (obj->trash < ass->size && obj->trash >= 0)
			ft_memcpy(ass->buff, ass->s, 0, obj->trash);
		else
			ft_putchars(ass->s, obj);
		ft_putchars(ass->buff, obj);
	}
	else
		ft_putchars(ass->s, obj);
}

void	as_s3(t_as *ass, const char *str, t_obj *obj)
{
	while (str[obj->i] != '.')
		obj->i++;
	ass->a = ft_atoi(&str[obj->i + 1]);
	if (ass->i == 0)
		ft_putchars(ass->buff, obj);
	else if (str[1] == '*')
		as_s3_1(ass, obj);
	else if (ass->a < ass->size && str[1] == '.'
		&& (str[2] >= '0' && str[2] <= '9'))
	{
		ft_memcpy(ass->buff, ass->s, 0, ass->a);
		ft_putchars(ass->buff, obj);
	}
	else if (str[-1] == '-' || ass->cpy > 0)
		as_s3_2(ass, obj);
	else if (str[2] == 's' || str[2] == '0')
		ft_putchars(ass->buff, obj);
	else if (ass->i > 0)
	{
		if (ass->i > ass->size)
			ft_putchars(ass->buff, obj);
		ft_putchars(ass->s, obj);
	}
}

void	ft_printas_s(t_obj *obj, const char *str)
{
	t_as	ass;

	ass.i = va_arg(obj->ap, int);
	if (ft_strlen_find_dot(str) && str[0] != '.'
		&& (str[2] == '*' || str[3] == '*'))
		obj->trash = va_arg(obj->ap, int);
	ass.s = va_arg(obj->ap, char *);
	if (ass.s == NULL)
		ass.s = "(null)";
	ass.cpy = -1;
	ass.size = ft_strlen(ass.s);
	if (ass.i < 0)
		as_s1(&ass);
	else if (ass.i >= 0)
		as_s2(&ass, str, obj);
	as_s3(&ass, str, obj);
	free(ass.buff);
}
