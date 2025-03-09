/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/02 22:23:47 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*detach_top(t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return (NULL);
	temp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = temp->prev;
		temp->prev->next = *src;
	}
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}

void	insert_top(t_stack **dest, t_stack *node)
{
	if (!node)
		return ;
	if (!*dest)
	{
		*dest = node;
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
	}
	else
	{
		node->next = *dest;
		node->prev = (*dest)->prev;
		(*dest)->prev->next = node;
		(*dest)->prev = node;
		*dest = node;
	}
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = detach_top(src);
	insert_top(dest, temp);
	if (!*src)
		*src = NULL;
	current_index(*dest);
	current_index(*src);
}

void	ft_pa(t_stack **a, t_stack **b, int print)
{
	ft_push(a, b);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **b, t_stack **a, int print)
{
	ft_push(b, a);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
