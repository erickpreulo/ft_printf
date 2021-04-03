/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 22:03:57 by egomes            #+#    #+#             */
/*   Updated: 2021/04/02 19:44:58 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_neg(char *str)
{
    int j;
    int buff;

    j = 0;
    while (str[j] != '\0')
    {
        if(str[j] == '-' || str[j] == '+')
        {
            buff = str[j];
            str[j] = str[0];
            str[0] = buff;
        }
        j++;
    }
}

void    ft_negdi(char *str)
{
    int j;
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == '-')
        {
            str[i] = str[i - 1];
        }
        i++;
    }
    j = 0;
    while (str[j] != '\0')
    {
        if(str[j] >= '0' && str[j] <= '9')
        {
            str[j - 1] = '-';
            break;
        }
        j++;
    }
}

int    ft_isneg(char *str)
{
    if (str[0] == '-')
        return (1);
    return (0);
}
