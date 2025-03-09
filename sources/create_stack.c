/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/08 17:12:35 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stack_a(t_stack **a, char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (!append_to_stack(a, ft_atol(args[i])))
		{
			free_stack(a);
			*a = NULL;
			return ;
		}
		i++;
	}
}

int	append_to_stack(t_stack **a, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = ft_lst_new(n);
	if (!new_node)
		return (0);
	if (!(*a))
	{
		*a = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last_node = (*a)->prev;
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = *a;
		(*a)->prev = new_node;
	}
	return (1);
}

t_stack	*ft_lst_new(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_nodes_a(a, b);
	set_position_cost(a, ft_stack_size(a), ft_stack_size(b));
	set_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_nodes_b(a, b);
}
