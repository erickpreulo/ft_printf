/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:10:39 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 12:09:41 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printu(const char *str, t_obj *obj)
{
	char *s;

	if (ft_strlen_find_dot(str))
		ft_printdot_u(str, obj);
	else if (str[0] == '*' || str[1] == '*' || str[2] == '*')
		ft_printas_u(obj, str);
	else if (str[-1] == '-' && str[0] != '*')
		ft_printendspaceu(obj);
	else if (str[0] == '0')
		ft_print0u(obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspaceu(obj);
	else
	{
		s = ft_itoap(va_arg(obj->ap, unsigned int));
		ft_putchars(s, obj);
		free(s);
	}
}
