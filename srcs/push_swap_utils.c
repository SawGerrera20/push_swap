/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:30 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/16 16:13:35 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_empty(t_stack *stack, int data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
		return ;
	temp->data = data;
	temp->next = temp;
	stack->top = temp;
}

void	add_at_beg(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*last;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = stack->top;
	last = traverse(stack);
	last->next = new_node;
	stack->top = new_node;
}

t_node	*traverse(t_stack *stack)
{
	t_node	*ptr;

	ptr = stack->top->next;
	while (ptr->next != stack->top)
		ptr = ptr->next;
	return (ptr);
}

// void	print(t_stack *stack)
// {
// 	t_node	*ptr;

// 	if (stack->top == NULL)
// 	{
// 		return ;
// 	}
// 	ptr = stack->top;
// 	do
// 	{
// 		printf("%d\n", stack->top->data);
// 		stack->top = stack->top->next;
// 	} while (stack->top != ptr);
// }

void	free_the_list(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	temp = NULL;
	node = stack->top;
	while (node->next != stack->top)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(node);
	free(stack);
}

int	ft_lstsize(t_stack *stack)
{
	int		i;
	t_node	*temp;

	if (!stack->top)
		return (0);
	i = 0;
	temp = stack->top;
	temp = temp->next;
	i++;
	while (temp != stack->top)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
