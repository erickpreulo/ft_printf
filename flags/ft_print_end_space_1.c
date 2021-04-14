/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_end_space_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:36:50 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 20:23:51 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printendspaces(t_obj *obj)
{
	char	*buff;
	char	*s;

	s = va_arg(obj->ap, char *);
	if (s == NULL)
		s = "(null)";
	obj->sizes = ft_strlen(s);
	if (obj->sizes >= obj->size)
		ft_putchars(s, obj);
	else
	{
		buff = ft_newstr(obj->size);
		ft_memcpy(buff, s, 0, obj->sizes);
		ft_memsetstart(buff, ' ', obj->sizes, obj->size);
		ft_putchars(buff, obj);
		free(buff);
	}
}
