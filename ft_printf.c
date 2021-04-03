/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:04:59 by egomes            #+#    #+#             */
/*   Updated: 2021/04/03 20:51:10 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_obj(t_obj *obj)
{
	obj->printedhex = 0;
	obj->counthex = 0;
	obj->hexleng = 0;
}

static void	init_obj(t_obj *obj)
{
	obj->printed = 0;
	obj->sequence = 0;
	reset_obj(obj);
}

void		print(va_list ap, const char *str, t_obj *obj)
{
	int size;
	int nbrsize;

	nbrsize = ft_strlen_nrb(str);
	size = ft_atoi(str);
	if (str[nbrsize] == 'c')
		printc(ap, size, str, obj);
	if (str[nbrsize] == 's') 
		prints(ap, size, str, obj);
	if (str[nbrsize] == 'd' || str[nbrsize] == 'i')
		printdi(ap, size, str, obj);
	if ( str[nbrsize] == 'u')
		printu(ap, size, str, obj);
	if (str[nbrsize] == 'x')
		printx(ap, size, str, obj);
	if (str[nbrsize] == 'X') 
		printX(ap, size, str, obj);
	if (str[nbrsize] == 'p')
		printp(ap, size, str, obj);
	if (str[nbrsize] == '%')
		ft_putchar('%', obj);
}

int			ft_printf(const char *str, ...)
{
	t_obj	obj;
	char	cpy;

	init_obj(&obj);
	va_start(obj.args, str);
	while (str[obj.sequence])
	{
		cpy = str[obj.sequence];
		if (cpy == '%')
		{
			obj.sequence += 1;
			if (str[obj.sequence] == '-')
				print(obj.args, &str[obj.sequence + 1], &obj);
			else
				print(obj.args, &str[obj.sequence], &obj);
			reset_obj(&obj);
			obj.sequence += (ft_strlen_nrb(&str[obj.sequence]));
		}
		else
			ft_putchar(cpy, &obj);
		obj.sequence += 1;
	}
	va_end(obj.args);
	return (obj.printed);
}
