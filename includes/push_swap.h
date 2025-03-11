/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:42:09 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/11 19:02:41 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int					value;
	int					index;
	bool				is_below_median;
	int					push_cost;
	bool				is_cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

//Handle errors and free stuff
char	**get_args(int ac, char **av);
void	validate_args(int ac, char **args);
int		is_num(char *str);
int		av_duplicated(int num, char **av, int i);
void	free_args(char **args);
void	free_stack(t_stack **stack);
void	error_exit(void);

//stack utils
void	create_stack_a(t_stack **a, char **args);
int		append_to_stack(t_stack **a, int n);
t_stack	*ft_lst_new(int n);
int		ft_stack_size(t_stack *stack);
t_stack	*max_value(t_stack *stack);
t_stack	*min_value(t_stack *stack);
void	push_smaller_to_b(t_stack **a, t_stack **b);
void	move_to_top(t_stack **stack, t_stack *node, char stack_name);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	set_target_nodes_a(t_stack *a, t_stack *b);
t_stack	*find_closest_smaller(t_stack *b, int value);
void	set_target_nodes_b(t_stack *a, t_stack *b);
t_stack	*find_closest_bigger(t_stack *a, int value);
t_stack	*find_cheapest_node(t_stack *a);
void	set_position_cost(t_stack *node, int size_a, int size_b);
int		calculate_cost(t_stack *node, int size_a, int size_b);
void	move_and_push(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	align_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest);
void	align_stack(t_stack **stack, t_stack *node, char stack_name);

//operations
t_stack	*detach_top(t_stack **src);
void	insert_top(t_stack **dest, t_stack *node);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **b, t_stack **a, int print);
void	ft_rev_rotate(t_stack **stack);
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_swap(t_stack **stack);
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);

//algorithm
int		stack_is_sorted(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_based_on_size(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
void	sort_4_5(t_stack **a, t_stack **b);

//checker - bonus
void	init_stack(t_stack **a, int ac, char **av);
void	check_operations(t_stack **a, t_stack **b, char *line);
void	exec_operations(t_stack **a, t_stack **b, char *line);

#endif