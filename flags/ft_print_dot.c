/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:02 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 21:16:20 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot_di(const char *str, t_obj *obj)
{
	t_dot dotd;

	dotd.buff = str;
	while (*dotd.buff != '.')
		dotd.buff++;
	dot_d1(&dotd, obj, str);
	if (dotd.buff[-1] == '*' && dotd.buff[1] == '*')
		dot_d2(&dotd, obj);
	else if (dotd.buff[-1] == '*')
		dot_d3(&dotd, obj, str);
	else if (dotd.buff[1] == '*')
		dot_d4(&dotd, obj, str);
	else if (str[-1] == '-')
		dot_d5(&dotd, obj);
	else if (dotd.a == 0 && dotd.b == 0 && ft_atoi(dotd.s) > 0)
		ft_putchars(dotd.s, obj);
	else if (dotd.a >= dotd.b && (dotd.a != 0 && dotd.b != 0))
		dot_d6(&dotd, obj);
	else if (dotd.a < dotd.b)
		dot_d7(&dotd, obj);
	free(dotd.s);
	free(dotd.bf);
	free(dotd.af);
}
void	dot_s_1(t_dot *dots, t_obj *obj)
{
	if (dots->la <= dots->a)
			dots->l = dots->a;
	else if (dots->l > 0)
	{
		(ft_memcpy(dots->af, dots->s, dots->a - dots->l, dots->l));
		ft_putchars(dots->af, obj);
	}
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

void	dot_s(t_dot *dots, const char *str, t_obj *obj)
{
	if (dots->b == 0 && dots->a >= dots->l)
	{
		ft_putchars(dots->s, obj);
	}
	if (dots->a <= dots->l)
		dots->l = dots->a;
	if (str[-1] == '%' && str[0] == '.' && str[1] != 's')
		dot_s_1(dots, obj);
	else if (str[-1] == '-')
		dot_s_2(dots, obj);
	else if (dots->a >= dots->b)
	{
		ft_memcpy(dots->af, dots->s, dots->a - dots->l, dots->l);
		ft_putchars(dots->af, obj);
	}
	else if (dots->a < dots->b)
	{

		if (dots->a != 0)
			ft_memcpy(dots->bf, dots->s, dots->b - dots->l, dots->l);
		ft_putchars(dots->bf, obj);
	}
}

void	ft_printdot_s(const char *str, t_obj *obj)
{
	t_dot dots;

	dots.s = va_arg(obj->ap, char *);
	dots.l = ft_strlen(dots.s);
	dots.bf = ft_strlen_bfdot(str);
	dots.af = ft_strlen_afdot(str, dots.s);
	dots.b = ft_strlen(dots.bf);
	dots.a = ft_strlen(dots.af);
	dots.la = dots.l;
	dot_s(&dots, str, obj);
	free(dots.bf);
	free(dots.af);
}
