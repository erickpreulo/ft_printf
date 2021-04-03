/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:54:28 by egomes            #+#    #+#             */
/*   Updated: 2021/04/03 15:54:28 by egomes           ###   ########.fr       */
/*                                                                            */

# include "ft_printf.h"
# include <stdio.h>

int main()
{
    int i = printf("[ORIG] | -%-*c* -%-*c* | ", 2, 0, -2, 0);
    printf("RES = %d \n\n", i);
    int i2 = ft_printf("[MEU ] | -%-*c* -%-*c* | ", 2, 0, -2, 0);
    ft_printf("RES = %d \n\n", i2 );
}
