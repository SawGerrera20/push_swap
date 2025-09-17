/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:20:45 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/12 21:24:00 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	t_node	*tmp_b;
	t_node	*last;
	t_node	*last_b;
	int		len;

	len = ft_lstsize(stack_b);
	if (ft_lstsize(stack_a) == 1)
		return (push_last(stack_a, stack_b), ft_putstr("pa\n"));
	if (len > 1)
		last_b = traverse(stack_b);
	tmp_b = stack_b->top;
	tmp = stack_a->top->next;
	last = traverse(stack_a);
	stack_b->top = stack_a->top;
	stack_a->top = tmp;
	last->next = tmp;
	stack_b->top->next = tmp_b;
	if (len > 1)
		last_b->next = stack_b->top;
	else if (len == 0)
		stack_b->top->next = stack_b->top;
	else
		tmp_b->next = stack_b->top;
	ft_putstr("pb\n");
}

void	push_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*tmp;
	t_node	*tmp_b;
	t_node	*last;
	t_node	*last_b;
	int		len;

	len = ft_lstsize(stack_b);
	if (ft_lstsize(stack_a) == 1)
		return (push_last(stack_a, stack_b), ft_putstr("pa\n"));
	if (len > 1)
		last_b = traverse(stack_b);
	tmp_b = stack_b->top;
	tmp = stack_a->top->next;
	last = traverse(stack_a);
	stack_b->top = stack_a->top;
	stack_a->top = tmp;
	last->next = tmp;
	stack_b->top->next = tmp_b;
	if (len > 1)
		last_b->next = stack_b->top;
	else if (len == 0)
		stack_b->top->next = stack_b->top;
	else
		tmp_b->next = stack_b->top;
	ft_putstr("pa\n");
}

void	push_last(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_b;
	t_node	*last_b;

	last_b = traverse(stack_b);
	tmp_b = stack_b->top;
	stack_b->top = stack_a->top;
	stack_b->top->next = tmp_b;
	last_b->next = stack_b->top;
	stack_a->top = NULL;
}
