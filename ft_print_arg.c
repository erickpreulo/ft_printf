/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:46:19 by egomes            #+#    #+#             */
/*   Updated: 2021/03/26 13:24:02 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printc(va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	ft_putchar(c);
}

void		prints(va_list ap)
{
	char	*s;
	int		i;

	s = va_arg(ap, char *);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void		printd(va_list ap)
{
	int i;

	i = va_arg(ap, int);
	ft_putnbr(i);
}
