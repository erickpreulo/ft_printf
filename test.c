/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:02:01 by egomes            #+#    #+#             */
/*   Updated: 2021/03/26 13:25:19 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
    ft_printf("meu teste:\nc: %c \ns: %s\nd: %d\n\n", 'e', "aqui", 42);
	printf("teste original:\nc: %c \ns: %s\nd: %d\n", 'e', "aqui", 42);
}