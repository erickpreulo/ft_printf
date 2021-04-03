/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:02:01 by egomes            #+#    #+#             */
/*   Updated: 2021/04/03 19:24:15 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
    ft_printf("meu c: c = |%c*| -5 = |%-10c| 5 = |%*c| *5 = | -%*c* -%-*c* |\n\n", '2', '0', 10, '1', -2, 0, 2, 0);
    printf("    c: c = |%c*| -5 = |%-10c| 5 = |%*c| *5 = | -%*c* -%-*c* |\n\n", '2', '0', 10, '1', -2, 0, 2, 0);
    ft_printf("meu s: s = |%s| -5 = |%-5s| 5 = |%5s| 15.10 = |%.1s|\n", "aqui", "aqui", "aqui", "aqui");
    printf("    s: s = |%s| -5 = |%-5s| 5 = |%5s| 15.10 = |%.1s|\n\n", "aqui", "aqui", "aqui", "aqui");
    ft_printf("meu d: d = |%d| 05 = |%05d| -5 = |%-5d| 5 = |%5d| 8.6 = |%.10d|\n", -42, -42, -42, -42, 142);
    printf("    d: d = |%d| 05 = |%05d| -5 = |%-5d| 5 = |%5d| 8.6 = |%.10d|\n\n", -42, -42, -42, -42, 142);
    ft_printf("meu i: i = |%i| 05 = |%05i| -5 = |%-5i| 5 = |%5i| 8.6 = |%8.6i|\n", -42, -42, -42, -42, 42);
    printf("    i: i = |%i| 05 = |%05i| -5 = |%-5i| 5 = |%5i| 8.6 = |%8.6i|\n\n", -42, -42, -42, -42, 42);
    ft_printf("meu u: u = |%u| 05 = |%05u| -5 = |%-5u| 5 = |%5u| 8.6 = |%8.6u|\n", 42, 42, 42, 42, 42);
    printf("    u: u = |%u| 05 = |%05u| -5 = |%-5u| 5 = |%5u| 8.6 = |%8.6u|\n\n", 42, 42, 42, 42, 42);
    ft_printf("meu x: x = |%x| 05 = |%05x| -5 = |%-5x| 5 = |%5x| 20.10 = |%20.10x|\n", -42, -42, -42, -42, 42);
    printf("    x: x = |%x| 05 = |%05x| -5 = |%-5x| 5 = |%5x| 20.10 = |%20.10x|\n\n", -42, -42, -42, -42, 42);
    ft_printf("meu X: X = |%X| 05 = |%05X| -5 = |%-5X| 5 = |%5X| 20.10 = |%-10.0X|\n", 42, 42, 42, 42, -142);
    printf("    X: X = |%X| 05 = |%05X| -5 = |%-5X| 5 = |%5X| 20.10 = |%-10.0X|\n\n", 42, 42, 42, 42, -142);
    ft_printf("meu p: p = |%p| -5 = |%-5p| 5 = |%5p|\n", (void *)42, (void *)42, (void *)42);
    printf("    p: p = |%p| -5 = |%-5p| 5 = |%5p|\n\n", (void *)42, (void *)42, (void *)42);
}