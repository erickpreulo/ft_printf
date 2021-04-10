/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:12:49 by egomes            #+#    #+#             */
/*   Updated: 2021/04/09 22:33:55 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printp(const char *str, t_obj *obj)
{
	unsigned int	s;
	int	i;
	char *buff;

	s = va_arg(obj->ap, unsigned int);
	buff = ft_itoap(s);
	i = ft_strlen(buff);
	if (obj->size < 0)
		obj->size *= -1;
	if (obj->size > i && (str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacehexp(i, (obj->size - 2), s, "0123456789abcdef", obj);
	else if (obj->size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehexp(i, (obj->size - 2), s, "0123456789abcdef", obj);
	else
	{
		ft_putchar('0', obj);
		ft_putchar('x', obj);
		ft_putnbr_hex(s, "0123456789abcdef", obj);
	}
	free(buff);
}
