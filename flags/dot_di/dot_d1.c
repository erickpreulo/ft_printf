/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_d1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:21:06 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 20:32:30 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_d1_1(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->s = ft_itoa(va_arg(obj->ap, int));
	dotd->bf = ft_strlen_bfdot(str);
	dotd->af = ft_strlen_afdot(str, dotd->s);
	dotd->b = ft_strlen(dotd->bf);
	dotd->a = ft_strlen(dotd->af);
}

void	dot_d1(t_dot *dotd, t_obj *obj, const char *str)
{
	dotd->cpya = -1;
	dotd->cpyb = -1;
	if (dotd->buff[-1] == '*' && dotd->buff[1] == '*')
	{
		dotd->b = va_arg(obj->ap, int);
		dotd->a = va_arg(obj->ap, int);
		dotd->s = ft_itoa(va_arg(obj->ap, int));
	}
	else if (dotd->buff[-1] == '*')
	{
		dotd->b = va_arg(obj->ap, int);
		dotd->s = ft_itoa(va_arg(obj->ap, int));
		dotd->cpyb *= dotd->b;
	}
	else if (dotd->buff[1] == '*')
	{
		dotd->a = va_arg(obj->ap, int);
		dotd->s = ft_itoa(va_arg(obj->ap, int));
		dotd->cpya *= dotd->a;
	}
	else
		dot_d1_1(dotd, obj, str);
	dotd->l = ft_strlen(dotd->s);
}

void	dot_d2_1(t_dot *dotd)
{
	if (dotd->b < 0)
	{
		dotd->cpyb *= dotd->b;
		dotd->bf = ft_newstr(dotd->cpyb);
		ft_memset(dotd->bf, ' ', dotd->cpyb);
	}
	else
	{
		dotd->bf = ft_newstr(dotd->b);
		ft_memset(dotd->bf, ' ', dotd->b);
	}
}
