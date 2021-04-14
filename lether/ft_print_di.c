/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:10:00 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 12:07:52 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printdi(const char *str, t_obj *obj)
{
	if (ft_strlen_find_dot(str))
		ft_printdot_di(str, obj);
	else if (str[0] == '*' || str[1] == '*' || str[2] == '*')
		ft_printas_di(obj, str);
	else if (str[-1] == '-')
		ft_printendspace(obj);
	else if (str[0] == '0')
		ft_print0(obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspace(obj);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_putnbr(va_arg(obj->ap, int), obj);
}