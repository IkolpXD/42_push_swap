/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                   	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/01/08 16:41:51 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*head;

	if (!stack || !stack->next)
		return (1);
	head = stack;
	while (stack->next != head)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_based_on_size(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size == 2)
		ft_sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_4_5(a, b);
	else
		sort_stacks(a, b);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = max_value(*a);
	if (biggest_node == *a)
		ft_ra(a, 1);
	else if ((*a)->next == biggest_node)
		ft_rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 1);
}

void	sort_4_5(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
		push_smaller_to_b(a, b);
	sort_three(a);
	while (*b)
		ft_pa(a, b, 1);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	ft_pb(b, a, 1);
	ft_pb(b, a, 1);
	while (ft_stack_size(*a) > 3 && !stack_is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_and_push(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	move_to_top(a, min_value(*a), 'a');
}
