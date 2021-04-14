/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:05:53 by egomes            #+#    #+#             */
/*   Updated: 2021/04/14 20:52:40 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_obj *obj)
{
	write(1, &c, 1);
	obj->printed += 1;
}

void	ft_putchars(char *s, t_obj *obj)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], obj);
		i++;
	}
}
