/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:44:03 by egomes            #+#    #+#             */
/*   Updated: 2021/04/01 16:12:34 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t start, size_t end)
{
	size_t i;

	i = 0;
	while (i < end)
	{
		((unsigned char*)dst)[start] = ((unsigned char*)src)[i];
		start++;
		i++;
	}
	((unsigned char*)dst)[start] = '\0';
	return (dst);;
}
