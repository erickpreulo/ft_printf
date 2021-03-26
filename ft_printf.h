/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:19 by egomes            #+#    #+#             */
/*   Updated: 2021/03/26 13:44:41 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

 int		ft_printf(const char *str, ...);
 void		ft_putchar(char c);
 int		ft_strlen(const char *str);
 void		print(va_list ap, const char *str);
 void		printc(va_list ap);
 void		prints(va_list ap);
 char		bar_rule(const char *str);
 void		ft_putnbr(int n);
 void		printd(va_list ap);

#endif