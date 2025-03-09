/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:01:37 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/04 16:33:26 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_stack(&a, ac, av);
	line = get_next_line(0);
	if (!line && !stack_is_sorted(a))
		ft_putstr_fd("KO\n", 1);
	else if (!line && stack_is_sorted(a))
		ft_putstr_fd("OK\n", 1);
	else
		check_operations(&a, &b, line);
	free_stack(&b);
	free_stack(&a);
	return (0);
}

void	init_stack(t_stack **a, int ac, char **av)
{
	char	**args;

	args = get_args(ac, av);
	if (!args)
		exit(1);
	validate_args(args);
	create_stack_a(a, args);
	if (ac == 2)
		free_args(args);
	if (!*a)
	{
		free_stack(a);
		error_exit();
	}
}

void	check_operations(t_stack **a, t_stack **b, char *line)
{
	char	*temp;

	while (line)
	{
		if (*line == '\n' || *line == '\0')
		{
			free(line);
			break ;
		}
		exec_operations(a, b, line);
		temp = line;
		line = get_next_line(0);
		free(temp);
	}
	if (*b || !stack_is_sorted(*a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}

void	exec_operations(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		ft_sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		ft_sb(b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ft_ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		ft_pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		ft_pb(b, a, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ft_ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		ft_rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		ft_rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		ft_rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		ft_rrr(a, b, 0);
	else
		error_exit();
}
