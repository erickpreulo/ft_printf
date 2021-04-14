/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:05:30 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 20:28:18 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printspace(t_obj *obj)
{
	char	*buff;
	char	*s;

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
