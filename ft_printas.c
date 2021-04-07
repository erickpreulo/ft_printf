/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:13 by egomes            #+#    #+#             */
/*   Updated: 2021/04/07 14:36:59 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printas_c(va_list ap, t_obj *obj, const char *str)
{
    char c;
    int i;
    char *buff;
    int cpy;

    cpy = -1;
    i = (int)(va_arg(ap, int));
    c = (char)(va_arg(ap, int));
    if (i < 0)
    {
        cpy *= i;
        buff = ft_newstr(cpy - 1);
        ft_memset(buff, ' ', cpy - 1);
    }
    else if (i > 0)
    {
        buff = ft_newstr(i - 1);
        ft_memset(buff, ' ', i - 1);
    }
    else
    {
        buff = ft_newstr(i);
        ft_memset(buff, ' ', i);
    }
    if (i == 0)
        ft_putchar(c, obj);
    else if (str[-1] == '-' || cpy > 0)
    {
        ft_putchar(c, obj);
        ft_putchars(buff, obj);
    }
    else if (i > 0)
    {
        ft_putchars(buff, obj);
        ft_putchar(c, obj);
    }
    free(buff);
}

void    ft_printas_s(t_obj *obj, const char *str)
{
    char *buff;
    int cpy;
    int size;
    int i;
    char *s;

    i = va_arg(obj->ap, int);
	s = va_arg(obj->ap, char *);
    cpy = -1;
    size = ft_strlen(s);
    if (i < 0)
    {
        cpy *= i;
        if (cpy > size)
        {
            buff = ft_newstr(cpy - size);
            ft_memset(buff, ' ', cpy - size);
        }
        else
        {
            buff = ft_newstr(size);
            ft_memset(buff, ' ', size);
        }
    }
    else if (i >= 0)
    {
        if (str[2] == 's' || str[2] == '0')
        {
            buff = ft_newstr(i);
            ft_memset(buff, ' ', i);
        }
        else if (i > size)
        {
            buff = ft_newstr(i - size);
            ft_memset(buff, ' ', i - size);
        }
        else
        {
            buff = ft_newstr(size);
            ft_memset(buff, ' ', size);
        }
    }
    else
    {
        buff = ft_newstr(i);
        ft_memset(buff, ' ', i);
    }
    if (i == 0)
        ft_putchars(s, obj);
    else if (str[2] == 's' || str[2] == '0')
        ft_putchars(buff, obj);
    else if (str[-1] == '-' || cpy > 0)
    {
        if (cpy > size)
        {
            ft_putchars(s, obj);
            ft_putchars(buff, obj);
        }
        else
            ft_putchars(s, obj);
    }
    else if (i > 0)
    {
        if (i > size)
        {
            ft_putchars(buff, obj);
            ft_putchars(s, obj);
        }
        else
            ft_putchars(s, obj);
    }
    free(buff);
}
