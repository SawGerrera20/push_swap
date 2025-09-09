/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:39:00 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/05 18:29:59 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_signs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (1);
		if (str[i] == '+' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (1);
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	check_max_min(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > 2147483647)
			return (1);
		if (ft_atoi(tab[i]) < -2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	already_sort(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if ((ft_atoi(tab[i]) < ft_atoi(tab[i + 1])) && tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_doubles(char **tab1, char **tab2)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (tab1[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(tab1[i]) == ft_atoi(tab2[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	error(t_stack *stack_a, t_stack *stack_b, char **tab, int *array)
{
	free_tab(tab);
	free(stack_a);
	free(stack_b);
	free(array);
	ft_putstr("Error\n");
	exit(1);
}

int	doubles_int_array(int *array, int len, int pose)
{
	int	i = 0;
	while(i <= len)
	{
		if(array[pose] == array[i])
			return(1);
		i++;
	}
	return(0);
}
