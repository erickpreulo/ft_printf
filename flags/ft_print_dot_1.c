/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dot_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:20:44 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 10:28:03 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot_u(const char *str, t_obj *obj)
{
	t_dot dotd;

	dotd.buff = str;
	while (*dotd.buff != '.')
		dotd.buff++;
	dot_u1(&dotd, obj, str);
	if (dotd.buff[-1] == '*' && dotd.buff[1] == '*')
		dot_u2(&dotd, obj);
	else if (dotd.buff[-1] == '*')
		dot_u3(&dotd, obj, str);
	else if (dotd.buff[1] == '*')
		dot_u4(&dotd, obj, str);
	else if (str[-1] == '-')
		dot_u5(&dotd, obj);
	else if (dotd.au == 0 && dotd.bu == 0 && ft_atoi(dotd.s) > 0)
		ft_putchars(dotd.s, obj);
	else if (dotd.au >= dotd.bu && (dotd.au != 0 && dotd.bu != 0))
		dot_u6(&dotd, obj);
	else if (dotd.au < dotd.bu)
		dot_u7(&dotd, obj);
	free(dotd.s);
	free(dotd.bf);
	free(dotd.af);
}

void	ft_printdot_hex(const char *str, t_obj *obj, char *hex)
{
	t_dot dotd;
	
	dotd.buff = str;
	while (*dotd.buff != '.')
		dotd.buff++;
	dot_x1(&dotd, obj, str, hex);
	if (dotd.buff[-1] == '*' && dotd.buff[1] == '*')
		dot_x2(&dotd, obj);
	else if (dotd.buff[-1] == '*')
		dot_x3(&dotd, obj, str);
	else if (dotd.buff[1] == '*')
		dot_u4(&dotd, obj, str);
	else if (str[-1] == '-')
		dot_u5(&dotd, obj);
	else if (dotd.au >= dotd.bu && (dotd.au != 0 && dotd.bu != 0))
		dot_u6(&dotd, obj);
	else if (dotd.au < dotd.bu)
		dot_x7(&dotd, obj);
	else if (dotd.arg > 0)
		ft_putnbr_hex(dotd.arg, hex, obj);
	free(dotd.bf);
	free(dotd.af);
	free(obj->hex);
}
