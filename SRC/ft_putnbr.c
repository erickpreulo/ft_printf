/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:38:41 by egomes            #+#    #+#             */
/*   Updated: 2021/04/17 17:35:04 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, t_obj *obj)
{
	if (nb < 0)
	{
		ft_putchar('-', obj);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, obj);
		ft_putnbr(nb % 10, obj);
	}
	else
		ft_putchar(nb + '0', obj);
}

void	ft_putnbru(unsigned int nb, t_obj *obj)
{
	if (nb >= 10)
	{
		ft_putnbru(nb / 10, obj);
		ft_putnbru(nb % 10, obj);
	}
	else
		ft_putchar(nb + '0', obj);
}

void	ft_putnbr_hex(unsigned long nbr, char *base, t_obj *obj)
{
	unsigned long	holder;

	holder = nbr;
	if (holder >= 16)
	{
		ft_putnbr_hex(holder / 16, base, obj);
		ft_putnbr_hex(holder % 16, base, obj);
	}
	else
		ft_putchar(base[holder], obj);
}

void	ft_cpy_hexs(unsigned long nbr, char *base, t_obj *obj)
{
	unsigned long	holder;

	holder = nbr;
	if (holder >= 16)
	{
		ft_cpy_hexs(holder / 16, base, obj);
		ft_cpy_hexs(holder % 16, base, obj);
	}
	else
	{
		obj->hex[obj->counthex] = base[holder];
		obj->counthex += 1;
		obj->hexleng += 1;
	}
}

void	ft_leng_hexs(unsigned long nbr, t_obj *obj)
{
	unsigned long	holder;

	holder = nbr;
	if (holder >= 16)
	{
		ft_leng_hexs(holder / 16, obj);
		ft_leng_hexs(holder % 16, obj);
	}
	else
		obj->hexleng += 1;
}
