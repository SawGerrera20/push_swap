/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:40:09 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/04 15:49:53 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	stack_a->top = stack_a->top->next;
	ft_putstr("ra\n");
}

void	rotate_b(t_stack *stack_b)
{
	stack_b->top = stack_b->top->next;
	ft_putstr("rb\n");
}

void	rotate_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr("rr\n");
}
