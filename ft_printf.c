/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:04:59 by egomes            #+#    #+#             */
/*   Updated: 2021/05/12 16:41:07 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_obj(t_obj *obj)
{
	obj->printedhex = 0;
	obj->counthex = 0;
	obj->hexleng = 0;
	obj->i = 0;
	obj->trash = 9999999;
	obj->size = 0;
	obj->sizes = 0;
}

static void	init_obj(t_obj *obj)
{
	obj->printed = 0;
	obj->sequence = 0;
	reset_obj(obj);
}

void	print(const char *str, t_obj *obj)
{
	int		nbrsize;

	nbrsize = ft_strlen_nrb(str);
	obj->size = ft_atoi(str);
	if (str[nbrsize] == 'c')
		printc(str, obj);
	else if (str[nbrsize] == 's')
		prints(str, obj);
	else if (str[nbrsize] == 'd' || str[nbrsize] == 'i')
		printdi(str, obj);
	else if (str[nbrsize] == 'u')
		printu(str, obj);
	else if (str[nbrsize] == 'x')
		printx(str, obj);
	else if (str[nbrsize] == 'X')
		printX(str, obj);
	else if (str[nbrsize] == 'p')
		printp(str, obj);
	else if (str[nbrsize] == '%')
		printpc(str, obj);
	else if (str[nbrsize == '\n'])
		ft_putchar('\n', obj);
	
}

int	ft_printf(const char *str, ...)
{
	t_obj	obj;

	init_obj(&obj);
	va_start(obj.ap, str);
	while (str[obj.sequence])
	{
		obj.cpy = str[obj.sequence];
		if (obj.cpy == '%')
		{
			obj.sequence += 1;
			if (str[obj.sequence] == '-')
				print(&str[obj.sequence + 1], &obj);
			else
				print(&str[obj.sequence], &obj);
			reset_obj(&obj);
			obj.sequence += (ft_strlen_nrb(&str[obj.sequence]));
		}
		else
			ft_putchar(obj.cpy, &obj);
		obj.sequence += 1;
	}
	va_end(obj.ap);
	return (obj.printed);
}
