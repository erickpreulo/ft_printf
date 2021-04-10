/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:11:25 by egomes            #+#    #+#             */
/*   Updated: 2021/04/09 20:55:32 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printx(const char *str, t_obj *obj)
{
	char	*s;
	int	i;

	s = ft_itoa(va_arg(obj->ap, unsigned int));
	i = ft_strlen(s);
	if (ft_strlen_find_dot(str))
		ft_printdot_hex(s, str, "0123456789abcdef", obj);
	else if (ft_isneg(s))
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef", obj);
	else if (str[-1] == '-')
		ft_printendspacehex(i, s, "0123456789abcdef", obj);
	else if (obj->size > i && str[0] == '0')
		ft_print0hex(i, (obj->size - 1), s, "0123456789abcdef", obj);
	else if (obj->size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehex(i, s, "0123456789abcdef", obj);
	else if (str[0] == 'x')
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef", obj);
	free(s);
}
