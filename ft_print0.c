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

void    ft_print0(char *s, int i, int size, t_obj *obj)
{
    char *buff;

    buff = ft_newstr(size);
	ft_memset(buff, '0', size);
	ft_memcpy(buff, s, (size - i), i);
    ft_neg(buff);
	ft_putchars(buff, obj);
    free(buff);
}

void    ft_print0hex(int i, int size, char *s, char *str, t_obj *obj)
{
    int j;
    char *buff;

    j = 0;
    buff = ft_newstr(size - i);
	ft_memset(buff, '0', size);
    ft_neg(buff);
	while (j <= (size - i))
	{
		ft_putchar(buff[j], obj);
		j++;
	}
    ft_putnbr_hex(ft_atoi(s), str, obj);
    free(buff);
}