/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:48:25 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/08 16:37:03 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	start;
	int	len;

	start = 0;
	len = ft_lstsize(stack_a);
	while (start < (len / 2))
	{
		sort_stack_a(stack_a, stack_b, start);
		push_everything_in_a(stack_a, stack_b);
		start++;
	}
	printf("new_a :\n");
	print(stack_a);
	printf("new_b :\n");
	print(stack_b);
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, int start)
{
	int	i;
	int	len;

	len = ft_lstsize(stack_a);
	i = 0;
	while (i < len)
	{
		if (stack_a->top->data >> start & 1)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
		stack_a->top = stack_a->top->next;
		i++;
	}
}

void	push_everything_in_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int len = ft_lstsize(stack_b);

	i = 0;
	while (i <= len - 1)
	{
		push_a(stack_a, stack_b);
		i++;
	}
}