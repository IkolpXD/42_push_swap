/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/02/27 22:40:14 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	ft_rra(t_stack **a, int print)
{
	ft_rev_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **b, int print)
{
	ft_rev_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b, int print)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
