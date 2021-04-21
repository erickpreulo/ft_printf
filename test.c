/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:02:01 by egomes            #+#    #+#             */
/*   Updated: 2021/04/19 16:02:57 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
    ft_printf("*.7 -5|%*.7d|\n", -5, 123);
    printf("*.7 -5|%*.7d|\n", -5, 123);
	ft_printf("*.7 -15|%*.7x|\n", 15, 123456);
    printf("*.7 -15|%*.7x|\n", 15, 123456);
	ft_printf("7.* -5|%7.*d|\n", -5, -123);
    printf("7.* -5|%7.*d|\n", -5, -123);
    /*ft_printf("meu c: c = |%c*| -5 = |%-10c| 5 = |%*c| *5 = | -%*c* -%-*c* |\n\n", '2', '0', 10, '1', -2, 0, 2, 0);
    printf("    c: c = |%c*| -5 = |%-10c| 5 = |%*c| *5 = | -%*c* -%-*c* |\n\n", '2', '0', 10, '1', -2, 0, 2, 0);
    ft_printf("meu s: s = |%s| -5 = |%-5s| 5 = |%5s| 15.10 = |%.6s| * = |%*s %*s |\n\n", "aqui", "aqui", "aqui", "aqui", 10, "aqui", 10, "aqui");
    printf("    s: s = |%s| -5 = |%-5s| 5 = |%5s| 15.10 = |%.6s| * = |%*s %*s |\n\n", "aqui", "aqui", "aqui", "aqui", 10, "aqui", 10, "aqui");
    ft_printf("meu d: d = |%d| 05 = |%05d| -5 = |%-5d| 5 = |%5d| 7.0 = |%7.0d| * = |%+*d|\n\n", -42, -42, -42, -42, 12345678, 12, 42);
    printf("    d: d = |%d| 05 = |%05d| -5 = |%-5d| 5 = |%5d| 7.0 = |%7.0d| * = |%+*d|\n\n", -42, -42, -42, -42, 12345678, 12, 42);
    ft_printf("meu i: i = |%i| 05 = |%05i| -5 = |%-5i| 5 = |%5i| 8.6 = |%8.6i|\n", -42, -42, -42, -42, 42);
    printf("    i: i = |%i| 05 = |%05i| -5 = |%-5i| 5 = |%5i| 8.6 = |%8.6i|\n\n", -42, -42, -42, -42, 42);
    ft_printf("meu u: u = |%u| 05 = |%02u| -5 = |%-5u| 5 = |%5u| 8.6 = |%8.6u|\n", -42, -42, 42, 42, 42);
    printf("    u: u = |%u| 05 = |%02u| -5 = |%-5u| 5 = |%5u| 8.6 = |%8.6u|\n\n", -42, -42, 42, 42, 42);
    ft_printf("meu x: x = |%x| 05 = |%05x| -5 = |%-5x| 5 = |%5x| 20.10 = |%20.10x|\n", -42, 42, -12342, 42, -42);
    printf("    x: x = |%x| 05 = |%05x| -5 = |%-5x| 5 = |%5x| 20.10 = |%20.10x|\n\n", -42, 42, -12342, 42, -42);
    ft_printf("meu X: X = |%X| 05 = |%010X| -5 = |%-5X| 5 = |%5X| 20.10 = |%-10.0X|\n", 42, 42, 123456789, 42, -142);
    printf("    X: X = |%X| 05 = |%010X| -5 = |%-5X| 5 = |%5X| 20.10 = |%-10.0X|\n\n", 42, 42, 123456789, 42, -142);
    ft_printf("meu p: p = |%p| -5 = |%-5p| 5 = |%5p|\n", (void *)42, (void *)42, (void *)42);
    printf("    p: p = |%p| -5 = |%-5p| 5 = |%5p|\n\n", (void *)42, (void *)42, (void *)42);*/
}
/*
void	as_s2(t_as *ass, const char *str, t_obj *obj)
{
	while (str[obj->i] != '.')
		obj->i++;
	ass->a = ft_atoi(&str[obj->i + 1]);
	if (ass->a < ass->size)
	{
		ass->buff = ft_newstr(ass->i);
		ft_memset(ass->buff, ' ', ass->i);
	}
	else if (str[2] == 's' || str[2] == '0')
	{
		ass->buff = ft_newstr(ass->i);
		ft_memset(ass->buff, ' ', ass->i);
	}
	else if (ass->i > ass->size)
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
		ass->buff = ft_newstr(ass->size);
		ft_memset(ass->buff, ' ', ass->size);
	}
}

void	as_s3_1(t_as *ass, t_obj *obj)
{
	
	if (ass->cpy > 0)
		ft_putchars(ass->s, obj);
	else if (ass->i <= ass->size)
		ft_putchars(ass->s, obj);
	else
	{
		ft_memcpy(ass->buff, ass->s, ass->i - ass->size, ass->size);
		ft_putchars(ass->buff, obj);
	}
}

void	as_s3_2(t_as *ass, t_obj *obj, const char *str)
{
	while (str[obj->i] != '.')
		obj->i++;
	ass->a = ft_atoi(&str[obj->i + 1]);
	if (ass->a < ass->size)
	{
		ft_memcpy(ass->buff, ass->s, 0, ass->a);
		ft_putchars(ass->buff, obj);
	}
	else if (ass->a >= ass->size)
		ft_putchars(ass->s, obj);
	else if (ass->cpy > 0)
		ft_putchars(ass->s, obj);
	else if (ass->i >= ass->size)
		ft_putchars(ass->s, obj);
	else
	{
		ft_memcpy(ass->buff, ass->s, 0, ass->i);
		ft_putchars(ass->buff, obj);
	}
}

void	as_s3(t_as *ass, const char *str, t_obj *obj)
{
	if (ass->i == 0)
		ft_putchars(ass->buff, obj);
	else if (str[1] == '.' || str[2] == '.')
		as_s3_2(ass, obj, str);
	else if (str[1] == '*')
		as_s3_1(ass, obj);
	else if (str[-1] == '-' || ass->cpy > 0)
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
	if (ft_strlen_find_dot(str) && str[0] != '.' && (str[0] != '*' && str[-1] != '*'))
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
}*/
