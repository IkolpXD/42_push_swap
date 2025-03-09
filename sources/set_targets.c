/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:22:21 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/07 21:11:26 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_nodes_a(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*best_match;
	t_stack	*head_a;

	if (!a || !b)
		return ;
	head_a = a;
	current_a = a;
	while (current_a)
	{
		best_match = find_closest_smaller(b, current_a->value);
		if (!best_match)
			best_match = max_value(b);
		current_a->target = best_match;
		current_a = current_a->next;
		if (current_a == head_a)
			break ;
	}
}

t_stack	*find_closest_smaller(t_stack *b, int value)
{
	t_stack	*best_match;
	t_stack	*current_b;
	t_stack	*head_b;

	if (!b)
		return (NULL);
	best_match = NULL;
	current_b = b;
	head_b = b;
	while (1)
	{
		if (current_b->value < value)
		{
			if (!best_match || current_b->value > best_match->value)
				best_match = current_b;
		}
		current_b = current_b->next;
		if (current_b == head_b)
			break ;
	}
	if (!best_match)
		best_match = max_value(b);
	return (best_match);
}

void	set_target_nodes_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*best_match;
	t_stack	*head_b;

	if (!a || !b)
		return ;
	head_b = b;
	current_b = b;
	while (current_b)
	{
		best_match = find_closest_bigger(a, current_b->value);
		if (!best_match)
			best_match = min_value(a);
		current_b->target = best_match;
		current_b = current_b->next;
		if (current_b == head_b)
			break ;
	}
}

t_stack	*find_closest_bigger(t_stack *a, int value)
{
	t_stack	*best_match;
	t_stack	*current;
	t_stack	*head_a;

	if (!a)
		return (NULL);
	best_match = NULL;
	head_a = a;
	current = a;
	while (1)
	{
		if (current->value > value)
		{
			if (!best_match || current->value < best_match->value)
				best_match = current;
		}
		current = current->next;
		if (current == head_a)
			break ;
	}
	if (!best_match)
		best_match = min_value(a);
	return (best_match);
}
