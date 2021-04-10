/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_u1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:21:06 by egomes            #+#    #+#             */
/*   Updated: 2021/04/10 23:44:50 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_u1_1(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->s = ft_itoap(va_arg(obj->ap, int));
	dotd->bf = ft_strlen_bfdot(str);
	dotd->af = ft_strlen_afdot(str, dotd->s);
	dotd->bu = ft_strlen(dotd->bf);
	dotd->au = ft_strlen(dotd->af);
}

void	dot_u1(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->cpyau = -1;
	dotd->cpybu = -1;
	if (dotd->buff[-1] == '*' && dotd->buff[1] == '*')
	{
		dotd->bu = va_arg(obj->ap, int);
		dotd->au = va_arg(obj->ap, int);
		dotd->s = ft_itoap(va_arg(obj->ap, int));
	}
	else if (dotd->buff[-1] == '*')
	{
		dotd->bu = va_arg(obj->ap, int);
		dotd->s = ft_itoap(va_arg(obj->ap, int));
		dotd->cpybu *= dotd->bu;
	}
	else if (dotd->buff[1] == '*')
	{
		dotd->au = va_arg(obj->ap, int);
		dotd->s = ft_itoap(va_arg(obj->ap, int));
		dotd->cpyau *= dotd->au;
	}
	else
		dot_u1_1(dotd, obj, str);
	dotd->lu = ft_strlen(dotd->s);
}
