/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:46:19 by egomes            #+#    #+#             */
/*   Updated: 2021/04/01 16:29:36 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printc(va_list ap, int size, const char *str)
{
	char c;

	c = (char)va_arg(ap, int);
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacec(c, size);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacec(c, size);
	else
		ft_putchar(c);
}

void		prints(va_list ap, int size, const char *str)
{
	char	*s;
	int		i;

	s = va_arg(ap, char *);
	i = ft_strlen(s);
	if (str[-1] == '-')
		ft_printendspace(s, i, size);
	else if (ft_strlen_find_dot(str))
		ft_printdots(s, str);
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspace(s, i, size );
	else
		ft_putchars(s);
}

void		printdi(va_list ap, int size, const char *str)
{
	char	*s;
	int		i;

	s = ft_itoa(va_arg(ap, int));
	i = ft_strlen(s);
	if (str[-1] == '-')
		ft_printendspace(s, i, size);
	else if (ft_strlen_find_dot(str))
		ft_printdot(s, str);
	else if (size > i && str[0] == '0')
		ft_print0(s, i, size);
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspace(s, i, size);
	else
		ft_putchars(s);
	free(s);
}

void		printu(va_list ap, int size, const char *str)
{
	char	*s;
	int		i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if (str[-1] == '-')
		ft_printendspace(s, i, size);
	else if (ft_strlen_find_dot(str))
		ft_printdot(s, str);
	else if (size > i && str[0] == '0')
		ft_print0(s, i, size);
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspace(s, i, size);
	else
		ft_putchars(s);
	free(s);
}

void	printx(va_list ap, int size, const char *str)
{
	char	*s;
	int	i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if (ft_strlen_find_dot(str))
		ft_printdothex(s, str, "0123456789abcdef");
	else if (ft_isneg(s))
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef");
	else if (str[-1] == '-')
		ft_printendspacehex(i, size, s, "0123456789abcdef");
	else if (size > i && str[0] == '0')
		ft_print0hex(i, (size - 1), s, "0123456789abcdef");
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehex(i, (size), s, "0123456789abcdef");
	else if (str[0] == 'x')
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef");
	free(s);
}

void	printX(va_list ap, int size, const char *str)
{
	char	*s;
	int		i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if (ft_strlen_find_dot(str))
		ft_printdothex(s, str, "0123456789ABCDEF");
	else if (ft_isneg(s))
		ft_putnbr_hex(ft_atoi(s), "0123456789ABCDEF");
	else if (str[-1] == '-')
		ft_printendspacehex(i, size, s, "0123456789ABCDEF");
	else if (size > i && str[0] == '0')
		ft_print0hex(i, (size - 1), s, "0123456789ABCDEF");
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehex(i, (size), s, "0123456789ABCDEF");
	else if (str[0] == 'X')
		ft_putnbr_hex(ft_atoi(s), "0123456789ABCDEF");
	free(s);
}

void	printp(va_list ap, int size, const char *str)
{
	char	*s;
	int	i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacehexp(i, (size - 2), s, "0123456789abcdef");
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehexp(i, (size - 2), s, "0123456789abcdef");
	else if (str[0] == 'p')
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef");
	}
	free(s);
}
