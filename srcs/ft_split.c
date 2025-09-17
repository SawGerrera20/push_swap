/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:36:31 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/17 14:10:22 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			word_count(char *s, char c);

static void	ft_free(char **result, int count);

static char	*fill_word(char *s, char c, int *i);

char	**ft_split(char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = fill_word(s, c, &i);
			if (!result[j])
				return ((ft_free(result, j), NULL));
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

int	word_count(char *s, char c)
{
	int		j;
	size_t	count;

	j = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && j != 1)
		{
			j = 1;
			count++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (count);
}

static char	*fill_word(char *s, char c, int *i)
{
	size_t	start;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
	}
	return (ft_substr(s, start, *i - start));
}

static void	ft_free(char **result, int j)
{
	while (j--)
		free(result[j]);
	free(result);
}
