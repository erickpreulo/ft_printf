/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printendspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:36:50 by egomes            #+#    #+#             */
/*   Updated: 2021/03/31 10:38:43 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printendspace(char *s, int i, int size)
{
    char *buff;

    buff = ft_newstr(size);
	ft_memcpy(buff, s, 0, i);
	ft_memsetstart(buff, ' ', i, size);
	ft_putchars(buff);
    free(buff);
}
void	ft_printendspacec(char s, int size)
{
    char *buff;

    buff = ft_newstr(size);
	ft_memset(buff, ' ', (size - 1));
	ft_putchar(s);
	ft_putchars(buff);
    free(buff);
}

void    ft_printendspacehex(int i, int size, char *s, char *str)
{
    char *buff;

    ft_putnbr_hex(ft_atoi(s), str);
    buff = ft_newstr(size - i);
	ft_memsetstart(buff, ' ', 0, (size - i));
    ft_neg(buff);
	ft_putchars(buff);
    free(buff);
}

void    ft_printendspacehexp(int i, int size, char *s, char *str)
{
    char *buff;

    ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_hex(ft_atoi(s), str);
    buff = ft_newstr(size - i);
	ft_memsetstart(buff, ' ', 0, (size - i));
    ft_neg(buff);
	ft_putchars(buff);
    free(buff);
}
