/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                  	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/01/08 16:41:51 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!*stack || !(*stack)->next || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	last = first->prev;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	last->next = second;
	*stack = second;
}

void	ft_sa(t_stack **a, int print)
{
	ft_swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **b, int print)
{
	ft_swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
