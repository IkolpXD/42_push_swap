/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:55:39 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/02 22:22:23 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_and_push(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*a);
	align_both_stacks(a, b, cheapest_node);
	align_stack(a, cheapest_node, 'a');
	align_stack(b, cheapest_node->target, 'b');
	ft_pb(b, a, 1);
	current_index(*a);
	current_index(*b);
}

void	align_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target
		&& !cheapest->is_below_median && !cheapest->target->is_below_median)
		ft_rr(a, b, 1);
	while (*a != cheapest && *b != cheapest->target
		&& cheapest->is_below_median && cheapest->target->is_below_median)
		ft_rrr(a, b, 1);
}

void	align_stack(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		if (node->is_below_median)
		{
			if (stack_name == 'a')
				ft_rra(stack, 1);
			else
				ft_rrb(stack, 1);
		}
		else
		{
			if (stack_name == 'a')
				ft_ra(stack, 1);
			else
				ft_rb(stack, 1);
		}
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		set_target_nodes_b(*a, *b);
		move_to_top(a, (*b)->target, 'a');
		ft_pa(a, b, 1);
	}
	move_to_top(a, min_value(*a), 'a');
	current_index(*a);
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*head;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	head = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
		if (stack == head)
			break ;
	}
	cheapest_node->is_cheapest = true;
}
