/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:04:59 by egomes            #+#    #+#             */
/*   Updated: 2021/03/25 23:19:12 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printc(va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	ft_putchar(c);
}
void	print(va_list ap, const char *str)
{
	int i;

	i = 0;
	if (str[i] == 'c')
		printc(ap);
}

 int	ft_printf(const char *str, ...)
 {
	 va_list ap;
	 int i;
	 int j;

	 i = ft_strlen(str);
	 va_start(ap, str);
	 j = 0;
	 while(j <= i)
	 {
		 if (str[j] == '%')
		{
			j++;
			print(ap, str);
			j++;
		}
		 	
		 ft_putchar(str[j]);
		 j++;
	 }
	 va_end(ap);
	 return(0);
 }