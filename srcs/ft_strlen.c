/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:18:38 by egomes            #+#    #+#             */
/*   Updated: 2021/05/12 16:23:28 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_nrb(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'
		|| str[i] == '.' || str[i] == '*')
		i++;
	return (i);
}

int	ft_strlen_find_dot(const char *str)
{
	int		i;

	i = 0;
	while (i <= (ft_strlen_nrb(str)))
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strlen_bfdot(const char *str)
{
	char	*buff;

	if (str[0] == '0' && str[1] == '-')
	{
		buff = ft_newstr(ft_atoi(&str[2]));
		ft_memset(buff, ' ', ft_atoi(&str[2]));
	}
	else
	{
		buff = ft_newstr(ft_atoi(str));
		ft_memset(buff, ' ', ft_atoi(str));
	}
	return (buff);
}

char	*ft_strlen_afdot(const char *str, char *s)
{
	char	*buff;
	int		i;

	i = 0;
	while (i <= (ft_strlen_nrb(str)))
	{
		if (str[i] == '.')
		{
			i++;
			if (s[0] == '-')
			{
				buff = ft_newstr(ft_atoi(&str[i]) + 1);
				ft_memset(buff, '0', (ft_atoi(&str[i]) + 1));
			}	
			else
			{				
				buff = ft_newstr(ft_atoi(&str[i]));
				ft_memset(buff, '0', (ft_atoi(&str[i])));
			}	
		}
		i++;
	}
	return (buff);
}