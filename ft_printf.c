/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:04:59 by egomes            #+#    #+#             */
/*   Updated: 2021/03/29 23:02:44 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print(va_list ap, const char *str)
{
	int size;
	int nbrsize;

	nbrsize = ft_strlen_nrb(str);
	size = ft_atoi(str);
	if (str[nbrsize] == 'c')
		printc(ap, size, str);
	if (str[nbrsize] == 's') 
		prints(ap, size, str);
	if (str[nbrsize] == 'd' || str[nbrsize] == 'i')
		printdi(ap, size, str);
	if ( str[nbrsize] == 'u')
		printu(ap, size, str);
	if (str[nbrsize] == 'x')
		printx(ap, size, str);
	if (str[nbrsize] == 'X') 
		printX(ap, size, str);
	if (str[nbrsize] == 'p')
		printp(ap, size, str);
	if (str[nbrsize] == '%')
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
			if (str[j] == '-')
				print(ap, &str[j + 1]);
			else
				print(ap, &str[j]);
			j = (j + (ft_strlen_nrb(&str[j]) + 1));
		}
		ft_putchar(str[j]);
		j++;
	}
	va_end(ap);
	return (0);
}
