/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:38:41 by egomes            #+#    #+#             */
/*   Updated: 2021/03/27 18:23:20 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void		ft_putnbru(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void			ft_putnbr_hex(unsigned long nbr, char *base)
{
	unsigned long	holder;
	unsigned long	base_length;

	base_length = ft_strlen(base);
	holder = nbr;
	if (holder >= base_length)
	{
		ft_putnbr_hex(holder / base_length, base);
		ft_putnbr_hex(holder % base_length, base);
	}
	else
		ft_putchar(base[holder]);
}
