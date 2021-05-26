/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_as.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:13 by egomes            #+#    #+#             */
/*   Updated: 2021/05/26 11:51:31 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	as_s2(t_as *ass)
{
	ass->buff = ft_newstr(ass->i);
	ft_memset(ass->buff, ' ', ass->i);
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

void	as_s3_2_1(t_as *ass, t_obj *obj)
{
	if (obj->trash <= ass->size)
	{
		ft_memcpy(ass->buff, ass->s, 0, obj->trash);
		ft_putchars(ass->buff, obj);
	}
	else if (obj->trash > ass->size)
		ft_putchars(ass->s, obj);
	else
		ft_putchars(ass->buff, obj);
}

void	as_s3(t_as *ass, const char *str, t_obj *obj)
{
	if (str[obj->i + 1] >= '0' && str[obj->i + 1] <= '9')
		obj->trash = ft_atoi(&str[obj->i + 1]);
	if (ass->i == 0 && str[0] == '.')
		ft_putchars(ass->buff, obj);
	else if (ass->i == 0 && (ft_find_as(&str[2])) && obj->trash > ass->size)
		ft_putchars(ass->s, obj);
	else if (str[1] == '*' && str[0] != '0')
		as_s3_1(ass, obj);
	else if (str[obj->i - 1] >= '0' && str[obj->i - 1] <= '9')
		as_s3_4(ass, obj, str);
	else if (str[-1] == '-' || ass->cpy > 0)
		as_s3_2(ass, obj, str);
	else if ((obj->trash < ass->size) && str[1] == '.'
		&& ((str[obj->i + 1] >= '0' && str[obj->i + 1] <= '9')
			|| ft_find_as(&str[2])))
		as_s3_5(ass, obj);
	else if (str[2] == 's' || str[2] == '0')
		ft_putchars(ass->buff, obj);
	else if (ass->i >= 0)
		as_s3_3(ass, obj);
}

void	ft_printas_s(t_obj *obj, const char *str)
{
	t_as	ass;

	while (str[obj->i] != '.' && as_find_lether(str[obj->i]))
		obj->i++;
	ass.i = va_arg(obj->ap, int);
	if (str[obj->i] == '.' && str[obj->i - 1] == '*'
		&& ft_find_as(&str[obj->i]))
		obj->trash = va_arg(obj->ap, int);
	ass.s = va_arg(obj->ap, char *);
	if (ass.s == NULL)
		ass.s = "(null)";
	ass.cpy = -1;
	ass.size = ft_strlen(ass.s);
	if (ass.i < 0)
		as_s1(&ass, obj);
	else if (ass.i >= 0)
		as_s2(&ass);
	as_s3(&ass, str, obj);
	free(ass.buff);
}
