/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                 	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/01/09 16:41:51 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ft_ra(t_stack **a, int print)
{
	ft_rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **b, int print)
{
	ft_rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
