/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:15:30 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/02 21:01:14 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		median;
	t_stack	*head;

	if (!stack)
		return ;
	i = 0;
	head = stack;
	median = ft_stack_size(stack) / 2;
	while (1)
	{
		stack->index = i;
		stack->is_below_median = (i >= median);
		stack = stack->next;
		i++;
		if (stack == head)
			break ;
	}
}

t_stack	*find_cheapest_node(t_stack *a)
{
	t_stack	*current;
	t_stack	*cheapest;
	t_stack	*head;

	if (!a)
		return (NULL);
	current = a;
	head = a;
	cheapest = current;
	while (1)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current->is_cheapest = false;
		current = current->next;
		if (current == head)
			break ;
	}
	cheapest->is_cheapest = true;
	return (cheapest);
}

void	set_position_cost(t_stack *node, int size_a, int size_b)
{
	t_stack	*head;

	if (!node)
		return ;
	head = node;
	while (node)
	{
		if (!node->target)
			return ;
		node->push_cost = calculate_cost(node, size_a, size_b);
		node = node->next;
		if (node == head)
			break ;
	}
}

int	calculate_cost(t_stack *node, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;
	int	total_cost;

	if (node->is_below_median)
		cost_a = size_a - node->index;
	else
		cost_a = node->index;
	if (node->target->is_below_median)
		cost_b = size_b - node->target->index;
	else
		cost_b = node->target->index;
	if ((node->is_below_median == node->target->is_below_median))
	{
		if (cost_a > cost_b)
			total_cost = cost_a;
		else
			total_cost = cost_b;
	}
	else
		total_cost = cost_a + cost_b;
	return (total_cost);
}
