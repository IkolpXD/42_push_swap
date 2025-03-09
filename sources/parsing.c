/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:51:21 by made-jes          #+#    #+#             */
/*   Updated: 2025/03/08 16:57:48 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_args(int ac, char **av)
{
	if (ac == 2)
		return (ft_split(av[1], ' '));
	return (av + 1);
}

void	validate_args(int ac, char **args)
{
	int			i;
	long		n;

	i = 0;
	while (args[i])
	{
		n = ft_atol(args[i]);
		if (!is_num(args[i]) || (n < INT_MIN || n > INT_MAX)
			|| (av_duplicated(n, args, i)))
		{
			if (ac == 2)
				free_args(args);
			error_exit();
		}
		i++;
	}
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	av_duplicated(int num, char **av, int i)
{
	while (--i >= 0)
	{
		if (ft_atol(av[i]) == num)
			return (1);
	}
	return (0);
}
