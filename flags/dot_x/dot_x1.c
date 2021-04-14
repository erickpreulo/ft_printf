/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_x1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:14:52 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 10:32:19 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_x1_1(t_dot *dotd, t_obj *obj, const char *str, char *hex)
{
	dotd->arg = va_arg(obj->ap, unsigned int);
	ft_cpy_hexs(dotd->arg, hex, obj);
	dotd->s = obj->hex;
	dotd->bf = ft_strlen_bfdot(str);
	dotd->af = ft_strlen_afdot(str, dotd->s);
	dotd->bu = ft_strlen(dotd->bf);
	dotd->au = ft_strlen(dotd->af);
}

void	dot_x1(t_dot *dotd, t_obj *obj, const char *str, char *hex)
{
	obj->hex = ft_newstr(8);
	dotd->cpyau = -1;
	dotd->cpybu = -1;
	if (dotd->buff[-1] == '*' && dotd->buff[1] == '*')
	{
		dotd->bu = va_arg(obj->ap, int);
		dotd->au = va_arg(obj->ap, int);
        dotd->arg = va_arg(obj->ap, unsigned int);
		ft_cpy_hexs(dotd->arg, hex, obj);
	}
	else if (dotd->buff[-1] == '*')
	{
		dotd->bu = va_arg(obj->ap, int);
		dotd->arg = va_arg(obj->ap, unsigned int);
		ft_cpy_hexs(dotd->arg, hex, obj);
		dotd->cpybu *= dotd->bu;
	}
	else if (dotd->buff[1] == '*')
	{
		dotd->au = va_arg(obj->ap, int);
		dotd->arg = va_arg(obj->ap, unsigned int);
		ft_cpy_hexs(dotd->arg, hex, obj);
		dotd->cpyau *= dotd->au;
	}
	else
		dot_x1_1(dotd, obj, str, hex);
    dotd->s = obj->hex;
	dotd->lu = obj->hexleng;
}
