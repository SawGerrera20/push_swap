/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:35 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/09 22:27:21 by pgaillar         ###   ########.fr       */
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
	if (!stack_a || !stack_b)
		return (0);
	if (argc == 2)
	{
		stack_a = add_single_arg(argc, argv, stack_a, stack_b);
		if (!stack_a)
			return (0);
		//first_sort(stack_a, stack_b);
		radix_sort(stack_a, stack_b);
		//print(stack_a);
		//push_b(stack_a, stack_b);
		//print(stack_a);
	}
	else if (argc > 2)
	{
		stack_a = add_arg(argc, argv, stack_a, stack_b);
		if (!stack_a)
			return (0);
		print(stack_a);
	}
	else if (argc < 2)
	{
		free(stack_a);
		free(stack_b);
		exit(1);
	}
	return (free_the_list(stack_a), free(stack_b), 0);
}
