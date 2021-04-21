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

void	ft_printspaceu(t_obj *obj)
{
	char	*buff;
	char	*s;

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

void	ft_printspacec(char s, t_obj *obj)
{
	int		j;
	char	*buff;

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
	char	*buff;
	char	*s;

	s = va_arg(obj->ap, char *);
	if (s == NULL)
		s = "(null)";
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

void	ft_printspacehex(char *str, t_obj *obj)
{
	obj->unsig = va_arg(obj->ap, unsigned int);
	ft_leng_hexs(obj->unsig, obj);
	obj->hex = ft_newstr(obj->hexleng);
	ft_cpy_hexs(obj->unsig, str, obj);
	if (obj->counthex >= obj->size)
		ft_putchars(obj->hex, obj);
	else
	{
		obj->buff = ft_newstr(obj->size);
		ft_memset(obj->buff, ' ', obj->size);
		ft_memcpy(obj->buff, obj->hex, (obj->size - obj->counthex),
			obj->counthex);
		ft_putchars(obj->buff, obj);
		free(obj->buff);
	}
	free(obj->hex);
}

void	ft_printspacehexp(char *hex, t_obj *obj)
{
	obj->hex = ft_newstr(20);
	ft_memset(obj->hex, 'x', 2);
	ft_memset(obj->hex, '0', 1);
	obj->counthex += 2;
	ft_cpy_hexs(va_arg(obj->ap, unsigned long), hex, obj);
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
		spahex(obj);
	free(obj->buff);
	free(obj->hex);
}
