/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:40:23 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/16 17:02:41 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (res > INT_MAX)
			return (LONG_MAX);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;
	size_t	dest_len;

	s_len = ft_strlen(s);
	dest_len = 0;
	while (start + dest_len < s_len && dest_len < len)
	{
		dest_len++;
	}
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * (dest_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
