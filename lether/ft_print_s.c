/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:09:04 by egomes            #+#    #+#             */
/*   Updated: 2021/04/26 15:09:01 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints(const char *str, t_obj *obj)
{
	if (str[0] == '*' || (str[0] != 's' && str[1] == '*') || str[2] == '*')
		ft_printas_s(obj, str);
	else if (ft_strlen_find_dot(str) && str[0] != '*')
		ft_printdot_s(str, obj);
	else if (str[-1] == '-')
		ft_printendspaces(obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspaces(obj);
	else if (str[0] == 's')
	{
		obj->buff = va_arg(obj->ap, char *);
		if (obj->buff == NULL)
			obj->buff = "(null)";
		ft_putchars(obj->buff, obj);
	}
}
