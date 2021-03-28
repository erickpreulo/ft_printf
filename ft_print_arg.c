/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:46:19 by egomes            #+#    #+#             */
/*   Updated: 2021/03/27 22:46:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printc(va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	ft_putchar(c);
}

void		prints(va_list ap, int size)
{
	char	*s;
	int		i;
	char *buff;
	int j;

	s = va_arg(ap, char *);
	i = ft_strlen(s);
	j = 0;
	if (size > i)
	{
		buff = ft_newstr(size);
		ft_bzero(buff, size);
		ft_memcpy(buff, s, (size - i), i);
		while (j <= size)
		{
			ft_putchar(buff[j]);
			j++;
		}
		free(buff);
	}
	else if (i > size)
	{
		while (j <= i)
		{
			ft_putchar(s[j]);
			j++;
		}
	}
}

void		printdi(va_list ap)
{
	int i;

	i = va_arg(ap, int);
	ft_putnbr(i);
}

void		printu(va_list ap)
{
	unsigned int i;

	i = va_arg(ap, unsigned int);
	ft_putnbru(i);
}

void	printx(va_list ap)
{
	unsigned int i;
	
	i = va_arg(ap, unsigned int);
	ft_putnbr_hex(i, "0123456789abcdef");
}

void	printX(va_list ap)
{
	unsigned int i;
	
	i = va_arg(ap, unsigned int);
	ft_putnbr_hex(i, "0123456789ABCDEF");
}

void	printp(va_list ap)
{
	unsigned int i;

	i = va_arg(ap, unsigned int);
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_hex(i, "0123456789abcdef");
}
