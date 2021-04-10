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

void    ft_print0(t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoa(va_arg(obj->ap, int));
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(obj->size);
	ft_memset(buff, '0', obj->size);
	ft_memcpy(buff, s, (obj->size - obj->sizes), obj->sizes);
    ft_neg(buff);
	ft_putchars(buff, obj);
    free(buff);
    free(s);
}

void    ft_print0u(t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoap(va_arg(obj->ap, unsigned int));
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(obj->size);
	ft_memset(buff, '0', obj->size);
	ft_memcpy(buff, s, (obj->size - obj->sizes), obj->sizes);
    ft_neg(buff);
	ft_putchars(buff, obj);
    free(buff);
    free(s);
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