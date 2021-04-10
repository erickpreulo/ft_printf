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

void	ft_printspace(t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoa(va_arg(obj->ap, int));
    obj->sizes = ft_strlen(s);
    if (obj->size > obj->sizes)
    {
        buff = ft_newstr(obj->size - obj->sizes);
        ft_memset(buff, ' ', (obj->size - obj->sizes));
        ft_putchars(buff, obj);
        ft_putchars(s, obj);
        free(buff);
        free(s);
    }
    else
        ft_putchars(s, obj);
}

void	ft_printspaceu(t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoap(va_arg(obj->ap, unsigned int));
    obj->sizes = ft_strlen(s);
    if (obj->size > obj->sizes)
    {
        buff = ft_newstr(obj->size - obj->sizes);
        ft_memset(buff, ' ', (obj->size - obj->sizes));
        ft_putchars(buff, obj);
        ft_putchars(s, obj);
        free(buff);
        free(s);
    }
    else
        ft_putchars(s, obj);
}

void	ft_printspacec(char s,  t_obj *obj)
{
    int j;
    char *buff;

    j = 0;
    buff = ft_newstr(obj->size - 1);
	ft_memset(buff, ' ', obj->size);
	while (j < (obj->size - 1))
	{
		ft_putchar(buff[j], obj);
		j++;
	}
	ft_putchar(s, obj);
    free(buff);
}

void	ft_printspaces(t_obj *obj)
{
    char *buff;
    char *s;

    s = va_arg(obj->ap, char *);
    obj->sizes = ft_strlen(s);
    if (obj->size > obj->sizes)
    {
        buff = ft_newstr(obj->size - obj->sizes);
        ft_memset(buff, ' ', (obj->size - obj->sizes));
        ft_putchars(buff, obj);
        ft_putchars(s, obj);
        free(buff);
    }
    else
        ft_putchars(s, obj);
}

void    ft_printspacehex(int i, char *s, char *str, t_obj *obj)
{
    char *buff;

    buff = ft_newstr(obj->size - i);
	ft_memset(buff, ' ', (obj->size - i));
    ft_neg(buff);
	ft_putchars(buff, obj);
    ft_putnbr_hex(ft_atoi(s), str, obj);
    free(buff);
}

void    ft_printspacehexp(int i, int size, unsigned int s, char *str, t_obj *obj)
{
    char *buff;

    buff = ft_newstr(size - i);
	ft_memset(buff, ' ', (size - i));
    ft_neg(buff);
	ft_putchars(buff, obj);
    ft_putchar('0', obj);
	ft_putchar('x', obj);
    ft_putnbr_hex(s, str, obj);
    free(buff);
}