/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:02 by egomes            #+#    #+#             */
/*   Updated: 2021/05/19 14:15:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot_di(const char *str, t_obj *obj)
{
	t_dot	dotd;

	dotd.buff = str;
	while (*dotd.buff != '.')
		dotd.buff++;
	dot_d1(&dotd, obj, str);
	if (dotd.buff[-1] == '*' && dotd.buff[1] == '*')
		dot_d2(&dotd, obj, str);
	else if (dotd.buff[-1] == '*')
		dot_d3(&dotd, obj, str);
	else if (dotd.buff[1] == '*')
		dot_d4(&dotd, obj, str);
	else if (ft_findless(str))
		dot_d5(&dotd, obj);
	else if (dotd.a == 0 && dotd.b == 0 && ft_atoi(dotd.s) > 0)
		dot_d8(&dotd, obj);
	else if (dotd.a >= dotd.b)
		dot_d6(&dotd, obj);
	else if (dotd.a < dotd.b)
		dot_d7(&dotd, obj);
	free(dotd.s);
}

void	dot_s_2(t_dot *dots, t_obj *obj)
{
	if (dots->a > dots->b)
	{
		ft_memcpy(dots->bf, dots->s, 0, dots->l);
		ft_putchars(dots->bf, obj);
	}
	else if (dots->a < dots->b)
	{
		if (dots->a != 0)
			ft_memcpy(dots->bf, dots->s, 0, dots->l);
		ft_putchars(dots->bf, obj);
	}
}

void	dot_s_3(t_dot *dots, t_obj *obj)
{
	if (dots->a != 0 && dots->b > dots->l)
		ft_memcpy(dots->bf, dots->s, dots->b - dots->l, dots->l);
	ft_putchars(dots->bf, obj);
}

void	dot_s(t_dot *dots, const char *str, t_obj *obj)
{
	if (dots->a <= dots->l)
		dots->l = dots->a;
	if (dots->b == 0 && dots->a > dots->l)
		ft_putchars(dots->s, obj);
	else if (str[-1] == '-')
		dot_s_2(dots, obj);
	else if (dots->a >= dots->b && dots->a <= dots-> l)
	{
		if (dots->a == 0 && dots->b == 0)
			ft_putchars(dots->bf, obj);
		else
		{
			ft_memcpy(dots->af, dots->s, 0, dots->a);
			ft_putchars(dots->af, obj);
		}
	}
	else if (dots->a < dots->b)
		dot_s_3(dots, obj);
	else if (dots->l > 0 && dots->b > dots->l)
	{
		ft_memcpy(dots->bf, dots->s, dots->b - dots->l, dots->l);
		ft_putchars(dots->bf, obj);
	}
	else if (dots->a > dots->b && dots->a > dots->l && dots->l > 0)
		ft_putchars(dots->s, obj);
	else
		ft_putchars(dots->bf, obj);
}

void	ft_printdot_s(const char *str, t_obj *obj)
{
	t_dot	dots;

	dots.s = va_arg(obj->ap, char *);
	dots.scpy = dots.s;
	if (dots.s == NULL)
		dots.s = "(null)";
	dots.l = ft_strlen(dots.s);
	dots.bf = ft_strlen_bfdot(str);
	dots.af = ft_strlen_afdot(str, dots.s, obj);
	dots.b = ft_strlen(dots.bf);
	dots.a = ft_strlen(dots.af);
	dots.la = dots.l;
	dot_s(&dots, str, obj);
	free(dots.bf);
	free(dots.af);
}
