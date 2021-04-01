/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:05:30 by egomes            #+#    #+#             */
/*   Updated: 2021/03/29 21:05:30 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printspace(char *s, int i, int size)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
	ft_putchars(buff);
	ft_putchars(s);
    free(buff);
}

void	ft_printspacec(char s, int size)
{
    int j;
    char *buff;

    j = 0;
    buff = ft_newstr(size);
	ft_memset(buff, ' ', size);
	while (j < (size - 1))
	{
		ft_putchar(buff[j]);
		j++;
	}
	ft_putchar(s);
    free(buff);
}

void    ft_printspacehex(int i, int size, char *s, char *str)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
    ft_neg(buff);
	ft_putchars(buff);
    ft_putnbr_hex(ft_atoi(s), str);
    free(buff);
}

void    ft_printspacehexp(int i, int size, char *s, char *str)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
    ft_neg(buff);
	ft_putchars(buff);
    ft_putchar('0');
	ft_putchar('x');
    ft_putnbr_hex(ft_atoi(s), str);
    free(buff);
}