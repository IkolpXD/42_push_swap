/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/02/28 19:26:52 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		i;
	t_stack	*head;

	i = 0;
	if (!stack)
		return (0);
	head = stack;
	while (1)
	{
		i++;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (i);
}

t_stack	*max_value(t_stack *stack)
{
	int		max;
	t_stack	*max_node;
	t_stack	*head;

	if (!stack)
		return (NULL);
	max = stack->value;
	max_node = stack;
	head = stack ;
	stack = stack->next;
	while (stack != head)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*min_value(t_stack *stack)
{
	int		min;
	t_stack	*min_node;
	t_stack	*head;

	if (!stack)
		return (NULL);
	min = stack->value;
	min_node = stack;
	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	move_to_top(t_stack **stack, t_stack *node, char stack_name)
{
	t_stack	*head;

	if (!stack || !*stack || !node)
		return ;
	head = *stack;
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
			if (stack_name == 'b')
				ft_ra(stack, 1);
			else
				ft_rra(stack, 1);
		}
		if (*stack == head)
			break ;
	}
}
