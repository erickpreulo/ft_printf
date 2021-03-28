/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:19 by egomes            #+#    #+#             */
/*   Updated: 2021/03/27 22:34:50 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_strlen(const char *str);
void	print(va_list ap, const char *str);
void	printc(va_list ap);
void	prints(va_list ap, int size);
char	bar_rule(const char *str);
void	ft_putnbr(int n);
void	printdi(va_list ap);
void	printu(va_list ap);
void	ft_putnbru(unsigned int nb);
void	printx(va_list ap);
void	ft_putnbr_hex(unsigned long nbr, char *base);
void	printX(va_list ap);
void	printp(va_list ap);
int	    ft_atoi(const char *str);
void    print0(va_list ap, const char *str);
void	ft_bzero(char *s, size_t n);
void	*ft_memset(char *s, int c, size_t n);
char	*ft_newstr(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t start, size_t end);

#endif