/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:19 by egomes            #+#    #+#             */
/*   Updated: 2021/04/01 15:50:13 by egomes           ###   ########.fr       */
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
void	printc(va_list ap, int size, const char *str);
void	prints(va_list ap, int size, const char *str);
void	ft_putnbr(int n);
void	printdi(va_list ap, int size, const char *str);
void	printu(va_list ap, int size, const char *str);
void	ft_putnbru(unsigned int nb);
void	printx(va_list ap, int size, const char *str);
void	ft_putnbr_hex(unsigned int nbr, char *base);
void	printX(va_list ap, int size, const char *str);
void	printp(va_list ap, int size, const char *str);
int	    ft_atoi(const char *str);
void    print0(va_list ap, const char *str);
void	ft_bzero(char *s, size_t n);
void	*ft_memset(char *s, int c, size_t n);
char	*ft_newstr(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t start, size_t end);
int		ft_strlen_nrb(const char *str);
char	*ft_itoa(int n);
char	*ft_itoahex(unsigned int n);
void    ft_neg(char *str);
void    ft_print0(char *s, int i, int size);
void    ft_print0hex(int i, int size, char *s, char *str);
void	ft_printspace(char *s, int i, int size);
void	ft_printspacec(char s, int size);
void    ft_printspacehex(int i, int size, char *s, char *str);
void    ft_printspacehexp(int i, int size, char *s, char *str);
void	ft_printendspacec(char s, int size);
void	ft_printendspace(char *s, int i, int size);
void    ft_printendspacehex(int i, int size, char *s, char *str);
void    ft_printendspacehexp(int i, int size, char *s, char *str);
void	*ft_memsetstart(char *s, int c, size_t start, size_t n);
int		ft_strlen_find_dot(const char *str);
char	*ft_strlen_afdot(const char *str, char *s);
char	*ft_strlen_bfdot(const char *str);
void    ft_putchars(char *s);
void	ft_printdot(char *s, const char *str);
void    ft_negdot(char *str);
void	ft_printdots(char *s, const char *str);
char	*ft_strlen_afdots(const char *str, char *s);
void	ft_printdothex(char *s, const char *str, char *hex);
int    ft_isneg(char *str);

#endif