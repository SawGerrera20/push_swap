/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaillar <pgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:10 by pgaillar          #+#    #+#             */
/*   Updated: 2025/09/17 14:54:21 by pgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

void				add_to_empty(t_stack *stack, int data);
void				add_at_beg(t_stack *tail, int data);
void				print(t_stack *tail);
long long			ft_atoi(char *str);
int					ft_isdigit(int c);
t_stack				*add_arg(int argc, char **argv, t_stack *stack_a,
						t_stack *stack_b);
char				**ft_split(char *s, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					ft_strlen(char *str);
int					find_doubles(char **tab1, char **tab2);
int					word_count(char *s, char c);
t_stack				*add_single_arg(int argc, char **argv, t_stack *stack_a,
						t_stack *b);
int					already_sort(char **tab1);
int					check_signs(char *str);
char				*make_string_with_args(int argc, char **argv);
int					check_max_min(char **tab);
int					count_number(int n);
int					count_args_len(char **tab, int argc);
void				free_tab(char **tab);
void				reverse_rotate_a(t_stack *stack_a);
void				reverse_rotate_b(t_stack *stack_b);
void				rotate_a(t_stack *stack_a);
void				rotate_b(t_stack *stack_b);
void				swap_a(t_stack *stack_a);
void				swap_b(t_stack *stack_b);
void				swap_swap(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate_rotate(t_stack *stack_a, t_stack *stack_b);
void				free_the_list(t_stack *stack);
void				error(t_stack *stack_a, t_stack *stack_b, char **tab,
						int *array);
t_node				*traverse(t_stack *stack);
void				rotate_rotate(t_stack *stack_a, t_stack *stack_b);
void				push_b(t_stack *stack_a, t_stack *stack_b);
void				push_a(t_stack *stack_a, t_stack *stack_b);
int					ft_lstsize(t_stack *stack);
void				sort_two(t_stack *stack);
void				sort_three(t_stack *stack);
int					*get_index(char **temp, int len);
void				feel_stack(t_stack *stack_a, int len, int *array);
void				sort_in_tab(int *array, int len);
void				give_index(int *array, int *sort_array, int len);
void				ft_putstr(char *str);
void				sort_stack_a(t_stack *stack_a, t_stack *stack_b, int start);
void				push_everything_in_a(t_stack *stack_a, t_stack *stack_b);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);
void				push_last(t_stack *stack_a, t_stack *stack_b);
int					sort_stack(t_stack *stack_a, t_stack *stack_b, int argc,
						char **argv);
void				choose_sort(t_stack *stack_a, t_stack *stack_b);
char				*ft_strjoin(char *s1, char *s2);

#endif