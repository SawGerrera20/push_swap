/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:49:44 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/17 15:34:16 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

t_stack	*add_arg(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		j;
	int		len;
	char	*str;
	char	**temp;
	int		*array;

	str = 0;
	j = 0;
	str = make_string_with_args(argc, argv);
	temp = ft_split(str, ' ');
	if (!str || !temp)
		return (NULL);
	len = word_count(str, ' ');
	array = get_index(temp, len);
	if (check_max_min(&temp[0]) || check_signs(str) || find_doubles(&temp[0], &temp[j])
		|| already_sort(&temp[0]))
	{
		free(str);
		error(stack_a, stack_b, temp, array);
	}
	feel_stack(stack_a, len, array);
	return (free(str), free_tab(temp), free(array), stack_a);
}

t_stack	*add_single_arg(int argc, char **argv, t_stack *stack_a,
		t_stack *stack_b)
{
	int		j;
	int		len;
	char	**temp;
	int		*array;

	(void)argc;
	j = 0;
	if (!argv[1][0])
		exit(1);
	temp = ft_split(argv[1], ' ');
	if (!temp)
		return (NULL);
	len = word_count(argv[1], ' ');
	array = get_index(temp, len);
	if (check_max_min(&temp[0]) || check_signs(argv[1]) || find_doubles(&temp[0], &temp[j])
		|| already_sort(&temp[0]))
		error(stack_a, stack_b, temp, array);
	feel_stack(stack_a, len, array);
	free_tab(temp);
	free(array);
	return (stack_a);
}

char	*make_string_with_args(int argc, char **argv)
{
	int		i;
	char	*str;
	int		len;

	len = count_args_len(argv, argc);
	i = 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	count_args_len(char **tab, int argc)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += count_number(ft_atoi(tab[i]));
		i++;
	}
	count += argc - 1;
	return (count);
}

void	feel_stack(t_stack *stack_a, int len, int *array)
{
	int	i;

	i = len - 1;
	add_to_empty(stack_a, array[i--]);
	while (i >= 0)
	{
		add_at_beg(stack_a, array[i]);
		i--;
	}
}
