/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:56:40 by egomes            #+#    #+#             */
/*   Updated: 2021/03/27 18:56:40 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        print0(va_list ap, const char *str)
{
    int i;
    int j;
    char *buff;
    int res;

    buff = malloc(0);
    i = 1;
    j = 0;
    while (str[i] >= 0 && str[i] <= 9)
    {
        buff[j] = str[i];
        i++;
        j++;
    }
    res = ft_atoi(buff);
    printf("%d", res);
    va_arg(ap, int);
}
