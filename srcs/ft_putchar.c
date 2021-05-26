/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:05:53 by egomes            #+#    #+#             */
/*   Updated: 2021/05/26 11:47:03 by egomes           ###   ########.fr       */
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

int	as_find_lether(char c)
{
	int		i;

	i = 0;
	while (LETRAS[i] != '0')
		if (c == LETRAS[i++])
			return (0);
	return (1);
}

int	ft_find_as(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && as_find_lether(str[i]))
	{
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

int	jump(const char *str)
{
	int	i;
	int	r;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	r = ft_atoi(&str[i]);
	return (r);
}
