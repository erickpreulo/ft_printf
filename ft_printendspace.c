/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printendspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:36:50 by egomes            #+#    #+#             */
/*   Updated: 2021/04/06 17:02:59 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printendspace(int size, t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoa(va_arg(obj->ap, int));
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(size);
	ft_memcpy(buff, s, 0, obj->sizes);
	ft_memsetstart(buff, ' ', obj->sizes, size);
	ft_putchars(buff, obj);
    free(buff);
    free(s);
}

void	ft_printendspaces(int size, t_obj *obj)
{
    char *buff;
    char *s;

    s = va_arg(obj->ap, char *);
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(size);
	ft_memcpy(buff, s, 0, obj->sizes);
	ft_memsetstart(buff, ' ', obj->sizes, size);
	ft_putchars(buff, obj);
    free(buff);
}

void	ft_printendspacec(char s, int size, t_obj *obj)
{
    char *buff;
    int j;

    j = 0;
    buff = ft_newstr(size);
	ft_memset(buff, ' ', (size));
	ft_putchar(s, obj);
	while (j < (size - 1))
	{
		ft_putchar(buff[j], obj);
		j++;
	}
    free(buff);
}

void    ft_printendspacehex(int i, int size, char *s, char *str, t_obj *obj)
{
    char *buff;

    ft_putnbr_hex(ft_atoi(s), str, obj);
    buff = ft_newstr(size - i);
	ft_memsetstart(buff, ' ', 0, (size - i));
    ft_neg(buff);
	ft_putchars(buff, obj);
    free(buff);
}

void    ft_printendspacehexp(int i, int size, char *s, char *str, t_obj *obj)
{
    char *buff;

    ft_putchar('0', obj);
	ft_putchar('x', obj);
	ft_putnbr_hex(ft_atoi(s), str, obj);
    buff = ft_newstr(size - i);
	ft_memsetstart(buff, ' ', 0, (size - i));
    ft_neg(buff);
	ft_putchars(buff, obj);
    free(buff);
}
