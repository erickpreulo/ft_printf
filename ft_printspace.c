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

void	ft_printspace(char *s, int i, int size, t_obj *obj)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
	ft_putchars(buff, obj);
	ft_putchars(s, obj);
    free(buff);
}

void	ft_printspacec(char s, int size, t_obj *obj)
{
    int j;
    char *buff;

    j = 0;
    buff = ft_newstr(size - 1);
	ft_memset(buff, ' ', size);
	while (j < (size - 1))
	{
		ft_putchar(buff[j], obj);
		j++;
	}
	ft_putchar(s, obj);
    free(buff);
}

void    ft_printspacehex(int i, int size, char *s, char *str, t_obj *obj)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
    ft_neg(buff);
	ft_putchars(buff, obj);
    ft_putnbr_hex(ft_atoi(s), str, obj);
    free(buff);
}

void    ft_printspacehexp(int i, int size, char *s, char *str, t_obj *obj)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
    ft_neg(buff);
	ft_putchars(buff, obj);
    ft_putchar('0', obj);
	ft_putchar('x', obj);
    ft_putnbr_hex(ft_atoi(s), str, obj);
    free(buff);
}