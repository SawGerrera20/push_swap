/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:27:09 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/08 12:05:26 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->data > stack->top->next->data)
		swap_a(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->top->next->next->data < stack->top->next->data
		|| stack->top->next->next->data < stack->top->data)
	{
		if (stack->top->data > stack->top->next->data
			&& stack->top->data > stack->top->next->next->data)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
	if (stack->top->next->data < stack->top->data)
		swap_a(stack);
	/*if (!dernier 3)
	{
		if (premier 3)
			ra
		else
			rra
	}
	if (2 > 1 swap)*/
}

int	*get_index(char **temp, int len)
{
	int	i;
	int	*array;
	int	*sort_array;
	int	j;

	i = 0;
	j = 0;
	sort_array = malloc(sizeof(int) * len);
	array = malloc(sizeof(int) * len);
	if (!sort_array || !array)
		return (0);
	while (i < len)
	{
		sort_array[i] = ft_atoi(temp[j]);
		array[i] = ft_atoi(temp[j]);
		i++;
		j++;
	}
	sort_in_tab(sort_array, len);
	// i = 0;
	// while(i < len)
	// {
	// 	printf("sort_array : %d\n", sort_array[i]);
	// 	i++;
	// }
	give_index(array, sort_array, len);
	// i = 0;
	// while(i < len)
	// {
	// 	printf("array : %d\n", array[i]);
	// 	i++;
	// }
	free(sort_array);
	return (array);
}

void	sort_in_tab(int *array, int len)
{
	int	tmp;
	int	j;
	int	i;

	i = 0;
	while (i < len - 1)
	{
		j = i;
		while (j < len)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	give_index(int *array, int *sort_array, int len)
{
	int	j;
	int	size;
	int	i;

	j = 0;
	size = len;
	while (len > 0)
	{
		i = 0;
		while (j <= size)
		{
			
			if (sort_array[j] == array[i])
			{
				array[i] = j;
				j++;
				break ;
			}
			i++;
		}
		len--;
	}
}
