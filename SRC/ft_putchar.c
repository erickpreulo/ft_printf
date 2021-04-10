/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:05:53 by egomes            #+#    #+#             */
/*   Updated: 2021/04/03 20:56:18 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_putchar(char c, t_obj *obj)
{
    write(1, &c, 1);
    obj->printed += 1;
}

void        ft_putcharstr(char c)
{
    write(1, &c, 1);
}

void    ft_putchars(char *s, t_obj *obj)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i], obj);
        i++;
    }
}
