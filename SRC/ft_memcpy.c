/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:44:03 by egomes            #+#    #+#             */
/*   Updated: 2021/04/26 11:07:44 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		((unsigned char *)dst)[start] = ((unsigned char *)src)[i];
		start++;
		i++;
	}
	return (dst);
}

void	*ft_memcpyneg(void *dst, const void *src, int end)
{
	int		i;
	int		j;

	((unsigned char *)dst)[0] = '-';
	i = 1;
	j = 0;
	while (i <= end)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[j];
		i++;
		j++;
	}
	return (dst);
}

void	*ft_memcpynegstay(void *dst, const void *src, int end)
{
	int		j;

	j = 0;
	while (j <= end)
	{
		((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
		j++;
	}
	((unsigned char *)dst)[0] = '-';
	return (dst);
}
