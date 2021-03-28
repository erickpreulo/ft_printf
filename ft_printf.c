/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:04:59 by egomes            #+#    #+#             */
/*   Updated: 2021/03/27 19:52:55 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print(va_list ap, const char *str)
{
	int i;

	i = 0;
	if (str[i] == 'c')
		printc(ap);
	if (str[i] == '0')
		prints(ap, ft_atoi(str));
	if (str[i] == 'd' || str[i] == 'i')
		printdi(ap);
	if (str[i] == 'u')
		printu(ap);
	if (str[i] == 'x')
		printx(ap);
	if (str[i] == 'X')
		printX(ap);
	if (str[i] == 'p')
		printp(ap);
	if (str[i] == '%')
		ft_putchar('%');
}

int			ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		j;

	i = ft_strlen(str);
	va_start(ap, str);
	j = 0;
	while (j <= i)
	{
		if (str[j] == '%')
		{ 
			j++;
			print(ap, &str[j]);
			j++;
		}
		ft_putchar(str[j]);
		j++;
	}
	va_end(ap);
	return (0);
}
