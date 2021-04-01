/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:02 by egomes            #+#    #+#             */
/*   Updated: 2021/04/01 20:55:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdot(char *s, const char *str)
{
	char *bf;
	char *af;

	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdot(str, s);
	if (ft_strlen(af) > ft_strlen(bf) || ft_strlen(af) > ft_strlen(s))
	{
		ft_memcpy(af, s, (ft_strlen(af) - ft_strlen(s)), ft_strlen(s));
		ft_neg(af);
		if (ft_strlen(bf) > ft_strlen(af))
		{
			ft_memcpy(bf, af, (ft_strlen(bf) - ft_strlen(af)), ft_strlen(af));
			ft_putchars(bf);
		}
		else
			ft_putchars(af);
	}
	else
	{
		ft_memcpy(bf, s, (ft_strlen(bf) - ft_strlen(af)), (ft_strlen(af) + 1));
		ft_putchars(bf);
	}
	free(bf);
	free(af);
}

void	ft_printdots(char *s, const char *str)
{
	char *bf;
	char *af;

	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdots(str, s);
	if (ft_strlen(af) > ft_strlen(bf) || ft_strlen(af) > ft_strlen(s))
	{
		if (ft_strlen(bf) > ft_strlen(af))
		{
			ft_memcpy(af, s, (ft_strlen(af) - ft_strlen(s)), ft_strlen(s));
			ft_neg(af);
			ft_memcpy(bf, af, (ft_strlen(bf) - ft_strlen(af)), ft_strlen(af));
			ft_putchars(bf);
		}
		else
		{
			ft_memcpy(bf, s, (ft_strlen(bf) - ft_strlen(s)), ft_strlen(s));
			ft_putchars(bf);
		}
	}
	else
	{
		ft_memcpy(bf, s, (ft_strlen(bf) - ft_strlen(af)), ft_strlen(af));
		ft_putchars(bf);
	}
	free(bf);
	free(af);
}

void	ft_printdothex(char *s, const char *str, char *hex)
{
	char *bf;
	char *af;

	bf = ft_strlen_bfdot(str);
	af = ft_strlen_afdot(str, s);
	if (ft_isneg(s))
	{
		ft_memcpy(af, "", (ft_strlen(af) - 9), 8);
		ft_memcpy(bf, af, ((ft_strlen(bf) - ft_strlen(af)) - 8), ft_strlen(af));
		ft_putchars(bf);
	}
	if (ft_strlen(af) == 0)
	{
		ft_memcpy(bf, "", ((ft_strlen(bf) - ft_strlen(af)) - 2), (ft_strlen(af) + 1));
		ft_putchars(bf);
	}
	else if (ft_strlen(af) >= ft_strlen(bf))
	{
		ft_memcpy(af, "", ((ft_strlen(af) - ft_strlen(s))), ft_strlen(s));
		ft_memcpy(bf, af, 0, ft_strlen(af));
		ft_putchars(bf);
	}
	else if (ft_strlen(bf) > ft_strlen(af))
	{
		ft_memcpy(af, "", ((ft_strlen(af) - ft_strlen(s))), ft_strlen(s));
		ft_memcpy(bf, af, ((ft_strlen(bf) - ft_strlen(af)) - ft_strlen(s)), ft_strlen(af));
		ft_putchars(bf);
	}
	ft_putnbr_hex(ft_atoi(s), hex);
	free(bf);
	free(af);
}
