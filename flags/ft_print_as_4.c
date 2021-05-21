/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:28:57 by egomes            #+#    #+#             */
/*   Updated: 2021/05/21 12:01:13 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	a(t_as *ass, t_obj *obj, const char *str)
{
	if (ft_findless(str))
	{
		ft_memcpy(ass->bf, ass->s, 0, ass->size);
		ft_putchars(ass->bf, obj);
	}
	else if (ass->b > ass->cpy || (ass->b > ass->size && ass->i < 0))
	{
		ft_memcpy(ass->bf, ass->s, ass->b - ass->size, ass->size);
		ft_putchars(ass->bf, obj);
	}
	else
		ft_putchars(ass->s, obj);
}

void	b(t_as *ass, t_obj *obj, const char *str)
{
	if (ft_findless(str))
		ft_memcpy(ass->bf, ass->s, 0, ass->i);
	else
		ft_memcpy(ass->bf, ass->s, ass->b - ass->i, ass->i);
	ft_putchars(ass->bf, obj);
}

void	c(t_as *ass, t_obj *obj, const char *str)
{
	if (ass->b > ass->size)
	{
		if (ft_findless(str))
			ft_memcpy(ass->bf, ass->s, 0, ass->size);
		else
			ft_memcpy(ass->bf, ass->s, ass->b - ass->size, ass->size);
		ft_putchars(ass->bf, obj);
	}
	else
		ft_putchars(ass->s, obj);
}

void	as_s3_4(t_as *ass, t_obj *obj, const char *str)
{
	ass->bf = ft_strlen_bfdot(str);
	ass->b = ft_strlen(ass->bf);
	if (ass->b > ass->i && ass-> i > ass->size)
	{
		if (ft_findless(str))
			ft_memcpy(ass->bf, ass->s, 0, ass->size);
		else
			ft_memcpy(ass->bf, ass->s, ass->b - ass->size, ass->size);
		ft_putchars(ass->bf, obj);
	}
	else if (ass->cpy > 0)
		a(ass, obj, str);
	else if (ass->b > ass->i && ass->i < ass->size)
		b(ass, obj, str);
	else if (ass->b < ass->i && ass->i > ass->size)
		c(ass, obj, str);
	else if (ass->b < ass->i && ass->i < ass->size)
	{
		ass->j = 0;
		while (ass->j < ass->i)
			ft_putchar(ass->s[ass->j++], obj);
	}
	free(ass->bf);
}
