/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:47:39 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/04 15:50:05 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	temp;
	int	temp2;

	temp = stack_a->top->data;
	temp2 = stack_a->top->next->data;
	stack_a->top->next->data = temp;
	stack_a->top->data = temp2;
	ft_putstr("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	int	temp;
	int	temp2;

	temp = stack_b->top->data;
	temp2 = stack_b->top->next->data;
	stack_b->top->next->data = temp;
	stack_b->top->data = temp2;
	ft_putstr("sb\n");
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr("ss\n");
}
