/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:20:45 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/09 22:30:31 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		*array;
	t_node	*temp;
	t_stack	*temp_stack;

	i = 0;
	temp = stack_a->top;
	temp = temp->next;
	array = malloc(sizeof(ft_lstsize(stack_a)));
	if (!array)
		return ;
	while (temp != stack_a->top)
	{
		array[i++] = temp->data;
		temp = temp->next;
	}
	temp_stack = malloc(sizeof(t_stack));
	if (!temp_stack)
		return ;
	bzero(temp_stack, sizeof(t_stack));
	add_to_empty(temp_stack, array[ft_lstsize(stack_a) - 2]);
	feel_stack_b(stack_a, stack_b, array, temp_stack);
	stack_a->top = temp_stack->top;
	free(temp_stack);
	free(array);
	ft_putstr("pb\n");
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		*array;
	t_node	*temp;
	t_stack	*temp_stack;

	i = 0;
	temp = stack_b->top;
	temp = temp->next;
	array = malloc(sizeof(ft_lstsize(stack_b)));
	if (!array)
		return ;
	while (temp != stack_b->top)
	{
		array[i++] = temp->data;
		temp = temp->next;
	}
	temp_stack = malloc(sizeof(t_stack));
	if (!temp_stack)
		return ;
	bzero(temp_stack, sizeof(t_stack));	
	add_to_empty(temp_stack, array[ft_lstsize(stack_b) - 2]);
	feel_stack_b(stack_b, stack_a, array, temp_stack);
	stack_b->top = temp_stack->top;
	free(temp_stack);
	free(array);
	ft_putstr("pa\n");
}

void	feel_stack_b(t_stack *stack_a, t_stack *stack_b, int *array,
		t_stack *temp_stack)
{
	int	len;

	len = ft_lstsize(stack_a) - 3;
	while (len >= 0)
		add_at_beg(temp_stack, array[len--]);
	if (!stack_b->top)
		add_to_empty(stack_b, stack_a->top->data);
	else
		add_at_beg(stack_b, stack_a->top->data);
}
