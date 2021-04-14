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

void	ft_print0(t_obj *obj)
{
	char	*buff;
	char	*s;

	s = ft_itoa(va_arg(obj->ap, int));
	obj->sizes = ft_strlen(s);
	if (obj->sizes >= obj->size)
		ft_putchars(s, obj);
	else
	{
		buff = ft_newstr(obj->size);
		ft_memset(buff, '0', obj->size);
		ft_memcpy(buff, s, (obj->size - obj->sizes), obj->sizes);
		ft_neg(buff);
		ft_putchars(buff, obj);
		free(buff);
	}
	free(s);
}

void	ft_print0u(t_obj *obj)
{
	char	*buff;
	char	*s;

	s = ft_itoap(va_arg(obj->ap, unsigned int));
	obj->sizes = ft_strlen(s);
	if (obj->sizes >= obj->size)
		ft_putchars(s, obj);
	else
	{
		buff = ft_newstr(obj->size);
		ft_memset(buff, '0', obj->size);
		ft_memcpy(buff, s, (obj->size - obj->sizes), obj->sizes);
		ft_neg(buff);
		ft_putchars(buff, obj);
		free(buff);
	}
	free(s);
}

void	ft_print0hex(char *str, t_obj *obj)
{
	char	*buff;
	int		i;

	obj->hex = ft_newstr(20);
	i = 0;
	ft_cpy_hexs(va_arg(obj->ap, unsigned long), str, obj);
	if (obj->hexleng >= obj->size)
	{
		while (i <= obj->hexleng)
		{
			ft_putchar(obj->hex[i], obj);
			i++;
		}
	}
	else
	{
		buff = ft_newstr(obj->size);
		ft_memset(buff, '0', obj->size);
		ft_memcpy(buff, obj->hex, (obj->size - obj->hexleng), obj->hexleng);
		ft_putchars(buff, obj);
		free(buff);
	}
	free(obj->hex);
}
