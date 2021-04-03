/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:13 by egomes            #+#    #+#             */
/*   Updated: 2021/04/03 20:46:00 by egomes           ###   ########.fr       */
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

void    ft_printas_s(va_list ap, t_obj *obj, const char *str)
{
    char *s;
    int i;
    int j;
    char *buff;
    int cpy;

    cpy = -1;
    i = (int)(va_arg(ap, int));
    s = (va_arg(ap, char *));
    j = ft_strlen(s);
    if (i < 0)
    {
        cpy *= i;
        buff = ft_newstr(cpy);
        ft_memset(buff, ' ', cpy);
    }
    else
    {
        buff = ft_newstr(i);
        ft_memset(buff, ' ', i);
    }
    if (i == 0)
        ft_putchars(s, obj);
    else if (str[-1] == '-' || i < 0)
        ft_memcpy(buff, s, 0, j);
    else
        ft_memcpy(buff, s, i - j, j);
    ft_putchars(buff, obj);
    free(buff);
}
