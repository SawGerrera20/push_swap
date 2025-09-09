/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:30 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/04 15:50:19 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack_a)
{
	t_node	*temp;

	temp = traverse(stack_a);
	stack_a->top = temp;
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack *stack_b)
{
	t_node	*temp;

	temp = traverse(stack_b);
	stack_b->top = temp;
	ft_putstr("rrb\n");
}

void	reverse_rotate_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putstr("rrr\n");
}
