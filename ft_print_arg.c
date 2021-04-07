/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:46:19 by egomes            #+#    #+#             */
/*   Updated: 2021/04/07 14:37:14 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printc(va_list ap, int size, const char *str, t_obj *obj)
{
	char c;

	if (str[0] == '*' || (str[0] != 'c' && str[1] == '*'))
		ft_printas_c(ap, obj, str);
	else
		c = (char)va_arg(ap, int);
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacec(c, size, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspacec(c, size, obj);
	else if (str[0] == 'c')
		ft_putchar(c, obj);
}

void		prints(int size, const char *str, t_obj *obj)
{
	if (str[0] == '*' || (str[0] != 's' && str[1] == '*'))
		ft_printas_s(obj, str);
	if (ft_strlen_find_dot(str) && str[0] != '*')
		ft_printdots(str, obj);
	else if (str[-1] == '-')
		ft_printendspaces(size, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspaces(size, obj);
	else if (str[0] == 's')
		ft_putchars(va_arg(obj->ap, char *), obj);
}

void		printdi(int size, const char *str, t_obj *obj)
{
	char *s;

	if (ft_strlen_find_dot(str))
		ft_printdot(str, obj);
	//else if (str[0] == '*' || str[1] == '*' || str[2] == '*')
	//	ft_printas_di(obj, str);
	else if (str[-1] == '-' && str[0] != '*')
		ft_printendspace(size, obj);
	else if (str[0] == '0')
		ft_print0(size, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspace(size, obj);
	else if (str[0] == 'd' || str[0] == 'i')
	{
		s = ft_itoa(va_arg(obj->ap, int));
		ft_putchars(s, obj);
		free(s);
	}
}

void		printu(int size, const char *str, t_obj *obj)
{
	char *s;

	if (str[-1] == '-')
		ft_printendspace(size, obj);
	else if (ft_strlen_find_dot(str))
		ft_printdot(str, obj);
	else if (str[0] == '0')
		ft_print0(size, obj);
	else if (str[0] >= '1' && str[0] <= '9')
		ft_printspace(size, obj);
	else
	{
		s = ft_itoa(va_arg(obj->ap, int));
		ft_putchars(s, obj);
		free(s);
	}
}

void	printx(va_list ap, int size, const char *str, t_obj *obj)
{
	char	*s;
	int	i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if (ft_strlen_find_dot(str))
		ft_printdot_hex(s, str, "0123456789abcdef", obj);
	else if (ft_isneg(s))
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef", obj);
	else if (str[-1] == '-')
		ft_printendspacehex(i, size, s, "0123456789abcdef", obj);
	else if (size > i && str[0] == '0')
		ft_print0hex(i, (size - 1), s, "0123456789abcdef", obj);
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehex(i, (size), s, "0123456789abcdef", obj);
	else if (str[0] == 'x')
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef", obj);
	free(s);
}

void	printX(va_list ap, int size, const char *str, t_obj *obj)
{
	char	*s;
	int		i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if (str[-1] == '-' && (!(ft_strlen_find_dot(str))))
		ft_printendspacehex(i, size, s, "0123456789ABCDEF", obj);
	else if (ft_strlen_find_dot(str) || str[-1] == '-')
		ft_printdot_hex(s, str, "0123456789ABCDEF", obj);
	else if (ft_isneg(s))
		ft_putnbr_hex(ft_atoi(s), "0123456789ABCDEF", obj);
	else if (size > i && str[0] == '0')
		ft_print0hex(i, (size - 1), s, "0123456789ABCDEF", obj);
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehex(i, (size), s, "0123456789ABCDEF", obj);
	else if (str[0] == 'X')
		ft_putnbr_hex(ft_atoi(s), "0123456789ABCDEF", obj);
	free(s);
}

void	printp(va_list ap, int size, const char *str, t_obj *obj)
{
	char	*s;
	int	i;

	s = ft_itoa(va_arg(ap, unsigned int));
	i = ft_strlen(s);
	if ((str[-1] == '-') && (str[0] >= '0' && str[0] <= '9'))
		ft_printendspacehexp(i, (size - 2), s, "0123456789abcdef", obj);
	else if (size > i && (str[0] >= '1' && str[0] <= '9'))
		ft_printspacehexp(i, (size - 2), s, "0123456789abcdef", obj);
	else if (str[0] == 'p')
	{
		ft_putchar('0', obj);
		ft_putchar('x', obj);
		ft_putnbr_hex(ft_atoi(s), "0123456789abcdef", obj);
	}
	free(s);
}
