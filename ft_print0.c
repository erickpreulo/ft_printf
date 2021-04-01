/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:09:26 by egomes            #+#    #+#             */
/*   Updated: 2021/03/29 13:09:26 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print0(char *s, int i, int size)
{
    char *buff;

    buff = ft_newstr(size);
	ft_memset(buff, '0', size);
	ft_memcpy(buff, s, (size - i), i);
    ft_neg(buff);
	ft_putchars(buff);
    free(buff);
}

void    ft_print0hex(int i, int size, char *s, char *str)
{
    int j;
    char *buff;

    j = 0;
    buff = ft_newstr(size - i);
	ft_memset(buff, '0', size);
    ft_neg(buff);
	while (j <= (size - i))
	{
		ft_putchar(buff[j]);
		j++;
	}
    ft_putnbr_hex(ft_atoi(s), str);
    free(buff);
}