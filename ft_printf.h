/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:19 by egomes            #+#    #+#             */
/*   Updated: 2021/04/06 21:27:26 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef struct      s_obj
{
	int     printedhex;
	char    *hex;
	int     counthex;
	int     printed;
	int     hexleng;
	va_list     ap;
	int         sequence;
	int		sizes;
}               t_obj;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, t_obj *obj);
void    ft_putcharstr(char c);
int		ft_strlen(const char *str);
void	print(va_list ap, const char *str, t_obj *obj);
void	printc(va_list ap, int size, const char *str, t_obj *obj);
void	prints(int size, const char *str, t_obj *obj);
void	ft_putnbr(int n, t_obj *obj);
void	printdi(int size, const char *str, t_obj *obj);
void	printu(int size, const char *str, t_obj *obj);
void	ft_putnbru(unsigned int nb, t_obj *obj);
void	printx(va_list ap, int size, const char *str, t_obj *obj);
void	ft_putnbr_hex(unsigned int nbr, char *base, t_obj *obj);
void	printX(va_list ap, int size, const char *str, t_obj *obj);
void	printp(va_list ap, int size, const char *str, t_obj *obj);
int	    ft_atoi(const char *str);
void    print0(va_list ap, const char *str, t_obj *obj);
void	ft_bzero(char *s, size_t n);
void	*ft_memset(char *s, int c, size_t n);
void	*ft_memset_s(char *s, int c, size_t n);
char	*ft_newstr(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t start, size_t end);
void	*ft_memcpyneg(void *dst, const void *src, int end);
void	*ft_memcpynegstay(void *dst, const void *src, int end);
int		ft_strlen_nrb(const char *str);
char	*ft_itoa(int n);
char	*ft_itoahex(unsigned int n);
void    ft_neg(char *str);
void    ft_negdi(char *str);
void    ft_print0(int size, t_obj *obj);
void    ft_print0hex(int i, int size, char *s, char *str, t_obj *obj);
void	ft_printspace(int size, t_obj *obj);
void	ft_printspaces(int size, t_obj *obj);
void	ft_printspacec(char s, int size, t_obj *obj);
void    ft_printspacehex(int i, int size, char *s, char *str, t_obj *obj);
void    ft_printspacehexp(int i, int size, char *s, char *str, t_obj *obj);
void	ft_printendspacec(char s, int size, t_obj *obj);
void	ft_printendspace(int size, t_obj *obj);
void	ft_printendspaces(int size, t_obj *obj);
void    ft_printendspacehex(int i, int size, char *s, char *str, t_obj *obj);
void    ft_printendspacehexp(int i, int size, char *s, char *str, t_obj *obj);
void	*ft_memsetstart(char *s, int c, size_t start, size_t n);
int		ft_strlen_find_dot(const char *str);
char	*ft_strlen_afdot(const char *str, char *s);
char	*ft_strlen_afdotdi(const char *str);
char	*ft_strlen_bfdot(const char *str);
void    ft_putchars(char *s, t_obj *obj);
void	ft_printdot(const char *str, t_obj *obj);
void    ft_negdot(char *str);
void	ft_printdots(const char *str, t_obj *obj);
void	ft_printdothex(char *s, const char *str, char *hex, t_obj *obj);
int    ft_isneg(char *str);
void	ft_strlen_hex(int nbr, char *base, t_obj *obj);
void	ft_cpy_hexs(int nbr, char *base, t_obj *obj);
void	ft_printdot_hex(char *s, const char *str, char *hex, t_obj *obj);
void    ft_printas_c(va_list ap, t_obj *obj, const char *str);
void    ft_printas_s(t_obj *obj, const char *str);
void    ft_printas_di(t_obj *obj, const char *str);

#endif