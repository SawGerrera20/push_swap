/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:35 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/16 16:13:27 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	j = 1;
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	if (!stack_a || !stack_b)
		return (0);
	sort_stack(stack_a, stack_b, argc, argv);
	return (free_the_list(stack_a), free(stack_b), 0);
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	if (argc == 2)
	{
		stack_a = add_single_arg(argc, argv, stack_a, stack_b);
		if (!stack_a)
			return (0);
		choose_sort(stack_a, stack_b);
	}
	else if (argc > 2)
	{
		stack_a = add_arg(argc, argv, stack_a, stack_b);
		if (!stack_a)
			return (0);
		choose_sort(stack_a, stack_b);
	}
	else if (argc < 2)
	{
		free(stack_a);
		free(stack_b);
		exit(1);
	}
	return (0);
}

void	choose_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a) == 2)
		sort_two(stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(stack_a);
	else
		radix_sort(stack_a, stack_b);
}
