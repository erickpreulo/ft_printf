/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:19 by egomes            #+#    #+#             */
/*   Updated: 2021/04/10 23:44:27 by egomes           ###   ########.fr       */
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

typedef struct s_as
{
	char    c;
	int     i;
	char    *buff;
	int     cpy;
	char	*s;
	int		size;
}             t_as;

typedef struct	s_dot
{
	char 	*bf;
	char 	*af;
	int 	l;
	int		a;
	int 	b;
	char 	*neg;
	char 	*s;
	const char *buff;
	int		cpya;
	int		cpyb;
	int		la;
	long int		au;
	long int 	bu;
	long int		cpyau;
	long int		cpybu;
	long int	lu;
}				t_dot;

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
	int		size;
}               t_obj;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, t_obj *obj);
void    ft_putcharstr(char c);
int		ft_strlen(const char *str);
void	print(const char *str, t_obj *obj);
void	printc(const char *str, t_obj *obj);
void	prints(const char *str, t_obj *obj);
void	ft_putnbr(int n, t_obj *obj);
void	printdi(const char *str, t_obj *obj);
void	printu(const char *str, t_obj *obj);
void	ft_putnbru(unsigned int nb, t_obj *obj);
void	printx(const char *str, t_obj *obj);
void	ft_putnbr_hex(unsigned int nbr, char *base, t_obj *obj);
void	printX(const char *str, t_obj *obj);
void	printp(const char *str, t_obj *obj);
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
char	*ft_itoap(unsigned int n);
char	*ft_itoahex(unsigned int n);
void    ft_neg(char *str);
void    ft_negdi(char *str);
void    ft_print0(t_obj *obj);
void    ft_print0hex(int i, int size, char *s, char *str, t_obj *obj);
void	ft_printspace(t_obj *obj);
void	ft_printspaces(t_obj *obj);
void	ft_printspacec(char s, t_obj *obj);
void    ft_printspacehex(int i, char *s, char *str, t_obj *obj);
void    ft_printspacehexp(int i, int size, unsigned int s, char *str, t_obj *obj);
void	ft_printendspacec(char s, t_obj *obj);
void	ft_printendspace(t_obj *obj);
void	ft_printendspaces(t_obj *obj);
void    ft_printendspacehex(int i, char *s, char *str, t_obj *obj);
void    ft_printendspacehexp(int i, int size, unsigned int s, char *str, t_obj *obj);
void	*ft_memsetstart(char *s, int c, size_t start, size_t n);
int		ft_strlen_find_dot(const char *str);
char	*ft_strlen_afdot(const char *str, char *s);
char	*ft_strlen_afdotdi(const char *str);
char	*ft_strlen_bfdot(const char *str);
void    ft_putchars(char *s, t_obj *obj);
void	ft_printdot_di(const char *str, t_obj *obj);
void	dot_d1(t_dot *dotd, t_obj *obj, const char *str);
void	dot_d2(t_dot *dotd, t_obj *obj);
void	dot_d3(t_dot *dotd, t_obj *obj, const char *str);
void	dot_d4(t_dot *dotd, t_obj *obj, const char *str);
void	dot_d5(t_dot *dotd, t_obj *obj);
void	dot_d6(t_dot *dotd, t_obj *obj);
void	dot_d7(t_dot *dotd, t_obj *obj);
void    ft_negdot(char *str);
void	ft_printdot_s(const char *str, t_obj *obj);
int    ft_isneg(char *str);
void	ft_strlen_hex(int nbr, char *base, t_obj *obj);
void	ft_cpy_hexs(int nbr, char *base, t_obj *obj);
void	ft_printdot_hex(char *s, const char *str, char *hex, t_obj *obj);
void    ft_printas_c(t_obj *obj, const char *str);
void    ft_printas_s(t_obj *obj, const char *str);
void    ft_printas_di(t_obj *obj, const char *str);
void	ft_printdot_u(const char *str, t_obj *obj);
void	dot_u(t_dot *dotd, t_obj *obj, const char *str);
void	ft_printendspaceu(t_obj *obj);
void    ft_print0u(t_obj *obj);
void	ft_printspaceu(t_obj *obj);
void	dot_u1(t_dot *dotd, t_obj *obj, const char *str);
void	dot_u2(t_dot *dotd, t_obj *obj);
void	dot_u3(t_dot *dotd, t_obj *obj, const char *str);
void	dot_u4(t_dot *dotd, t_obj *obj, const char *str);
void	dot_u5(t_dot *dotd, t_obj *obj);
void	dot_u6(t_dot *dotd, t_obj *obj);
void	dot_u7(t_dot *dotd, t_obj *obj);
void    ft_printas_u(t_obj *obj, const char *str);

#endif