/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_end_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:36:50 by egomes            #+#    #+#             */
/*   Updated: 2021/04/13 14:28:08 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printendspaces(t_obj *obj)
{
    char *buff;
    char *s;

    s = va_arg(obj->ap, char *);
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(obj->size);
	ft_memcpy(buff, s, 0, obj->sizes);
	ft_memsetstart(buff, ' ', obj->sizes, obj->size);
	ft_putchars(buff, obj);
    free(buff);
}

void	ft_printendspace(t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoa(va_arg(obj->ap, int));
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(obj->size);
	ft_memcpy(buff, s, 0, obj->sizes);
	ft_memsetstart(buff, ' ', obj->sizes, obj->size);
	ft_putchars(buff, obj);
    free(buff);
    free(s);
}

void	ft_printendspaceu(t_obj *obj)
{
    char *buff;
    char *s;

    s = ft_itoap(va_arg(obj->ap, unsigned int));
    obj->sizes = ft_strlen(s);
    buff = ft_newstr(obj->size);
	ft_memcpy(buff, s, 0, obj->sizes);
	ft_memsetstart(buff, ' ', obj->sizes, obj->size);
	ft_putchars(buff, obj);
    free(buff);
    free(s);
}

void	ft_printendspacec(char s, t_obj *obj)
{
    char *buff;
    int j;

    j = 0;
    buff = ft_newstr(obj->size);
	ft_memset(buff, ' ', (obj->size));
	ft_putchar(s, obj);
	while (j < (obj->size - 1))
	{
		ft_putchar(buff[j], obj);
		j++;
	}
    free(buff);
}

void    ft_printendspacehex(char *str, t_obj *obj)
{
    obj->hex = ft_newstr(8);
    ft_cpy_hexs(va_arg(obj->ap, unsigned int), str, obj);
    if (obj->counthex >= obj->size)
    {
        while (obj->i < obj->counthex)
        {
            ft_putchar(obj->hex[obj->i], obj);
            obj->i++;
        }
    }
    else
    {
        obj->buff = ft_newstr(obj->size);
        ft_memset(obj->buff, ' ', obj->size);
        ft_memcpy(obj->buff, obj->hex, 0, obj->counthex);
        ft_putchars(obj->buff, obj);
        free(obj->buff);
    }
    free(obj->hex);
}

void    ft_printendspacehexp(char *hex, t_obj *obj)
{
    obj->hex = ft_newstr(10);
	ft_memset(obj->hex, 'x', 2);
	ft_memset(obj->hex, '0', 1);
	obj->counthex += 2;
    ft_cpy_hexs(va_arg(obj->ap, unsigned int), hex, obj);
    obj->buff = ft_newstr(obj->size);
    if (obj->counthex >= obj->size)
    {
        while (obj->i < obj->counthex)
        {
            ft_putchar(obj->hex[obj->i], obj);
            obj->i++;
        }
    }
    else
    {
        ft_memset(obj->buff, ' ', obj->size);
        ft_memcpy(obj->buff, obj->hex, 0, obj->counthex);
        ft_neg(obj->buff);
        ft_putchars(obj->buff, obj);
    }
    free(obj->buff);
    free(obj->hex);
}
