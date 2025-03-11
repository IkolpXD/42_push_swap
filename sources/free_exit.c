/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:41:32 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/11 19:04:23 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		if (*stack == head)
			break ;
	}
	*stack = NULL;
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	push_smaller_to_b(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = min_value(*a);
	move_to_top(a, smallest, 'a');
	ft_pb(b, a, 1);
}
